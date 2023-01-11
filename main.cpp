#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "mygraphics.h"
#include "Queuee.h"
# include "myconsole.h"
# include "point.h"
#include  <sstream>
#include<Windows.h>
using namespace std;


//-------------------------------Color Codes------------------------------//
// Color Codes Hexadecimal values for both Fore Ground and Back Ground //ForeGround|BackGround
int B_BLACK = 0x00;	int B_Royal_Blue = 0x10;	int B_Dark_Green = 0x20;
int B_Tale_Blue = 0x30;	int B_Dark_Red = 0x40;	int B_Purple = 0x50;
int B_Tale_Green = 0x60;	int B_Light_Grey = 0x70; int B_Dark_Gray = 0x80;
int B_Light_Blue = 0x90; int B_Light_Green = 0xA0;	int B_Sky_Blue = 0xB0;
int B_Red = 0xC0;	int B_Pink = 0xD0;	int B_Yellow = 0xE0;
int B_White = 0xF0;

int F_BLACK = 0x00;	int F_Royal_Blue = 0x01; int F_Dark_Green = 0x02;
int F_Tale_Blue = 0x03;	int F_Dark_Red = 0x04;	int F_Purple = 0x05;
int F_Tale_Green = 0x06;	int F_Light_Grey = 0x07; int F_Dark_Gray = 0x08;
int F_Light_Blue = 0x09; int F_Light_Green = 0x0A;	int F_Sky_Blue = 0x0B;
int F_Red = 0x0C;	int F_Pink = 0x0D;	int F_Yellow = 0x0E;
int F_White = 0x0F;

//-------------------------------POINT CLASS------------------------------//
//initialize MaxPoint
point point::MaxPoint(MAX_X, MAX_Y);
bool point::incrementX()
{
	bool returnValue = true;
	if (x < MaxPoint.x)
	{
		x++;

	}
	else if (y < MaxPoint.y)
	{
		x = 0;
		y = y + 1;
	}
	else
		returnValue = false;

	return returnValue;
}

bool point::incrementY()
{
	bool returnValue = true;
	if (y < MaxPoint.y)
		y++;
	else
		returnValue = false;

	return returnValue;

}
bool point::decrementX()
{
	bool returnValue = true;
	if (x > 0)
		x--;
	else if (y > 0)
	{
		y--;
		x = MaxPoint.x;
	}
	else
		returnValue = false;

	return returnValue;
}
bool point::decrementY()
{
	bool returnValue = true;
	if (y > 0)
		y--;
	else
		returnValue = false;

	return returnValue;

}

//-------------------------------END OF POINT CLASS------------------------------------------------//


//--------------------------The function Where you will write code--------------------------------//



