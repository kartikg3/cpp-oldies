#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int starcount=700;

    // stars
    float x[700];
    float y[700];
    float z[700];
    


int main()
{
    int gdriver = DETECT, gmode;
    //initgraph(&gdriver, &gmode, "");
    
    printf("use A/S/W/D/Q/E for navigation\npress '~' to exit");
    
    // uncomment the below line if u are using dev cpp and intialized regular graphics procedures
    initwindow(1018,720);
    
    // center point of screen (roughly)
    int xc, yc;
    xc = 509, yc = 360;
    //xc = 0, yc = 0;
    
    // the Z-plane VIEW PLANE (on which perspective projection is to be applied
    float zvp = 5;
    
    // the 3d points TRANSFORMED to 2d screen coordinates (perspective proj.)
    float xp;
    float yp;
    
    
    // points specification
    int j;
    for(j=0;j<(starcount);j++)
     {
      x[j]=rand()%1700;
      y[j]=rand()%1700;
      z[j]=rand()%700;
     }
    
    int i;
    char c;
    double xtemp, ytemp, ztemp;
    float theta[starcount], rad;
    //theta = 0;
    // interactive animation loop
    do
    {
    if(kbhit()) // traces keyboard input
    {
     clearviewport();             // clears screen
     c = getch();                  // stores keyboard input character
    }
     switch(c)
     {
      case 'd':                    // moving rightside
           for(i=0 ; i<starcount ; i++)
           {
                   x[i]+=15;
           }
           break;
      case 'a':                    // moving leftside
           for(i=0 ; i<starcount ; i++)
           {
                   x[i]-=15;
           }
           break;
      case 's':                    // moving down
           for(i=0 ; i<starcount ; i++)
           {
                   y[i]+=15;
           }
           break;
      case 'w':                    // mioving up
           for(i=0 ; i<starcount ; i++)
           {
                   y[i]-=15;
           }
           break;
      case 'q':                    // moving our Z-ViewPlane forward
           for(i=0 ; i<starcount ; i++)
           z[i]-=2.0;
           break;
      case 'e':                    // moving our Z-ViewPlane backward
           for(i=0 ; i<starcount ; i++)
           z[i]+=2.0;
           break;
      case 'r':
           for(i=0 ; i<starcount ; i++)
           {
           theta[i]+=0.1;
           rad = theta[i]*(3.142/180);
           xtemp = z[i]*sin(rad)+x[i]*cos(rad);
           ztemp = z[i]*cos(rad)-x[i]*sin(rad);
           x[i] = xtemp;
           z[i] = ztemp;
           y[i] = y[i];
           //x[i] = 100;
           //printf("%.2f,%.2f,%.2f\t%.2f %.2f %.2f\n ",x[i],y[i],z[i], rad, ztemp, ytemp);
           }
           break;
      case 't':
           for(i=0 ; i<starcount ; i++)
           {
           theta[i]-=0.1;
           rad = theta[i]*(3.142/180);
           xtemp = z[i]*sin(rad)+x[i]*cos(rad);
           ztemp = z[i]*cos(rad)-x[i]*sin(rad);
           x[i] = xtemp;
           z[i] = ztemp;
           y[i] = y[i];
           //x[i] = 100;
           //printf("%.2f,%.2f,%.2f\t%.2f %.2f %.2f\n ",x[i],y[i],z[i], rad, ztemp, ytemp);
           }
           break;
      case 'f':
           for(i=0 ; i<starcount ; i++)
           {
           theta[i]+=0.1;
           rad = theta[i]*(3.142/180);
           ytemp = -z[i]*sin(rad)+y[i]*cos(rad);
           ztemp = z[i]*cos(rad)+y[i]*sin(rad);
           y[i] = ytemp;
           z[i] = ztemp;
           x[i] = x[i];
           //x[i] = 100;
           //printf("%.2f,%.2f,%.2f\t%.2f %.2f %.2f\n ",x[i],y[i],z[i], rad, ztemp, ytemp);
           }
           break;
      case 'g':
           for(i=0 ; i<starcount ; i++)
           {
           theta[i]-=0.1;
           rad = theta[i]*(3.142/180);
           ytemp = -z[i]*sin(rad)+y[i]*cos(rad);
           ztemp = z[i]*cos(rad)+y[i]*sin(rad);
           y[i] = ytemp;
           z[i] = ztemp;
           x[i] = x[i];
           //x[i] = 100;
           //printf("%.2f,%.2f,%.2f\t%.2f %.2f %.2f\n ",x[i],y[i],z[i], rad, ztemp, ytemp);
           }
           break;
     } 
     if(c!='`') c = '!';
     int colorflick = WHITE; // ;)
    for(i=0 ; i<starcount ; i++)
    {
    
     //THE PERSPECTIVE PROJXN FORMULA!!!! :)
     xp=x[i]*(zvp/z[i]);
     yp=y[i]*(zvp/z[i]);
     // for all stars...
     
     // plot the transformed screen coords..
     if(!(z[i] < 0 || z[i] > 500))          // clip planes
     {
      if(z[i] > 70 && z[i] <= 200)
      {
              colorflick = 7; //3, 6, 7, 8
      }      
      else if(z[i] > 200 && z[i] <= 500)
      {
              colorflick = 8;
      }
      else colorflick = WHITE;
      ///putpixel(xp+xc, yp+yc, colorflick);
      if(z[i]<10 && z[i]>=4)
      {
       setcolor(BLACK);
       setfillstyle(SOLID_FILL,colorflick);
       fillellipse(xp+xc, yp+yc, 2, 2);
      }
      else if(z[i]<4 && z[i]>=2)
      {
       setcolor(BLACK);
       setfillstyle(SOLID_FILL,colorflick);
       fillellipse(xp+xc, yp+yc, 4, 4);
      }
      else if(z[i]<2 && z[i]>=0)
      {
       setcolor(BLACK);
       setfillstyle(SOLID_FILL,colorflick);
       fillellipse(xp+xc, yp+yc, 10, 10);
      }
      else putpixel(xp+xc, yp+yc, colorflick);
     }
     //if(z[i]<0)
//     {
//      x[i]=rand()%1700;
//      y[i]=rand()%1700;
//      z[i]=rand()%700;
//     }
    
    }
    }while(c!='`');  // comes out on a "~" keypress
    return 1;
}
