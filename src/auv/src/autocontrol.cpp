#include "auv/usv_control.h"
#include "sensor_msgs/NavSatFix.h"


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "autocontrol");
    AutoControl a;
    ros::spin();
    return 0;
}