void Insert_Two_Players(Linklist<int> :: Queuee &q,int n)
{
	int l = 0;
	for (int i = 1, x = 700, y = 500, p = 50, r = y; i <= n; i++, x += 300, p += 30, r -= 50)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";
		myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
		myEllipse(x, y, x + 100, y + 100, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
		myDrawTextWithFont(x + 40, y + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
	}
}
void Insert_Three_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50,y+=150)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";
		if (y == 600)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y-100, 800, y, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y-100+ 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y+50, x + 100, y + 150, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y+ 90, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
	}
}
void Insert_Four_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 150)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";

		if (i==3)
		{
			int o = x - 300;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(o, y +50, o+100, y+150, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(o+40, y +50 + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i==4)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y - 250, 800, y - 150, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y - 250 + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}

		else
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y + 50, x + 100, y + 150, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y + 90, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
	}
}
void Insert_Five_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 110, p += 30, r -= 50, y += 110)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";

		if (i == 3)
		{
			int o = x - 220;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(o, y + 55, o + 100, y + 155, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(o + 40, y + 50 + 40, 30, str, RGB(100, 0, 0), RGB(0, 200, 0));
		}
		else if (i==4)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(710, y - 100, 810, y, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(750, y - 110 + 40, 30, str, RGB(100, 0, 0), RGB(0, 200, 0));
		}
		else if (i==5)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(720, y - 350, 820, y - 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(750, y - 360 + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}

		else
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y + 55, x + 100, y + 155, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y + 90, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
	}
}
void Insert_Six_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 100)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";

		if(i==3)
		{
		myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
		myEllipse(x-150, y+200, x-50 , y + 300, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
		myDrawTextWithFont(x -110, y +240, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		
		}
	
		else if (i == 4)
		{
			int o = x - 440;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(o, y+200, o + 100, y + 300, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(o + 40, y + 240, 30, str, RGB(100, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 5)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y, 800, y+100 , COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(700+40, y+ 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 6)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y-250 , 800, y-150, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y - 210 , 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}

		else
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y+150 , x + 100, y + 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y + 190, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
	}
}
void Insert_Seven_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 120)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";

		if (i == 3)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x - 150, y + 200, x - 50, y + 300, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x - 110, y + 240, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));

		}

		else if (i == 4)
		{
			int o = x - 440;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(o, y + 170, o + 100, y + 270, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(o + 40, y + 210, 30, str, RGB(100, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 5)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y, 800, y + 100, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 6)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(650, y - 250, 750, y - 150, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(690, y - 210, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 7)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y - 500, 800, y - 400, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y - 460, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}

		else
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y + 150, x + 100, y + 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y + 190, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
	}
}
void Insert_Eight_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 120)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";

		if (i == 3)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x - 100, y + 170, x, y + 270, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x - 60, y + 210, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));

		}
		else if (i == 4)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x-270 , y + 200, x-170, y + 300, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x -230, y + 240, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));

		}

		else if (i == 5)
		{
			int o = x - 580;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(o, y + 150, o + 100, y + 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(o + 40, y + 190, 30, str, RGB(100, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 6)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(680, y+60, 780, y-40 , COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 7)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(650, y-300, 750, y -200, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(690, y - 260, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 8)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(680, y - 570, 780, y - 470, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(720, y - 530, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}

		else
		{
			if (i == 1)
			{
		
				myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
				myEllipse(x, y + 180, x + 100, y + 280, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
				myDrawTextWithFont(x + 40, y + 220, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
			}
			else
			{
				myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
				myEllipse(x, y + 150, x + 100, y + 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
				myDrawTextWithFont(x + 40, y + 190, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
			}
		}
	}
}
void Insert_Nine_Players(Linklist<int> ::Queuee& q, int n)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 120)
	{
		q.Enqueue(i);
		l = i;
		ostringstream str1;
		str1 << l;
		string str = str1.str();
		string j = "Players are :";

		if (i == 3)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x - 100, y + 170, x, y + 270, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x - 60, y + 210, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));

		}
		else if (i == 4)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x - 270, y + 200, x - 170, y + 300, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x - 230, y + 240, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));

		}

		else if (i == 5)
		{
			int o = x - 540;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(o, y + 150, o + 100, y + 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(o + 40, y + 190, 30, str, RGB(100, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 6)
		{
			int o = x - 830;
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
	     	myEllipse(o, y + 40, o+100, y+140, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
		    myDrawTextWithFont(o+40, y+80, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));

		}
		else if (i == 7)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(670, y - 200, 770, y - 100, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(710, y-160, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 8)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(650, y - 450, 750, y - 350, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(690, y - 410, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else if (i == 9)
		{
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(700, y - 700, 800, y - 600, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(740, y - 660, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}

		else
		{
			if (i == 1)
			{

				myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
				myEllipse(x, y + 180, x + 100, y + 280, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
				myDrawTextWithFont(x + 40, y + 220, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
			}
			else
			{
				myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
				myEllipse(x, y + 150, x + 100, y + 250, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
				myDrawTextWithFont(x + 40, y + 190, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
			}
		}
	}
}
void Insert_Multiple_Players(Linklist<int> ::Queuee& q, int n)
{

	int l = 0;
	for (int i = 1, x = 200, y = 500, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50)
	{
		if (x < 1700)
		{
			q.Enqueue(i);
			l = i;
			ostringstream str1;
			str1 << l;
			string str = str1.str();
			string j = "Players are :";
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y, x + 100, y + 100, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
		}
		else
		{
			x = 200;
			y += 200;
			q.Enqueue(i);
			l = i;
			ostringstream str1;
			str1 << l;
			string str = str1.str();
			string j = "Players are :";
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			myEllipse(x, y, x + 100, y + 100, COLORREF RGB(100, 0, 0), RGB(p, r, p + 70));
			myDrawTextWithFont(x + 40, y + 40, 30, str, RGB(0, 0, 0), RGB(0, 200, 0));
			
		}
	}

}


void Remove_Player_In_Two(Linklist<int> ::Queuee& q, int n, int d)
{

	for (int i = 1, x = 700, y = 500, p = 50, r = y; i <= n; i++, x += 300, p += 30, r -= 50)
	{

		if (i == d)
		{
			myEllipse(x, y, x + 100, y + 100, COLORREF RGB(0, 0, 0), RGB(0,0,0));

		}
	}
}
void Remove_Player_In_Three(Linklist<int> ::Queuee& q, int n, int d)
{

	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 150)
	{
		if (d==i && d==3)
		{

			myEllipse(700, y - 100, 800, y, COLORREF RGB(0, 0, 0), RGB(0,0,0));
	
		}
		else if(d==i)
		{

			myEllipse(x, y + 50, x + 100, y + 150, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}
	}
}
void Remove_Player_In_Four(Linklist<int> ::Queuee& q, int n, int d)
{
	
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 150)
	{
	

		if (i == d && d==3)
		{
			int o = x - 300;
			myEllipse(o, y + 50, o + 100, y + 150, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}
		else if (i ==d && d==  4)
		{

			myEllipse(700, y - 250, 800, y - 150, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
	
		}

		else if(i==d)
		{

			myEllipse(x, y + 50, x + 100, y + 150, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
	
		}
	}
}
void Remove_Player_In_Five(Linklist<int> ::Queuee& q, int n, int d)
{
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 110, p += 30, r -= 50, y += 110)
	{

		if (i == d && d==3)
		{
			int o = x - 220;
			myEllipse(o, y + 55, o + 100, y + 155, COLORREF RGB(0, 0, 0), RGB(0,0,0));

		}
		else if (i == d && d==4)
		{
		
			myEllipse(710, y - 100, 810, y, COLORREF RGB(0, 0, 0), RGB(0,0,0));
	
		}
		else if (i == d && d==5)
		{

			myEllipse(720, y - 350, 820, y - 250, COLORREF RGB(0, 0, 0), RGB(0,0,0));
	
		}

		else if(i==d)
		{
			myEllipse(x, y + 55, x + 100, y + 155, COLORREF RGB(0, 0, 0), RGB(0,0,0));

		}
	}
}
void Remove_Player_In_Six(Linklist<int> ::Queuee& q, int n, int d)
{
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 100)
	{

        if (i == d && d == 3)
		{
			
			myEllipse(x - 150, y + 200, x - 50, y + 300, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}
		else if (i == d && d == 4)
		{
			int o = x - 440;
			myEllipse(o, y + 200, o + 100, y + 300, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}
		else if (i == d && d == 5)
		{

			myEllipse(700, y, 800, y + 100, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
		}
		else if (i == d && d == 6)
		{

			myEllipse(700, y - 250, 800, y - 150, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}

		else if (i == d)
		{
			myEllipse(x, y + 150, x + 100, y + 250,  COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}
	}
}
void Remove_Player_In_Seven(Linklist<int> ::Queuee& q, int n, int d)
{

	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 120)
	{

		if (i == 3 && i==d)
		{
			myEllipse(x - 150, y + 200, x - 50, y + 300, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
		}

		else if (i == 4 && i == d)
		{
			int o = x - 440;
			myEllipse(o, y + 170, o + 100, y + 270, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
		}
		else if (i == 5 && i == d)
		{
			myEllipse(700, y, 800, y + 100, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));

		}
		else if (i == 6 && i == d)
		{
			myEllipse(650, y - 250, 750, y - 150, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
		}
		else if (i == 7 && i == d)
		{
			myEllipse(700, y - 500, 800, y - 400, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
		}

		else if(i==d)
		{
			myEllipse(x, y + 150, x + 100, y + 250, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
		}
	}
}
void Remove_Player_In_Eight(Linklist<int> ::Queuee& q, int n, int d)
{

	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 120)
	{


		if (i == 3 && i==d)
		{
			
			myEllipse(x - 100, y + 170, x, y + 270, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			

		}
		else if (i == 4 && i == d)
		{
			
			myEllipse(x - 270, y + 200, x - 170, y + 300, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			

		}

		else if (i == 5 && i == d)
		{
			int o = x - 580;
			myEllipse(o, y + 150, o + 100, y + 250, COLORREF RGB(0, 0, 0),RGB(0, 0, 0));
			
		}
		else if (i == 6 && i == d)
		{
			
			myEllipse(680, y + 60, 780, y - 40, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}
		else if (i == 7 && i == d)
		{
			
			myEllipse(650, y - 300, 750, y - 200, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}
		else if (i == 8 && i == d)
		{
			
			myEllipse(680, y - 570, 780, y - 470, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}

		else if(i==d)
		{
			if (i == 1)
			{

				
				myEllipse(x, y + 180, x + 100, y + 280, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
				
			}
			else if(i==2)
			{
				
				myEllipse(x, y + 150, x + 100, y + 250, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
				
			}
		}
	}
}
void Remove_Player_In_Nine(Linklist<int> ::Queuee& q, int n, int d)
{
	int l = 0;
	for (int i = 1, x = 850, y = 300, p = 50, r = y; i <= n; i++, x += 150, p += 30, r -= 50, y += 120)
	{

		if (i == 3 && i==d)
		{
			
			myEllipse(x - 100, y + 170, x, y + 270, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			

		}
		else if (i == 4 && i == d)
		{
			
			myEllipse(x - 270, y + 200, x - 170, y + 300, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			

		}

		else if (i == 5 && i == d)
		{
			int o = x - 540;
			
			myEllipse(o, y + 150, o + 100, y + 250, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}
		else if (i == 6 && i == d)
		{
			int o = x - 830;
			
			myEllipse(o, y + 40, o + 100, y + 140, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			

		}
		else if (i == 7 && i == d)
		{
			
			myEllipse(670, y - 200, 770, y - 100, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}
		else if (i == 8 && i == d)
		{
			
			myEllipse(650, y - 450, 750, y - 350, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}
		else if (i == 9 && i == d)
		{
			
			myEllipse(700, y - 700, 800, y - 600, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			
		}

		else  if(i==d)
		{
			if (i == 1)
			{

				
				myEllipse(x, y + 180, x + 100, y + 280, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
				
			}
			else
			{
				
				myEllipse(x, y + 150, x + 100, y + 250, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
				
			}
		}
	}
}
void Remove_Player_In_Multiple(Linklist<int> ::Queuee& q, int n,int d)
{

	int l = 1;
	for (int i = 1, x = 200, y = 500 ; i <= n; i++, x += 150,l++)
	{
		if (l<=10)
		{

			if(i==d)
			myEllipse(x, y, x + 100, y + 100, COLORREF RGB(0,0,0), RGB(0, 0, 0));
		
		}
		else
		{
			x = 200;
			y += 200;
			if(i==d)
			myEllipse(x, y, x + 100, y + 100, COLORREF RGB(0, 0, 0), RGB(0, 0, 0));
			l = 1;

		}
	}

}


void Menue(int &n, int &m, int &k,int b)
{
	string s = "Josephous Problem";
	string s1 = "Enter Number Of Players";
	string s2 = "Enter Number Of Skips";
	string s3 = "Enter starting point";

	FullScreen();

	system("CLS");


	myDrawTextWithFont(450, 400, 150, s, RGB(105, 00, 0), RGB(0, 100, 0));
	myDrawTextWithFont(550, 600, 70, s1, RGB(105, 00, 0), RGB(0, 100, 0));
	n = 31;
	while (n > 30)
	{
		cin >> n;
	}


	ostringstream str1;
	str1 << n;
	string str = str1.str();
	myDrawTextWithFont(b, 600, 70, str, RGB(105, 00, 0), RGB(0, 100, 0));
	b += 30;

	myDrawTextWithFont(550, 700, 70, s2, RGB(105, 00, 0), RGB(0, 100, 0));

	cin >> m;

	ostringstream str11;
	str11 << m;
	string str13 = str11.str();
	myDrawTextWithFont(1250, 700, 70, str13, RGB(105, 00, 0), RGB(0, 100, 0));
	myDrawTextWithFont(550, 800, 70, s3, RGB(105, 00, 0), RGB(0, 100, 0));
	k = 31;
	while (k > n)
		cin >> k;
	ostringstream str12;
	str12 << k;
	string str14 = str12.str();
	myDrawTextWithFont(1250, 800, 70, str14, RGB(105, 00, 0), RGB(0, 100, 0));
}
void main()
{
	
	int n=0, m=0, k=0, d=0,l=0,a,b=1250;
	bool specialKey = false;
	int key = 50;
	

	Menue(n, m, k,b);

	


	bool stop = false;

	key = CheckWhichKeyPressed(specialKey, 100);
	while (!stop)
	{
		key = CheckWhichKeyPressed(specialKey,100);
	
		if (key == ESCKEY)
		{
			stop = true;
		}
	

		
		else if (key == ENTERKEY)
		{
			ClearScreen();
			Linklist<int> ::Queuee q;
			if(n==2)
				Insert_Two_Players(q,n);
			if (n == 3)
				Insert_Three_Players(q, n);
			else if (n == 4)
				Insert_Four_Players(q, n);
			else if (n == 5)
				Insert_Five_Players(q, n);
			else if (n == 6)
				Insert_Six_Players(q, n);
			else if (n == 7)
				Insert_Seven_Players(q, n);
			else if (n == 8)
				Insert_Eight_Players(q, n);
			else if (n == 9)
				Insert_Nine_Players(q, n);
			else if (n > 9)
				Insert_Multiple_Players(q, n);

			Sleep(5000);
			for (int i = 1; i < k; i++)
				q.move_next();

			string j = "Players left :";
			myDrawTextWithFont(700, 100, 70, j, RGB(100, 0, 0), RGB(0, 100, 0));
			int o = n;
				while (n > 1)
				{
					
					for (int i = 1; i <= m; i++)
						q.move_next();

					    d = q.Dequeue();

						if (o == 2)
							Remove_Player_In_Two(q,o,d);
						else if (o == 3)
							Remove_Player_In_Three(q, o, d);
						else if (o == 4)
							Remove_Player_In_Four(q, o, d);
						else if (o == 5)
							Remove_Player_In_Five(q, o, d);
						else if (o == 6)
							Remove_Player_In_Six(q, o, d);
						else if (o == 7)
							Remove_Player_In_Seven(q, o, d);
						else if (o == 8)
							Remove_Player_In_Eight (q, o, d);
						else if (o == 9)
							Remove_Player_In_Nine(q, o, d);
						else if (o >9)
							Remove_Player_In_Multiple(q, o, d);
						
						
					Sleep(2500);
					n--;
				}
				d = q.Dequeue();
				string c = "Winning player is";
				myDrawTextWithFont(700, 100, 70, c, RGB(100, 0, 0), RGB(0, 100, 0));
				
			
		}
		
	}
	system("pause");

}