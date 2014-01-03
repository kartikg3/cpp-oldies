#include<kitrak.h>

void draw_ship(int x,int y)
 {
  //body
  setcolor(7);
  setfillstyle(0,15);
  fillellipse(x,y,14,3);
  setcolor(7);
  line(x+15,y,x+20,y);
  line(x+14,y+1,x+22,y+1);
  line(x+12,y+2,x+23,y+2);
  line(x+8,y+3,x+23,y+3);
  line(x,y+4,x+22,y+4);line(x,y+4,x-60,y+4);
  setcolor(8);
  line(x,y+5,x+22,y+5);line(x,y+6,x+22,y+6);
  line(x,y+5,x-60,y+5);line(x,y+6,x-60,y+6);
  setfillstyle(2,8);
  bar(x-60,y,x-55,y+5);
  setcolor(7);
  setfillstyle(1,7);
  bar(x-55,y-2,x-14,y+4);
  line(x-15,y+2,x,y+2);
  line(x-15,y+3,x,y+3);
  setcolor(0);
  line(x-55,y,x-14,y);
  //wings
     setcolor(0);    setfillstyle(1,15);      fillellipse(x-25,y+4,17,2);
     setcolor(8);
     line(x-55,y-3,x-35,y-3);
     line(x-55,y-4,x-37,y-4);
     line(x-55,y-5,x-39,y-5);
     line(x-55,y-6,x-40,y-6);
     setcolor(7);
     line(x-55,y-7,x-40,y-7);
     line(x-55,y-8,x-35,y-8);
  do
   {
     setcolor(11);
     line(x-55,y-3,x-55,y-8);

	  setcolor(7);delay(50);
     line(x-55,y-3,x-55,y-8);

	  setcolor(11);delay(50);
     line(x-55,y-3,x-55,y-8);
  //jet fire animation


  setcolor(1);
  setfillstyle(1,11);
  fillellipse(x-70,y+2,8,3);delay(20);
  setcolor(0);
  setfillstyle(1,0);
  fillellipse(x-70,y+2,8,3);
  setcolor(1);
  setfillstyle(1,11);
  fillellipse(x-70,y+2,5,2);delay(20);
  setcolor(0);
    setfillstyle(1,0);
  fillellipse(x-70,y+2,8,3);
   }while(!kbhit());

 }

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

   draw_ship(getmaxx()/2,getmaxy()/2);

   getch();
  closegraph();
 }
