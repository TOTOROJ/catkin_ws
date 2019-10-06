#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cmath>
#include "auv/jiexi_GPS.h"
#include "auv/add_comma.h"
#include "auv/add_semi.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/NavSatFix.h"


#define buffLen 1024
#define rcvTimeOut 1000
#define PORT 8986

using namespace std;

/*************Linux and Serial Port *********************/
int openPort(int fd, int comport)
{

	if (comport == 1)
	{
		fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return (-1);
		}
		else
		{
			printf("open ttyS0 .....\n");
		}
	}
	else if (comport == 2)
	{
		fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return (-1);
		}
		else
		{
			printf("open ttyS1 .....\n");
		}
	}
	else if (comport == 3)
	{
		fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY | O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return (-1);
		}
		else
		{
			printf("open ttyS2 .....\n");
		}
	}
	/*************************************************/
	else if (comport == 4)
	{
		fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return (-1);
		}
		else
		{
			printf("open ttyUSB0 .....\n");
		}
	}

	if (fcntl(fd, F_SETFL, 0) < 0)
	{
		printf("fcntl failed!\n");
	}
	else
	{
		printf("fcntl=%d\n", fcntl(fd, F_SETFL, 0));
	}
	if (isatty(STDIN_FILENO) == 0)
	{
		printf("standard input is not a terminal device\n");
	}
	else
	{
		printf("is a tty success!\n");
	}
	printf("fd-open=%d\n", fd);
	return fd;
}

int setOpt(int fd, int nSpeed, int nBits, char nEvent, int nStop)
{
	struct termios newtio, oldtio;
	if (tcgetattr(fd, &oldtio) != 0)
	{
		perror("SetupSerial 1");
		return -1;
	}
	bzero(&newtio, sizeof(newtio));
	newtio.c_cflag |= CLOCAL | CREAD;
	newtio.c_cflag &= ~CSIZE;

	switch (nBits) //数据位
	{
	case 7:
		newtio.c_cflag |= CS7;
		break;
	case 8:
		newtio.c_cflag |= CS8;
		break;
	}

	switch (nEvent) //奇偶校验
	{
	case 'O': //奇校验
		newtio.c_cflag |= PARENB;
		newtio.c_cflag |= PARODD;
		newtio.c_iflag |= (INPCK | ISTRIP);
		break;
	case 'E': //偶校验
		newtio.c_iflag |= (INPCK | ISTRIP);
		newtio.c_cflag |= PARENB;
		newtio.c_cflag &= ~PARODD;
		break;
	case 'N': //无校验
		newtio.c_cflag &= ~PARENB;
		break;
	}

	switch (nSpeed) //波特率
	{
	case 2400:
		cfsetispeed(&newtio, B2400);
		cfsetospeed(&newtio, B2400);
		break;
	case 4800:
		cfsetispeed(&newtio, B4800);
		cfsetospeed(&newtio, B4800);
		break;
	case 9600:
		cfsetispeed(&newtio, B9600);
		cfsetospeed(&newtio, B9600);
		break;
	case 115200:
		cfsetispeed(&newtio, B115200);
		cfsetospeed(&newtio, B115200);
		break;
	case 57600:
		cfsetispeed(&newtio, B57600);
		cfsetospeed(&newtio, B57600);
		break;
	default:
		cfsetispeed(&newtio, B9600);
		cfsetospeed(&newtio, B9600);
		break;
	}
	if (nStop == 1) //停止位
	{
		newtio.c_cflag &= ~CSTOPB;
	}
	else if (nStop == 2)
	{
		newtio.c_cflag |= CSTOPB;
	}
	newtio.c_cc[VTIME] = 0;
	newtio.c_cc[VMIN] = 0;
	tcflush(fd, TCIFLUSH);
	if ((tcsetattr(fd, TCSANOW, &newtio)) != 0)
	{
		perror("com set error");
		return -1;
	}
	printf("set done!\n");
	return 0;
}

