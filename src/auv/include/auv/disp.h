#ifndef _DISP_H_
#define _DISP_H_

#include "string"
#include "ros/ros.h"
#include "stdio.h"
#include "iostream"



void DispData(std::string msg)
{
    char str[100]={0};
    int len = msg.length();
    msg.copy(str,len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%02x",str[i]);
    }
    fflush();
}


#endif