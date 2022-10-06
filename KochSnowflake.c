#include "stdio.h"
#include "graphics.h"
#include "math.h"

double pi = 22.0/7.0;

//global variables
double X = 200;
double Y = 200;
int Angle = 30;

//change angle
int left(int angle)
{
    return angle+60;
}

int right(int angle)
{
    return angle-120;
}

//drawline
void forward(int angle, double x, double y, int l)
{
    drawLine(x,y,x+l*cos(angle*pi/180),y-l*sin(angle*pi/180)); 
}

//recursive
void koch(int angle, double x, double y, int l, int z)
{
    if(z == 0)
    {
        forward(Angle, X, Y, l);
        X = X+l*cos(Angle*pi/180);
        Y = Y-l*sin(Angle*pi/180);
    }
    
    if(z != 0)
    {
        l = l/3;
        z = z-1;
        koch(Angle, X, Y,l,z);
        Angle = left(Angle);
        koch(Angle, X, Y,l,z);
        Angle = right(Angle);
        koch(Angle, X, Y,l,z);
        Angle = left(Angle);
        koch(Angle, X, Y,l,z);
    }


}

int main (void)
{
    int l = 90;
    int z = 4;
    koch(Angle, X, Y, l, z);
    for(int i = 0; i<5; i++)
    {
    Angle = Angle +60;
    koch(Angle, X, Y, l, z);
    }
}