int readDataTty(int fd, char *rcv_buf, int TimeOut, int Len)
{
	int retval;
	fd_set rfds;
	struct timeval tv;
	int ret, pos;
	tv.tv_sec = TimeOut / 1000;			//set the rcv wait time
	tv.tv_usec = TimeOut % 1000 * 1000; //100000us = 0.1s
	int flag = 0;
	pos = 0;
	while (1)
	{
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);
		retval = select(fd + 1, &rfds, NULL, NULL, &tv);
		if (retval == -1)
		{
			perror("select()");
			break;
		}
		else if (retval)
		{
			ret = read(fd, rcv_buf + pos, 1);
			if (-1 == ret)
			{
				break;
			}
			if (rcv_buf[pos] == '#')
			{
				flag = 1;
			}
			// if(flag == 1)
			pos++;
			if (Len <= pos)
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	return pos;
}

int sendDataTty(int fd, char *send_buf, int Len)
{
	ssize_t ret;

	ret = write(fd, send_buf, Len);
	if (ret == -1)
	{
		printf("write device error\n");
		return -1;
	}

	return 1;
}

int main(int argc, char **argv)
{

	ros::init(argc, argv, "serial_stm32");
	ros::NodeHandle n;
	ros::Publisher gps_to_stm32 = n.advertise<std_msgs::String>("gps_to_stm32", 1);
	ros::Publisher lonlat = n.advertise<sensor_msgs::NavSatFix>("lonlat", 1);
	ros::Publisher radar_v = n.advertise<std_msgs::Float64>("radar_v", 1);
	ros::Publisher radar_dir = n.advertise<std_msgs::Float64>("radar_dir", 1);
	int iSetOpt = 0; //SetOpt 的增量i

	int fdSerial = 0;

	//openPort
	if ((fdSerial = openPort(fdSerial, 4)) < 0) 
	{
		perror("open_port error");
		return -1;
	}
	if ((iSetOpt = setOpt(fdSerial, 57600, 8, 'N', 1)) < 0)
	{
		perror("set_opt error");
		return -1;
	}
	printf("Serial fdSerial=%d\n", fdSerial);
	tcflush(fdSerial, TCIOFLUSH); //清掉串口缓存
	fcntl(fdSerial, F_SETFL, 0);

	char buffRcvData[buffLen] = {0};
	unsigned int readDataNum = 0;
	char s[308];  //单次接收到的rtk的消息
	char s1[14];  //纬度
	char s2[15];  //经度
	char s3[10];  //高度
	char s4[10];  //起伏
	char s5[8];   //北向速度
	char s6[8];   //东向速度
	char s7[8];   //天向速度
	char s8[14];  //roll角
	char s9[14];  //俯仰角
	char s10[14]; //航向角

	int num = 11; //维度子字符串对应的逗号次序

	while (1)
	{
		readDataNum = readDataTty(fdSerial, buffRcvData, 2000, 308);
		for (int m = 0; m < readDataNum; m++)
		{
			s[m] = buffRcvData[m];
			//printf("%c", buffRcvData[m]);
		}

		GPS h;
		h.get_ss(s);
		//ASCII子字符串
		h.gps(s1, num, 14, 3);
		printf("%s\n",s1);

		h.gps(s2, num + 1, 15, 4);

		h.gps(s3, num + 2, 10, 5);
		h.gps(s4, num + 3, 10, 5);
		h.gps(s5, num + 4, 8, 3);

		h.gps(s6, num + 5, 8, 3);

		h.gps(s7, num + 6, 8, 3);
		h.gps(s8, num + 7, 14, 4);
		h.gps(s9, num + 8, 14, 4);
		h.gps(s10, num + 9, 14, 4);

		//完成字符串拼接，通过串口发送给下位机
		char *s11 = add_comma(s1); //纬度字符串加逗号
		char *s22 = add_comma(s2);
		char *s55 = add_comma(s5);
		char *s66 = add_comma(s6);
		char *s1010 = add_semi(s10); //航向字符串加分号，\n,\r
		char s0[150] = "#IMU";//s0 -- attch string

		strcat(s0, s11);
		strcat(s0, s22);
		strcat(s0, s55);
		strcat(s0, s66);
		strcat(s0, s1010);
		//sendDataTty(fdSerial, s0, 300);

		//double，通过ros publish
		double lat = atof(s1);
		double lon = atof(s2);
		double dir = atof(s10);
		double vel_north = atof(s5);
		double vel_east = atof(s6);
		double v = sqrt(pow(vel_north, 2)+pow(vel_east, 2));

		std_msgs::Float64 radar_v_data;
		std_msgs::Float64 radar_dir_data;
		std_msgs::String gpsinfo_stm32;
		sensor_msgs::NavSatFix gps_lidar;

		radar_dir_data.data = dir;
		radar_v_data.data = v;
		gpsinfo_stm32.data = s0;
		gps_lidar.longitude = lon;
		gps_lidar.latitude = lat;


		radar_dir.publish(radar_dir_data);
		radar_v.publish(radar_v_data);
		lonlat.publish(gps_lidar);
		gps_to_stm32.publish(gpsinfo_stm32);

		ros::spinOnce();

	}

	return 0;
}
