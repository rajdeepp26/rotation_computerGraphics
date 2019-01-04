#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a + 0.5))
#define PII 3.14

void line1(int, int, int, int);
void line2(int, int, int, int);
void line3(int, int, int, int);
void TRIANGLE(int, int, int, int, int, int);
void ROTATION(int, int, int, int, int, int, float);

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, "");


    TRIANGLE(280, 144, 230, 230, 330, 230);  					//Triangle with the defined coordinates will be generated
    delay(500);

    printf("Angle of rotation is 45 degree\n");

    ROTATION(280, 144, 230, 230, 330, 230, -45); 
    delay(1500);
}

void TRIANGLE(int x1, int y1, int x2, int y2, int x3, int y3)			//TRIANGLE() will draw the triangle
{
   line1(x1, y1, x2, y2);
   line2(x2, y2, x3, y3);
   line3(x3, y3, x1, y1);
}

void line1(int xa, int ya, int xb, int yb)			//DDA algorithm to draw the first side
{
    int dx, dy, steps, i;
    float xNext, yNext, x = xa, y = ya;

    dx = xb - xa;
    dy = yb - ya;
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xNext = dx / float(steps);
    yNext = dy / float(steps);
    putpixel(ROUND(x),ROUND(y), BLUE);
    for(i = 1; i <= steps; i++)
    {
        x = x + xNext;
        y = y + yNext;
        putpixel(ROUND(x), ROUND(y), BLUE);
    }
}


void line2(int xa, int ya, int xb, int yb)			//DDA algorithm to draw the second side
{
    int dx, dy, steps, i;
    float xNext, yNext, x = xa, y = ya;
    dx = xb - xa;
    dy = yb - ya;
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xNext = dx / float(steps);
    yNext = dy / float(steps);
    putpixel(ROUND(x),ROUND(y), RED);
    for(i = 1; i <= steps; i++)
    {
        x = x + xNext;
        y = y + yNext;
        putpixel(ROUND(x), ROUND(y), RED);
    }
}


void line3(int xa, int ya, int xb, int yb)			//DDA algorithm to draw the third side
{
    int dx, dy, steps, i;
    float xNext, yNext, x = xa, y = ya;
    dx = xb - xa;
    dy = yb - ya;
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xNext = dx / float(steps);
    yNext = dy / float(steps);
    putpixel(ROUND(x),ROUND(y), GREEN);
    for(i = 1; i <= steps; i++)
    {
        x = x + xNext;
        y = y + yNext;
        putpixel(ROUND(x), ROUND(y), GREEN);
    }
}


void ROTATION(int x1, int y1, int x2, int y2, int x3, int y3, float theta)	//rotation() will rotate the triangle in 45 degree
{
    int l1, m1, l2, m2, l3, m3, cent_xf = 250, cent_yf = 172;

    cleardevice();								//cleardevice() will remove the previously displayed triangle
    theta = (theta * PII) / 180;						//Next we convert the angle in degree to radian

    l1 = cent_xf + (x1 - cent_xf)*cos(theta) - (y1 - cent_yf)*sin(theta);
    m1 = cent_yf + (x1 - cent_xf)*sin(theta) + (y1 - cent_yf)*cos(theta);
    l2 = cent_xf + (x2 - cent_xf)*cos(theta) - (y2 - cent_yf)*sin(theta);
    m2 = cent_yf + (x2 - cent_xf)*sin(theta) + (y2 - cent_yf)*cos(theta);
    l3 = cent_xf + (x3 - cent_xf)*cos(theta) - (y3 - cent_yf)*sin(theta);
    m3 = cent_yf + (x3 - cent_xf)*sin(theta) + (y3 - cent_yf)*cos(theta);
    TRIANGLE(l1, m1, l2, m2, l3, m3);
}


