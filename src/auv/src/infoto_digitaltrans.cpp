#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include "sensor_msgs/NavSatFix.h"
#include "std_msgs/Float64.h"
#include "string.h"
#include "sstream"



class Info_to_digitaltrans
{
public:

	Info_to_digitaltrans()
	{
		memset(str,0,sizeof(str));
		timer = n_.createTimer(ros::Duration(2),&Info_to_digitaltrans::timer_Callback,this);
		pub_ = n_.advertise<std_msgs::String>("serial_digitaltrans_sub", 1);//serial send
		subgps_ = n_.subscribe("lonlat", 1, &Info_to_digitaltrans::lonlatCallback,this);//gps
		subv_ = n_.subscribe("radar_v", 1, &Info_to_digitaltrans::vCallback,this);//v
		subdir_ = n_.subscribe("radar_dir", 1, &Info_to_digitaltrans::dirCallback,this);//direction
		
	}

	void SynLonLatVDir(char*,double,double,double,double);

	void timer_Callback(const ros::TimerEvent& event)
	{
		SynLonLatVDir(str,lon,lat,v,dir);
		ss.clear();
		ss << "#AUVINFO" << str << "\r\n";
		msg.data = ss.str();
		pub_.publish(msg);
		memset(str,0,sizeof(str));

	}

	void lonlatCallback(const sensor_msgs::NavSatFix::ConstPtr &msg)
	{
		lon = msg->longitude;
		lat = msg->latitude;
	}

	void vCallback(const std_msgs::Float64::ConstPtr &msg)
	{
		v = msg->data;
	}

	void dirCallback(const std_msgs::Float64::ConstPtr &msg)
	{
		dir = msg->data;
	}

private:
	ros::NodeHandle n_;
	ros::Publisher pub_;
	ros::Subscriber subgps_;
	ros::Subscriber subv_;
	ros::Subscriber subdir_;
	ros::Timer timer;
	double lon;
	double lat;
	double v;
	double dir;
	char str[100];
	std_msgs::String msg;
	std::stringstream ss;

};


int main(int argc, char *argv[])
{

	ros::init(argc, argv, "info_to_DT");
	Info_to_digitaltrans s;
	ros::spin();	
	return 0;
}

void Info_to_digitaltrans::SynLonLatVDir(char* str,double lon, double lat,double v,double dir)
{

    char sgn = 0;

    if(lon>0)
    {

    }
    else
    {
        lon = -lon;
        sgn |= 0x80;
    }
    if(lat>0)
    {

    }
    else
    {
        lat = -lat;
        sgn |= 0x40;
    }
	if(v>0)
	{

	}
	else
	{
		v = -v;
		sgn |= 0x20;
	}
    if(dir>0)
    {

    }
    else
    {
        dir = -dir;
        sgn |= 0x10;
    }

    unsigned char lon_int = (unsigned char)lon;
    unsigned int lon_dec = (unsigned int)((lon - lon_int)*1e7);
    unsigned char lat_int = (unsigned char)lat;
    unsigned int lat_dec = (unsigned int)((lat - lat_int)*1e7);
	unsigned char v_int = (unsigned char)v;
	unsigned int v_dec = (unsigned int)((v - v_int)*1e2);
    unsigned char dir_int = (unsigned char)dir;
    unsigned int dir_dec = (unsigned int)((dir - dir_int)*1e7);

    str[0] = sgn;
    *(int*)(&str[1]) = lon_int;
    *(int*)(&str[2]) = lon_dec;
    *(int*)(&str[6]) = lat_int;
    *(int*)(&str[7]) = lat_dec;

    *(int*)(&str[11]) = v_int;
    *(int*)(&str[12]) = v_dec;
	*(int*)(&str[13]) = dir_int;
	*(int*)(&str[14]) = dir_dec;
}