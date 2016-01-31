
// Snakegame.cpp : Defines the entry point for the console application.
#include<iomanip>
#include<iostream>
#include<conio.h>
#include"stdafx.h"
using namespace std;
bool gameOver;
const int width=50;
const int height=26;
int x,y, fruitx, fruity, score;
int tailx[100],taily[100];
int ntail;
enum eDirection { Stop = 0, Left, Right, up, down};
eDirection dir;
	void setup()
	{
		gameOver= false;
		dir=Stop;
		x= 10;
		y=10;
		fruitx = rand() % width;
		fruity = rand() % height;
		score=0;
	}

	void draw()
	{
		system("cls");
		cout<<"		Score: "<<score<<endl;
		for(int i=0; i < width+2; i++)
			cout<<"#";
		cout<<endl;
		for(int i=0; i < height; i++)
		{
			for(int j=0;j<width;j++)
			{
				if(j==0)
					cout<<"#";
				if(i==y && j==x)
					cout<<"e";
				else if(i==fruity && j==fruitx)
					cout<<"$";
				else
				{
					bool print=false;
					for(int k=0;k<ntail;k++)
					{
						if(tailx[k]==j && taily[k]==i)
						{
							cout<<"o";
							print=true;
						}
					}
					if(!print)
						cout<<" ";
					
				}
				if (j==width-1)
						cout<<"#";
			}
			cout<<endl;
		}
		for(int i=0; i < width+2; i++)
			cout<<"#";
		cout<<endl;
	}

	void input()
	{
		if(_kbhit())
			switch(_getch())
			{
				case 'w':
					dir=up;
					break;
				case 'a':
					dir=Left;
					break;
				case 'd':
					dir=Right;
					break;
				case 's':
					dir=down;
					break;
				case 'x':
					gameOver=true;
					break;
			}
	}

	void logic()
	{
		int prex=tailx[0];
		int prey=taily[0];
		int pre2x,pre2y;
		taily[0]=y;
		tailx[0]=x;
		for(int i=1; i<ntail; i++)
		{
			pre2x=tailx[i];
			pre2y=taily[i];
			tailx[i]=prex;
			taily[i]=prey;
			prex=pre2x;
			prey=pre2y;

		}
		switch(dir)
		{
			case Left:
				x--;
				break;
			case Right:
				x++;
				break;
			case up:
				y--;
				break;
			case down:
				y++;
				break;
			default:
				break;
		}
		if(x>width||x<0||y>height||y<0)
			gameOver=true;
		for(int i=0; i<ntail;i++)
			if(tailx[i]==x &&taily[i]==y)
				gameOver=true;
		
		if(x==fruitx&&y==fruity)
		{
			score++;
			fruitx = rand() % width;
			fruity = rand() % height;
			ntail++;

		}
	}

int main()
{
	setup();
		while(!gameOver)
		{
			draw();
			input();
			logic();
			//sleep(10);
		}
return 0;
}


