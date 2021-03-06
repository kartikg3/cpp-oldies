#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>

#define HEAD 11
#define TAIL 22
#define NONE 0
#define RIGHT 3
#define LEFT 1
#define UP 2
#define DOWN 4


int DirectionStatus;
int SnakeSize;
int FoodTake;
int speed=100;
int level=1;
int round=1;

struct SnakeSect
 {
  int x;
  int y;
  int HeadTailStatus;
 }s[10];

struct Food
 {
  int x,y;
 }food;

void main()
 {

    int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "");
  errorcode = graphresult();

  if (errorcode != grOk)  /* an error occurred */
   {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);             /* return with error code */
   }
   char c,nc;
   int xcorr,ycorr;
   start:
   {
    setfillstyle(SOLID_FILL,0);
    bar(0,0,700,600);
    setfillstyle(SOLID_FILL,2);
    DirectionStatus=RIGHT;
    SnakeSize=4;
    for(int i=0;i<SnakeSize;i++)
     {
      s[i].x=0,s[i].y=0;
     }
   }
   FoodTake=1;
   {
    setcolor(1);
    s[0].x=0;s[0].y=0;
    for(int l=0;l<SnakeSize;l++)
     {
      s[l].HeadTailStatus=NONE;
      bar(s[l].x,s[l].y,s[l].x+10,s[l].y+10);
      s[l+1].x=s[l].x+10;
      s[l+1].y=s[l].y;
     }
    s[0].HeadTailStatus=TAIL;
    s[SnakeSize-1].HeadTailStatus=HEAD;
   }

  int timer=0;
  int color;
  char clevel[2];
  char cround[2];

  while(1)
   {
    if(timer==5)
    {
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    bar(0,0,460,480);
    }
    if(FoodTake==1)
     {
      //setfillstyle(SOLID_FILL,0);
      //bar(food.x,food.y,food.x+10,food.y+10);
      color=10;
      if(timer==20)
      {
      FoodTake=0;
      color=6;
      food.x=rand()%500+10;
      food.y=rand()%400+10;
       xcorr=food.x%10;
       ycorr=food.y%10;
      food.x-=xcorr;
      food.y-=ycorr;
      }
     }

    outtextxy(10,0,"Round - ");
    outtextxy(65,0,itoa(round,cround,10));

    outtextxy(10,10,"Level - ");
    outtextxy(65,10,itoa(level,clevel,10));

    setfillstyle(SOLID_FILL,color);
      bar(food.x,food.y,food.x+10,food.y+10);

    if(kbhit())
     {
      c=getch();
      switch(c)
       {
	case '`':
	 exit(1);
	 break;

	case 'd':
	 if(DirectionStatus!=LEFT)
	 DirectionStatus=RIGHT;
	 break;

	case 'a':
	 if(DirectionStatus!=RIGHT)
	 DirectionStatus=LEFT;
	 break;

	case 'w':
	 if(DirectionStatus!=DOWN)
	 DirectionStatus=UP;
	 break;

	case 's':
	 if(DirectionStatus!=UP)
	 DirectionStatus=DOWN;
	 break;
       }
     }
    for(int i=0;i<SnakeSize;i++)      	//checking for the head
     {
      if(s[i].HeadTailStatus==HEAD)
       break;
     }
    for(int j=0;j<SnakeSize;j++)	//checking for the tail
     {
      if(s[j].HeadTailStatus==TAIL)
       break;
     }
     delay(speed);



     //if((s[i].x<=(food.x+120)&&s[i].x>=(food.x+120))&&(s[i].y<=(food.y+120)&&s[i].y>=(food.y+120)))
     if(s[i].x==food.x&&s[i].y==food.y)
     {
      SnakeSize++;
      if(SnakeSize==9)
       {
	level++;
	outtextxy(50,400,"Y O U  W I N  T H E  L E V E L ! ! !");
	delay(1000);
	 if(level==9)
	  {
	   setcolor(0);
	   outtextxy(50,400,"Y O U  W I N  T H E  L E V E L ! ! !");
	   setcolor(3);
	   outtextxy(50,400,"Y O U  W I N  T H E  R O U N D ! ! !");
	   delay(1000);
	   exit(1);
	  }
	speed-=10;
	goto start;
       }
      FoodTake=1;
      s[i].x=food.x;
      s[i].y=food.y;
      bar(s[i].x,s[i].y,s[i].x+10,s[i].y+10);
      //printf("good");
     }

     //food-in-the-bellyeffect module
     if(FoodTake==1)
     for(int b=0;b<SnakeSize;b++)
     {
      if(s[b].x==food.x&&s[b].y==food.y)
      {
      color=10;
      //printf("good");
      }
      else
      color=0;
      //setcolor(0);
      //setfillstyle(SOLID_FILL,0);
      //bar(s[SnakeSize].x,s[SnakeSize].y,s[SnakeSize].x+10,s[SnakeSize].y+10);
     }

     //timer function
     {
      if(timer>50)
       timer=0;
      else
       timer++;
     }
      //tail erasure
     {
     {
      setfillstyle(SOLID_FILL,0);
      bar(s[j].x,s[j].y,s[j].x+10,s[j].y+10);
      setfillstyle(SOLID_FILL,2);
     }

    //head draw
     {
      switch(DirectionStatus)
       {
	case RIGHT:

	 bar(s[i].x+10,s[i].y,s[i].x+20,s[i].y+10);
	 s[j].x=s[i].x+10;
	 s[j].y=s[i].y;
	 break;

	case DOWN:
	 s[j].x=s[i].x;
	 s[j].y=s[i].y+10;
	 bar(s[j].x,s[j].y,s[j].x+10,s[j].y+10);
	 break;

	case UP:
	 s[j].x=s[i].x;
	 s[j].y=s[i].y-10;
	 bar(s[j].x,s[j].y,s[j].x+10,s[j].y+10);
	 break;

	case LEFT:
	 s[j].x=s[i].x-10;
	 s[j].y=s[i].y;
	 bar(s[j].x,s[j].y,s[j].x+10,s[j].y+10);
	 break;
       }
     }
    s[j].HeadTailStatus=HEAD;
     if(j+1>SnakeSize-1)
      j=0;
     else
      j++;
     s[j].HeadTailStatus=TAIL;
     s[i].HeadTailStatus=NONE;

      {
       for(int k=0;k<SnakeSize;k++)
	{
	 for(int m=k+1;m<SnakeSize;m++)
	 if(s[k].HeadTailStatus!=HEAD&&s[m].HeadTailStatus!=HEAD)
	  {
	   if(s[k].x==s[m].x&&s[k].y==s[m].y)
	    {
	     outtextxy(50,400,"G A M E   O V E R");
	     delay(1000);
	     while(1)
	     {
	     setcolor(2);
	     outtextxy(50,450,"Play Again ?! y/n");
	     setcolor(14);
	     outtextxy(50,450,"Play Again ?! y/n");
	     if(kbhit())
	      {
	       nc=getch();
	       switch(nc)
	       {
	       case 'y':
	       speed=100;
	       level=1;
	       round=1;
	       goto start;
	       break;

	       case 'n':
	       goto end;
	       break;
	       }
	      }

	     }
	    }
	  }
	 else continue;
	}
      }
     }

   }
  end:
  closegraph();
 }
