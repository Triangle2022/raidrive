#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include <cstdio>


//target hz = 1k
//1-> 1000microseconds
double angle = 0;
double t1 = sin(M_PI/3 - angle);
double t2 = sin(angle);
double t3 = 1000-t1-t2;

void update_angle(double angle)
{
    t1 =  1000*sqrt(3)*0.5*sin(M_PI/3 - angle*(M_PI/180));
    t2 = 1000*sqrt(3)*0.5*sin(angle*(M_PI/180));
    t3 = 1000-t1-t2;
}

int main(void)
{
    using namespace std::chrono_literals;
    for(double i= 0 ;i < 6000 ; i++)
    {
        update_angle(i/100);
        std::this_thread::sleep_for(1ms);
        std::cout << "t1  " << t1 << "  t2  " << t2 << "  t3  " << t3 << " total " <<  t1+t2+t3 <<std::endl;
    }
    for(double i= 6000 ;i > 0 ; i--)
    {
        update_angle(i/100);
        std::this_thread::sleep_for(1ms);
        std::cout << "t1  " << t1 << "  t2  " << t2 << "  t3  " << t3 << " total " <<  t1+t2+t3 <<std::endl;
    }

    
}