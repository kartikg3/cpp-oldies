#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int starcount=700;

    // stars
    float x[700];
    float y[700];
    float z[700];
    


int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    
    // uncomment the below line if u are using dev cpp and intialized regular graphics procedures
    //initwindow(1018,720);
    
    // center point of screen (roughly)
    int xc, yc;
    xc = 200, yc = 200;
    
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
      z[j]=rand()%1700;
     }
    
    int i;
    char c;
    // interactive animation loop
    do
    {
    if(kbhit()==1) // traces keyboard input
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
           zvp+=2.0;
           break;
      case 'e':                    // moving our Z-ViewPlane backward
           zvp-=2.0;
           break;
     } 
     if(c!='`') c = '!';
    for(i=0 ; i<starcount ; i++)
    {
    
     //THE PERSPECTIVE PROJXN FORMULA!!!! :)
     xp=x[i]*(zvp/z[i]);
     yp=y[i]*(zvp/z[i]);
     // for all stars...
     
     // plot the transformed screen coords..
     putpixel(xp+xc, yp+yc, WHITE);
    }
    }while(c!='`');  // comes out on a "~" keypress
    return 1;
}
