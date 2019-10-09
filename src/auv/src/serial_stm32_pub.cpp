#include "ros/ros.h"
#include "std_msgs/String.h"
#include "serial/serial.h"

serial::Serial sp;// serial handle

void stm32_callback(const std_msgs::String::ConstPtr& msg)
{
	sp.write(msg->data);
	// ROS_INFO("1");
	// ROS_INFO("%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{

	ros::init(argc, argv, "serial_stm32");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("serial_stm32_pub", 100);
	ros::Subscriber chatter_sub = n.subscribe<std_msgs::String>("serial_stm32_sub",100,stm32_callback);
	ros::Rate loop_rate(10);


	serial::Timeout to = serial::Timeout::simpleTimeout(1000);
	sp.setPort("/dev/ttyUSB0");
	sp.setBaudrate(9600);
	sp.setTimeout(to);
	try
	{
		sp.open();
	}
	catch (serial::IOException e)
	{
		ROS_ERROR("Unable to open port.");
	}

	if (sp.isOpen())
	{
		ROS_INFO("serial_stm32 is opened.");
	}
	else
	{
		return -1;
	}
	
		

	while (ros::ok())
	{	
		// ROS_INFO("1");		
		std_msgs::String buf;
		buf.data = sp.readline(65536,"\r\n");

		// ROS_INFO_STREAM(buf.data);

		chatter_pub.publish(buf);
		ros::spinOnce();
		loop_rate.sleep();
	}

	sp.close();
	return 0;
}