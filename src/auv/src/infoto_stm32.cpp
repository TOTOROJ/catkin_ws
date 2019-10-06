#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"


class Info_to_stm32
{
public:
	Info_to_stm32()
	{
		ManualMode = 1;
		pub_ = n_.advertise<std_msgs::String>("serial_stm32_sub", 100);//serial send
		sub_ = n_.subscribe("serial_digitaltrans_pub", 100, &Info_to_stm32::DTCallback,this);//serial receive
		subgpsinfo_ = n_.subscribe("gps_to_stm32", 100, &Info_to_stm32::gpsinfoCallback,this);;//gps info to stm32
		subauto_ = n_.subscribe("autocontrol", 100, &Info_to_stm32::autoCallback,this);;//auto control
	}

	void gpsinfoCallback(const std_msgs::String::ConstPtr &msg)
	{
		pub_.publish(msg);
	}
	void DTCallback(const std_msgs::String::ConstPtr &msg)
	{
		if(msg->data == "#MANUALON")
		{
			ManualMode=1;
			ROS_INFO("MANUAL ON");
		}
		if(msg->data == "#MANUALOFF")
		{
			ManualMode=0;
			ROS_INFO("MANUAL OFF");
		}
		if(ManualMode == 1)
		{
			pub_.publish(msg);
		}		
	}
	void autoCallback(const std_msgs::String::ConstPtr &msg)
	{
		if (ManualMode == 0)
		{
			pub_.publish(msg);
		}
		
	}
private:
	ros::NodeHandle n_;
	ros::Publisher pub_;
	ros::Subscriber sub_;
	ros::Subscriber subgpsinfo_;
	ros::Subscriber subauto_;
	int ManualMode;
};


int main(int argc, char *argv[])
{

	ros::init(argc, argv, "info_to_stm32");
	Info_to_stm32 s;
	ros::spin();	
	return 0;
}