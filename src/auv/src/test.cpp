#include "auv/mytest.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "stdio.h"
#include "sensor_msgs/NavSatFix.h"
#include "std_msgs/Float64.h"
#include "string.h"
#include "sstream"

void chatter_callback(const std_msgs::String::ConstPtr &msg)
{
    DispData(msg->data);
}


int main(int argc, char *argv[])
{

	ros::init(argc, argv, "test");
	ros::NodeHandle n;
	ros::Subscriber chatter_sub = n.subscribe<std_msgs::String>("serial_digitaltrans_pub",100,chatter_callback);
		
	ros::spin();
	return 0;
}