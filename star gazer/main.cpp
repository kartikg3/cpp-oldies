/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ 					S T A R   G A Z E R   S C R E E N S A V E R 				          /
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
  }s[500],s2[500];
int main()
 {
  int j;

 //default error handler code for Graphics mode
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


 //Module for creating the Stars Tile
 for(j=0;j<(100);j++)
     {
      s[j].x=rand()%570+10;
      s[j].y=rand()%390+5;
      putpixel(s[j].x,s[j].y,8);

      s2[j].x=rand()%570+10;
      s2[j].y=rand()%390+5;
      putpixel(s2[j].x,s2[j].y,15);

     }

 //Main Animation Module
 while(1)
 {
   if(kbhit())		//Comes out of ScrSaver
    break;
    //Module for flashing display - feel free to change the properties
      setcolor(14);
      outtextxy(230,400,"STAR GAZER SCREENSAVER");
      setcolor(6);
      delay(15);
      outtextxy(230,400,"STAR GAZER SCREENSAVER");
    //Module for scrolling the Stars Tile Horizontally
      delay(50);
 for(j=0;j<(100);j++)
     {
      putpixel(s[j].x,s[j].y,0);
      if(s[j].x<651)
       s[j].x++;
      else if(s[j].x>650)
       s[j].x=0;
      putpixel(s[j].x,s[j].y,8);

      putpixel(s2[j].x,s2[j].y,0);
       if(s2[j].x<651)
       s2[j].x+=2;
      else if(s2[j].x>650)
       s2[j].x=0;
      putpixel(s2[j].x,s2[j].y,15);
     }
  }

  return 1;
 }
