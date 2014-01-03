/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ 					       T H E  L I N E  G A M E				          /
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

struct star
  {
   int x;
   int y;
   int color;
  }s[500],s2[500];
int main()
 {
  initwindow(640,480);


 int speed=1,ik,amox1,amoy1,supx1,supy1,ij,k,j,r,x1=4,y1=80,x2=100,y2=80,xx,yy,pos,xx2,yy2,xxx,yyy,i=0,healthx=500,ammox=500,ammoflag=0,healthflag=0;
    int points=0;
  char c,score[10],highscore[10];
    FILE *hi;
    void refresh_page();
 // void far setcolor(7);
 
  setcolor(9);
  line(x1, y1, x2, y2);
 // printf("\n\t\t\t\tTHE  LINE  GAME\n\t\t\t\t~~~~~~~~~~~~~~~\n");
  /* clean up */

   pos=80;
  xx2=580;
  yy2=110;


  {
     //  ***************************************************************
     //  	GAME 		ENVIRONMENT 		MODULE
     //  ***************************************************************

   setfillstyle(1,7);
   bar(0,0,getmaxx(),61);
   setfillstyle(1,7);
   bar(0,416,getmaxx(),getmaxy());
   setfillstyle(2,7);
   bar(632,62,getmaxx(),415);
   setfillstyle(2,7);
   bar(0,62,3,415);
   setfillstyle(1,7);
   bar(0,45,getmaxx(),57);
   setfillstyle(1,7);
   bar(0,0,15,45);
   setfillstyle(1,7);
   bar(515,0,getmaxx(),57);
   setcolor(15);
   line(14,0,14,45);
   setcolor(8);
   line(516,0,516,45);
   setfillstyle(1,8);
   bar(14,45,516,46);
   setcolor(15);

   setcolor(8);
   line(0,57,getmaxx(),57);
    setcolor(15);
   line(0,58,getmaxx(),58);

   line(3,62,600+30,62);
   line(2,61,601+30,61);
   line(2,61,602+30,61);

   line(3,62,3,414);
   line(2,61,2,415);

   setcolor(8);

   line(2,415,601+30,415);
   line(3,414,600+30,414);

   line(601+30,415,601+30,61);
   line(600+30,414,600+30,62);

   //energy bar

    setcolor(8);
   line(0,420,getmaxx(),420);
    setcolor(15);
   line(0,421,getmaxx(),421);
    setcolor(8);
   outtextxy(18,15,"Energy : ");
   setfillstyle(1,0);
   bar(100,13,500,23);

   setfillstyle(1,2);
   bar(102,14,500,23);

   //ammo bar
    outtextxy(18,34,"Ammo   : ");

    setfillstyle(1,0);
   bar(100,33,500,42);

   setfillstyle(1,9);
   bar(102,34,500,42);

   //score display
    outtextxy(470,427,"Score     : ");
     setfillstyle(1,0);
     bar(560,425,610,437);
     setcolor(8);
      line(559,424,611,424);
      line(559,424,559,438);
     setcolor(15);
      line(611,425,611,438);
      line(559,438,611,438);

    setcolor(8);
    outtextxy(470,448,"Hi-Score  : ");
     setfillstyle(1,0);
     bar(560,425+20,610,437+20);
     setcolor(8);
      line(559,424+20,611,424+20);
      line(559,424+20,559,438+20);
     setcolor(15);
      line(611,425+20,611,438+20);
      line(559,438+20,611,438+20);

      //hi=fopen("highscr.txt","r");
     setcolor(2);
      //fscanf(hi,"%s",&highscore);
      outtextxy(562,427+20,highscore);
      //fclose(hi);
    setcolor(9);
   /* draw a line */
//   outtextxy(2,38,"score : ");
//   line(x1,y1,x2,y2);

 for(j=0;j<(50);j++)
     {
      s[j].x=rand()%570+10;
      s[j].y=rand()%290+90;
      putpixel(s[j].x,s[j].y,8);

      s2[j].x=rand()%570+10;
      s2[j].y=rand()%290+90;
      putpixel(s2[j].x,s2[j].y,15);

     }

   }
   ij=0;
     supx1=getmaxx()-25;
      supy1=rand()%190+90;

    ik=0;
       amox1=getmaxx()-25;
      amoy1=rand()%190+90;
  do
   {


 while(pos!=166)
 {


   do
   {
    if(points==200)
     speed=5;
    setcolor(2);
    outtextxy(562,427,itoa(points,score,10));

    if((healthflag==1)&&ij>=25)
    {
      //module for health suppliment
      //ij=0;


	{
	 //battery animation
	  setfillstyle(1,15);
	   bar(supx1+2,supy1-2,supx1+3,supy1);
	  setfillstyle(1,14);
	   bar(supx1,supy1,supx1+5,supy1+2);
	  setfillstyle(1,4);
	   bar(supx1,supy1+2,supx1+5,supy1+8);
	   delay(5);

	  setfillstyle(1,15);
	   bar(supx1+2,supy1-2,supx1+3,supy1);
	  setfillstyle(1,1);
	   bar(supx1,supy1,supx1+5,supy1+2);
	  setfillstyle(1,4);
	   bar(supx1,supy1+2,supx1+5,supy1+8);delay(10);
	 // supx1-=5;

	 setfillstyle(1,15);
	   bar(supx1+2,supy1-2,supx1+3,supy1);
	  setfillstyle(1,14);
	   bar(supx1,supy1,supx1+5,supy1+2);
	  setfillstyle(1,4);
	   bar(supx1,supy1+2,supx1+5,supy1+8);
	   delay(0);

		  setfillstyle(1,0);
	   bar(supx1+2,supy1-2,supx1+3,supy1);
	  setfillstyle(1,0);
	   bar(supx1,supy1,supx1+5,supy1+2);
	  setfillstyle(1,0);
	   bar(supx1,supy1+2,supx1+5,supy1+8);
	  supx1-=5;

	  setcolor(2);
	  outtextxy(450,405,"grab the energy pack!");delay(10);
	  setcolor(2);
	  outtextxy(450,405,"grab the energy pack!");delay(10);
	  setcolor(0);
	  outtextxy(450,405,"grab the energy pack!");


       }
   }
   //if(ij==50){ij=0;}
   ij++;


     if(supx1<=18)
      {
       ij=0;
       supy1=rand()%190+90;
       supx1=getmaxx()-25;
       healthflag=1;
      }

     if(ij>=25&&healthflag==1&&(supx1<=(x2))&&(supx1>=(x1))&&((supy1>=(y2-7)&&supy1<=(y2+7))))
     {
      ij=0;
      healthflag=0;
      healthx+=200;
      setfillstyle(1,2);
      bar(102,14,healthx,23);
      supy1=rand()%190+90;
      supx1=getmaxx()-25;
     }
   ik++;
     //module for ammo supplement animation
     if((ammoflag==1)&&ik>=25)
    {
      //module for ammo suppliment
      //ij=0;


	{
	 //bullet animation
	  setfillstyle(2,7);
	   bar(amox1,amoy1,amox1+5,amoy1+10);delay(10);
	  setfillstyle(2,7);
	   bar(amox1,amoy1,amox1+5,amoy1+10);delay(10);
	  setfillstyle(2,0);
	   bar(amox1,amoy1,amox1+5,amoy1+10);delay(10);



	  amox1-=5;

	  setcolor(2);
	  outtextxy(450,390,"grab the ammo pack!");delay(10);
	  setcolor(2);
	  outtextxy(450,390,"grab the ammo pack!");delay(10);
	  setcolor(0);
	  outtextxy(450,390,"grab the ammo pack!");


       }
   }
   //if(ij==50){ij=0;}



     if(amox1<=18)
      {
       ik=0;
       amoy1=rand()%190+90;
       amox1=getmaxx()-25;
       ammoflag=1;
      }

     if(ik>=25&&ammoflag==1&&(amox1<=(x2))&&(amox1>=(x1))&&((amoy1>=(y2-10)&&amoy1<=(y2+10))))
     {
      ik=0;
      ammoflag=0;
      ammox+=200;
      setfillstyle(1,9);
      bar(102,34,ammox,42);
      amoy1=rand()%190+90;
      amox1=getmaxx()-25;
     }

   {
     for(j=0;j<95;j++)
      {
       if(s[j].x>=598) {s[j].x=6;}
       putpixel(s[j].x,s[j].y,8);
       delay(0);
       putpixel(s[j].x,s[j].y,0);
       s[j].x++;
       putpixel(s[j].x,s[j].y,8);

       if(s2[j].x>=598) {s2[j].x=6;}
       putpixel(s2[j].x,s2[j].y,15);
       delay(0);
       putpixel(s2[j].x,s2[j].y,0);
       s2[j].x+=3;
       putpixel(s2[j].x,s2[j].y,15);

       setcolor(0);
       line(600,63,600,413);
       line(599,63,599,413);
       line(598,63,598,413);
       setcolor(9);
      }

   }



    pos+=20;
    i+=speed;

    setcolor(4);
    setfillstyle(1, 8);
    fillellipse(xx2,yy2,20,20);
    setcolor(0);delay(60);
    setfillstyle(1, 0);
    //setfillstyle(0,0);
  //  refresh_page();
    fillellipse(xx2,yy2,20,20);
    xx2-=4;
    //fillellipse(xx2,80,20,20);
   // fillellipse(xx2,70,20,20);

    setcolor(9);


    //setfillstyle(0,2);
    if(xx2<100)
     {
	setcolor(2);
	 for(i=0;i<10;i++)
	 {
	  outtextxy(getmaxx()/2-50,getmaxy()/2,"G A M E   O V E R");delay(250);
	  setcolor(2);
	  outtextxy(getmaxx()/2-50,getmaxy()/2,"G A M E   O V E R");delay(350);
	  setcolor(0);

	 }

	 setcolor(2);getch();goto end;

     }
   if(kbhit())
   {
   c=getch();
   if(c==119)
    { //module for w-keypress (up)
     if(y1>68)
     {
     setcolor(0);
     line(x1, y1, x2, y2);
     setcolor(9);
     y1-=6;
     y2-=6;
     line(x1, y1, x2, y2);
     }
    }
   else if(c==115)
    { //module for s-keypress (down)
     if(y1<400)
     {
     setcolor(0);
     line(x1, y1, x2, y2);
     setcolor(9);
     y1+=6;
     y2+=6;
     line(x1, y1, x2, y2);
     }
    }
   else if(c=='`')
    exit(1);
  /* else if(c==97)
    { //module for a-keypress (left)
     if(x1>0)
     {
     setcolor(0);
     line(x1, y1, x2, y2);
     setcolor(2);
     x1-=3;
     x2-=3;
     line(x1, y1, x2, y2);
     }
    }
   else if(c==100)
    { //module for d-keypress (right)
     if(x2<580)
     {
     setcolor(0);
     line(x1, y1, x2, y2);
     setcolor(2);
     x1+=3;
     x2+=3;
     line(x1, y1, x2, y2);
     }
    }*/

   else if(c==32&&ammox>110)
    { //module for shooting (space)

     ammox--;
     if(ammox<=200)
       {
	ammoflag=1;
	setfillstyle(1,6);
	bar(102,34,500,42);
       }

	 {
	 setfillstyle(1,0);
	 ammox=ammox-10;
	 bar(ammox,34,500,42);
	 }
     if(ammox>0)
     {
     xx=x2;yy=y2;
     while(xx<=590)
      {
       
       xx+=9;setcolor(12);
       circle(xx,yy,3);
       setcolor(0);




       xx-=8;delay(0);
       circle(xx,yy,3);
       }

       if((xx>=(xx2-40))&&(yy>=(yy2-20)&&yy<=(yy2+20)))//&&yy<(70)))
	{
	 //printf("GOOD SHOT!!!");
	
	 setfillstyle(1,14);delay(15);
	 fillellipse(xx2,yy2,20+15,20+15);
	 setfillstyle(1,0);delay(25);
	 fillellipse(xx2,yy2,20+15,20+15);
	 setfillstyle(1,14);delay(25);
	 fillellipse(xx2,yy2,20,20);
	 setfillstyle(1,0);delay(10);
	 fillellipse(xx2,yy2,20,20);
	 setfillstyle(1,14);delay(20);
	 fillellipse(xx2,yy2,20-5,20-5);
	 setfillstyle(1,0);delay(20);
	 fillellipse(xx2,yy2,20,20);
	 
      //	 setfillstyle(1,14);
       //	 fillellipse(xx2,70,20-15,20-15);


	  setcolor(0);
	 outtextxy(562,427,itoa(points,score,10));

	 points+=50;



	 xx2=580;
	 yy2=(rand()%270+110);
	 break;
	}

      }

	setfillstyle(1,0);
       bar(xx+35,yy-10,xx-50,yy);
       bar(xx+35,yy+10,xx-50,yy);

     }




	if(ammox<=110)
      {

	 {
	  setcolor(2);
	  outtextxy(16,406,"        Out of ammo !");
	  setcolor(4);
	  outtextxy(16,406,"WARNING ");delay(50);
	  setcolor(0);
	  outtextxy(16,406,"WARNING Out of ammo !");delay(20);
	 }
	setcolor(2);

      }
     }

  // if(1)
  // if(yy2>=(y2-20)&&yy2<=(y2+20))
    if(i>=20&&y2>=(yy2-20)&&y2<(yy2+20))
     {

      //module for set_target
      //printf("in firing range");
       xxx=xx2;yyy=yy2;

       while(xxx>40)
	{
	 
	 xxx-=30;
	setcolor(3);
       circle(xxx,yyy,5);delay(0);
       setcolor(0);




       xxx+=29;delay(0);
       circle(xxx,yy2,5);
       }
       if((xxx<=(x2))&&(xxx>=(x1))&&((yy2>=(y2-4)&&yy2<=(y2+4))))//&&yy<(70)))
	{
	 healthx=healthx-100;
	 if(healthx<=200)
	 {
	 healthflag=1;
	 setfillstyle(1,4);
	 bar(102,14,500,23);
	 }
	 setfillstyle(1,0);

	 bar(healthx,14,500,23);

	 if(healthx<=120)
	 {
	 setcolor(2);
	 for(i=0;i<10;i++)
	 {
	  outtextxy(getmaxx()/2-50,getmaxy()/2,"G A M E   O V E R");delay(250);
	  setcolor(2);
	  outtextxy(getmaxx()/2-50,getmaxy()/2,"G A M E   O V E R");delay(350);
	  setcolor(0);

	 }

	 setcolor(2);getch();goto end;
	 }
	 //bar(102,14,500,23);

	}
       setfillstyle(1,0);
       bar(xxx-35,yy2+5,xxx+50,yy2);
       bar(xxx-35,yy2-5,xxx+50,yy2);

      i=0;
      if(c==27)break;

    }

    if(c==27)break;

   }while(xx2<160);
    }

   if(c==27)break;
   //clrscr();
   //if(c==27)break;
   //if(c==27)break;
  }while(c!=27);
  end:
   if(points>atoi(highscore))
    {
     //hi=fopen("highscr.txt","w");
     //fprintf(hi,"%s",itoa(points,score,10));
     //fclose(hi);
    }
  return 1;
 }
