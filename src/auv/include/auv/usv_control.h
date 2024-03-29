#ifndef _UAV_CONTROL_H
#define _UAV_CONTROL_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"
#include "string"

enum NaviMode{ManualMode=200,AutoMode,LowSpeedMode,StableMode,ThrusterPower,AvoidMode,CircleMode};

class AutoControl
{


private:
    std::stringstream ss;
    ros::NodeHandle n;
    ros::Publisher pub_;
    ros::Subscriber sub_;
public:
    AutoControl()
    {
        // sub_ = n_.subscribe("topic", 100, &AutoControl::Callback,this);
        pub_ = n.advertise<std_msgs::String>("autocontrol", 100);
    }

void ChangeMode(NaviMode mode)
{
    std_msgs::String msg;
    switch (mode)
    {
        case ManualMode:
            msg.data = "#MOD01";
            pub_.publish(msg);
            break;
        case AutoMode:
            msg.data = "#MOD02";
            pub_.publish(msg);
            break;   
        case LowSpeedMode:
            msg.data = "#MOD03";
            pub_.publish(msg);
            break;    
        case StableMode:
            msg.data = "#MOD04";
            pub_.publish(msg);
            break;    
        case ThrusterPower:
            msg.data = "#MOD05";
            pub_.publish(msg);
            break; 
        case AvoidMode:
            msg.data = "#MOD06";
            pub_.publish(msg);
            break;
        case CircleMode:
            msg.data = "#MOD07";
            pub_.publish(msg);
            break;
        default:
            ;
    }
    
}

void ModeStop(NaviMode mode)
{
    std_msgs::String msg;
    switch (mode)
    {
        case ManualMode:


            break;
        case AutoMode:
            msg.data = "#RPGSTOP";
            pub_.publish(msg);
            break;   
        case LowSpeedMode:
            msg.data = "#LPGSTOP";
            pub_.publish(msg);
            break;    
        case StableMode:
            msg.data = "#SPGSTOP";
            pub_.publish(msg);
            break;    
        case ThrusterPower:

            break;    
        case AvoidMode:

            break;  
        case CircleMode:

            break;       
        default:
            ;
    }    
}

void ModeStart(NaviMode mode)
{
    std_msgs::String msg;
    switch (mode)
    {
        case ManualMode:


            break;
        case AutoMode:
            msg.data = "#RPGSTART";
            pub_.publish(msg);
            break;   
        case LowSpeedMode:
            msg.data = "#LPGSTART";
            pub_.publish(msg);
            break;    
        case StableMode:
            msg.data = "#SPGSTART";
            pub_.publish(msg);
            break;    
        case ThrusterPower:

            break;  
        case AvoidMode:

            break;  
        case CircleMode:

            break;  
                               
        default:
            ;
    }    
}

void SendAutoMode(double lon,double lat)
{
    std_msgs::String msg;
    ss.clear();
    char str[100]={0};
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

    unsigned char lon_int = (unsigned char)lon;
    unsigned int lon_dec = (unsigned int)((lon - lon_int)*1e7);
    unsigned char lat_int = (unsigned char)lat;
    unsigned int lat_dec = (unsigned int)((lat - lat_int)*1e7);

    str[0] = sgn;
    *(int*)(&str[1]) = lon_int;
    *(int*)(&str[2]) = lon_dec;
    *(int*)(&str[6]) = lat_int;
    *(int*)(&str[7]) = lat_dec;

    std::string tmp(str,11);
    ss << "#RPG" << tmp << "\r\n";
    msg.data = ss.str();
    pub_.publish(msg);

    // ModeStart(AutoMode);

}

void SendLowSpeedMode(double lon, double lat,double dir)
{

    std_msgs::String msg;
    ss.clear();   
    char str[100]={0};
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

    if(dir>0)
    {

    }
    else
    {
        dir = -dir;
        sgn |= 0x20;
    }

    unsigned char lon_int = (unsigned char)lon;
    unsigned int lon_dec = (unsigned int)((lon - lon_int)*1e7);
    unsigned char lat_int = (unsigned char)lat;
    unsigned int lat_dec = (unsigned int)((lat - lat_int)*1e7);
    unsigned char dir_int = (unsigned char)dir;
    unsigned int dir_dec = (unsigned int)((dir - dir_int)*1e7);

    str[0] = sgn;
    *(int*)(&str[1]) = lon_int;
    *(int*)(&str[2]) = lon_dec;
    *(int*)(&str[6]) = lat_int;
    *(int*)(&str[7]) = lat_dec;
    *(int*)(&str[11]) = dir_int;
    *(int*)(&str[12]) = dir_dec;

    std::string tmp(str,16);
    ss << "#LPG" << tmp << "\r\n";
    msg.data = ss.str();
    pub_.publish(msg);

    // ModeStart(LowSpeedMode);

}

void SendStableMode(double lon, double lat,double dir)
{

    std_msgs::String msg;
    // ss.clear();   
    char str[100]={0};
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

    if(dir>0)
    {

    }
    else
    {
        dir = -dir;
        sgn |= 0x20;
    }

    unsigned char lon_int = (unsigned char)lon;
    unsigned int lon_dec = (unsigned int)((lon - lon_int)*1e7);
    unsigned char lat_int = (unsigned char)lat;
    unsigned int lat_dec = (unsigned int)((lat - lat_int)*1e7);
    unsigned char dir_int = (unsigned char)dir;
    unsigned int dir_dec = (unsigned int)((dir - dir_int)*1e7);

    str[0] = sgn;
    *(int*)(&str[1]) = lon_int;
    *(int*)(&str[2]) = lon_dec;
    *(int*)(&str[6]) = lat_int;
    *(int*)(&str[7]) = lat_dec;
    *(int*)(&str[11]) = dir_int;
    *(int*)(&str[12]) = dir_dec;

    std::string tmp(str,16);
    ss << "#SPG" << tmp << "\r\n";
    msg.data = ss.str();
    pub_.publish(msg);

    // ModeStart(StableMode);

}


void SendAvoidMode(double lon,double lat)
{
    std_msgs::String msg;
    ss.clear();
    char str[100]={0};
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

    unsigned char lon_int = (unsigned char)lon;
    unsigned int lon_dec = (unsigned int)((lon - lon_int)*1e7);
    unsigned char lat_int = (unsigned char)lat;
    unsigned int lat_dec = (unsigned int)((lat - lat_int)*1e7);

    str[0] = sgn;
    *(int*)(&str[1]) = lon_int;
    *(int*)(&str[2]) = lon_dec;
    *(int*)(&str[6]) = lat_int;
    *(int*)(&str[7]) = lat_dec;
    std::string tmp(str,11);
    ss << "#RPO" << tmp << "\r\n";
    msg.data = ss.str();
    pub_.publish(msg);

    // ModeStart(AutoMode);
}

void SendCircleMode(double lon,double lat,double r=100)
{
    std_msgs::String msg;
    ss.clear();
    char str[100]={0};
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
    // if(r>0)
    // {

    // }
    // else
    // {
    //     r = -r;
    //     sgn |= 0x20;
    // }

    unsigned char lon_int = (unsigned char)lon;
    unsigned int lon_dec = (unsigned int)((lon - lon_int)*1e7);
    unsigned char lat_int = (unsigned char)lat;
    unsigned int lat_dec = (unsigned int)((lat - lat_int)*1e7);
    // unsigned char r_int = (unsigned char)r;
    // unsigned int r_dec = (unsigned int)((r - r_int)*1e7);

    str[0] = sgn;
    *(int*)(&str[1]) = lon_int;
    *(int*)(&str[2]) = lon_dec;
    *(int*)(&str[6]) = lat_int;
    *(int*)(&str[7]) = lat_dec;
    // *(int*)(&str[11]) = r_int;
    // *(int*)(&str[12]) = r_dec;

    std::string tmp(str,11);
    ss << "#RPC" << tmp << "\r\n";
    msg.data = ss.str();
    pub_.publish(msg);

    // ModeStart(AutoMode);
}

};







#endif 