#ifndef _MY_TEST_H_
#define _MY_TEST_H_

#include "string"
#include "ros/ros.h"
#include "stdio.h"
// #include "iostream"



void DispData(std::string msg)
{
    char str[100]={0};
    int len = msg.length();
    msg.copy(str,len);
    for (size_t i = 0; i < len; i++)
    {
        printf(" %02x ",str[i]);
    }
    printf("\n");
    fflush(stdout);
}


#endif