#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>
#include <iostream.h>

#define ROUND(a) ((int)(a+0.5))

float zvp=5;
float xc = 509, yc = 360;


class Window
{
  public:
    float left, right, top, bottom;
    
    // child viewport variables
    float left_v, right_v, top_v, bottom_v;
    int drawToViewportFlag;
    
    
  //variables for line clipping
    int code1, code2;
    
  void initWindow(int _left, int _top, int _right, int _bottom)
  {
       left = _left;
       right = _right;
       top = _top;
       bottom = _bottom;
       drawToViewportFlag = 0;
       drawWindow();
  }
  
  void drawWindow()
  {
       setcolor(WHITE);
       rectangle(left, top, right, bottom);
  }
  
  // methods for line clipping
  int encode(float x1, float y1, float x2, float y2)
  {
     if(x1<left)
      code1 = code1|0x0001;
     else if(x1>right)
      code1 = code1|0x0010;
     if(y1<top)
      code1 = code1|0x1000;
     else if(y1>bottom)
      code1 = code1|0x0100;
      
     if(x2<left)
      code2 = code2|0x0001;
     else if(x2>right)
      code2 = code2|0x0010;
     if(y2<top)
      code2 = code2|0x1000;
     else if(y2>bottom)
      code2 = code2|0x0100; 
      
     return 1; 
  }
  
  int drawToViewportLine(float x1, float y1, float x2, float y2)
  {
      if(drawToViewportFlag<=0)
        return 0;
      float xv1, yv1, xv2, yv2, sx, sy;
      
      sx = (right_v - left_v)/(right - left);
      sy = (bottom_v - top_v)/(bottom - top);
      
      xv1 = left_v + (x1 - left)*sx;
      yv1 = top_v + (y1 - top)*sy;
      
      xv2 = left_v + (x2 - left)*sx;
      yv2 = top_v + (y2 - top)*sy;
      
      //setcolor(9);
      line(xv1, yv1, xv2, yv2);
      return 1;
  }
  
  int clipLine(float x1, float y1, float x2, float y2)
  {
      code1 = 0x0000;
      code2 = 0x0000;
      
      encode(x1, y1, x2, y2);
    
      if((code1|code2)==0x0000)    // trivially acceptable lines
       {
         if(drawToViewportFlag == 1)
         {        
           setcolor(10);       
           drawToViewportLine(x1, y1, x2, y2);
         }
         if(drawToViewportFlag > 1)
          return 1;  
         setcolor(GREEN);
         line(ROUND(x1), ROUND(y1), ROUND(x2), ROUND(y2));
         return 1;
       }
       
      if((code1&code2)!=0x0000)    // trivally rejectable lines
      {
        //setcolor(BLUE);
        //line(x1, y1, x2, y2);
        return 1;
      }
      
      // for CODE1
      if((code1|0x0001)==code1)    // left
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        ytemp = y1 + m*(left - x1);
        x1 = left;
        y1 = ytemp;
        encode(x1, y1, x2, y2);
      }
      if((code1|0x0010)==code1)    // right
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        ytemp = y1 + m*(right - x1);
        x1 = right;
        y1 = ytemp;
        encode(x1, y1, x2, y2);
      }
      if((code1|0x0100)==code1)    // bottom
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        xtemp = x1 + (bottom - y1)/m;
        x1 = xtemp;
        y1 = bottom;
        encode(x1, y1, x2, y2);
      }
      if((code1|0x1000)==code1)    // top
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        xtemp = x1 + (top - y1)/m;
        x1 = xtemp;
        y1 = top;
        encode(x1, y1, x2, y2);
      }
      // for CODE2
      if((code2|0x0001)==code2)    // left
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        ytemp = y2 + m*(left - x2);
        x2 = left;
        y2 = ytemp;
        encode(x1, y1, x2, y2);
      }
      if((code2|0x0010)==code2)    // right
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        ytemp = y2 + m*(right - x2);
        x2 = right;
        y2 = ytemp;
        encode(x1, y1, x2, y2);
      }
      if((code2|0x0100)==code2)    // bottom
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        xtemp = x2 + (bottom - y2)/m;
        x2 = xtemp;
        y2 = bottom;
        encode(x1, y1, x2, y2);
      }
      if((code2|0x1000)==code2)    // top
      {
        float xtemp, ytemp, m;
        m = (y2 - y1)/(x2 - x1);
        xtemp = x2 + (top - y2)/m;
        x2 = xtemp;
        y2 = top;
        encode(x1, y1, x2, y2);
      }
      
      clipLine(x1, y1, x2, y2);
      return 1;
  }
}drawWindow;



int setDrawWindow(Window w1)
{
    drawWindow.left = w1.left;
    drawWindow.right = w1.right;
    drawWindow.bottom = w1.bottom;
    drawWindow.top = w1.top;
    
    return 1;
}

int setViewport(Window v1)
{
    drawWindow.left_v = v1.left;
    drawWindow.right_v = v1.right;
    drawWindow.bottom_v = v1.bottom;
    drawWindow.top_v = v1.top;
    drawWindow.drawToViewportFlag = 1;
    return 1;
}

int unsetViewport()
{
    drawWindow.drawToViewportFlag = 0;
}

class Vertex3D
{
      public:
      float x;
      float y;
      float z;
      int color;
      
      Vertex3D()
      {
       x = 0;
       y = 0;
       z = 0;
       color = GREEN;
      }
      
      Vertex3D(float a, float b, float c)
      {
       x = a;
       y = b;
       z = c;
       color = GREEN;
      }
};

void putpixel3D(Vertex3D v1)
{
     float xp, yp;

     xp = (v1.x)*(zvp/v1.z);
     yp = (v1.y)*(zvp/v1.z);
     putpixel(xp+xc, yp+yc, v1.color);
}

void putpixel3D(float x, float y, float z, int c)
{
     float xp, yp;
     
     int color;
     color = c;
     
     xp = (x*(zvp/z));
     yp = (y*(zvp/z));
     putpixel(xp+xc, yp+yc, color);

}

void line3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
     float xp1, yp1, xp2, yp2;
      
     xp1 = (x1)*(zvp/z1);
     yp1 = (y1)*(zvp/z1);
     
     xp2 = (x2)*(zvp/z2);
     yp2 = (y2)*(zvp/z2);
     
     //drawWindow.clipLine(xp1+xc, yp1+yc, xp2+xc, yp2+yc);
     /*
     xp1 = (x1)+z1*cos(0*(180/M_PI));
     yp1 = (y1)+z1*sin(0*(180/M_PI));
     
     xp2 = (x2)+z2*cos(0*(180/M_PI));
     yp2 = (y2)+z2*sin(0*(180/M_PI));
     */
     drawWindow.clipLine(xp1+xc, yp1+yc, xp2+xc, yp2+yc);
}

class MeshGrid
{
      public:
      Vertex3D *v;
      int rows;
      int columns;
      
      MeshGrid()
      {}
      
      MeshGrid(int a, int b)
      {
       rows = a;
       columns = b;
       int i;
       int j;
       v = new Vertex3D[rows*columns];
       for(i=0 ; i<rows ; i++)
        for(j=0 ; j<columns ; j++)
         v[i*columns+j].x=0, v[i*columns+j].y=0, v[i*columns+j].z=0, v[i*columns+j].color=GREEN;
      }
      
      int setVertex(float x1, float y1, float z1, int a, int b)
      {
          if(a>=rows || b>=columns)
           return 0;
          v[a*columns+b].x = x1;
          v[a*columns+b].y = x1;
          v[a*columns+b].z = x1;
          return 1;
      }
      
      int setVertex(float x1, float y1, float z1, int c, int a, int b)
      {
          if(a>=rows || b>=columns)
           return 0;
          v[a*columns+b].color = c;
          setVertex(x1,y1,z1,a,b);
      }
      
      int setVertexColor(int c, int a, int b)
      {
          if(a>=rows || b>=columns)
           return 0;
          v[a*columns+b].color = c;
      }
};

class Terrain
{
 public:
 MeshGrid* m1;
 
 // constructors
 Terrain()
 {}
 
 Terrain(int a, int b)
 {
  m1 = new MeshGrid(a, b);
 }
 
 // methods for setting the home vertex
 int setHomeVertex(float x1, float y1, float z1)      // sets the world reference point of the terrain
 {
     m1->v[0].x = x1;
     m1->v[0].y = y1;
     m1->v[0].z = z1;
     return 1;
 }
 
 int setHomeVertex(Vertex3D v1)      // sets the world reference point of the terrain
 {
     m1->v[0].x = v1.x;
     m1->v[0].y = v1.y;
     m1->v[0].z = v1.z;
     return 1;
 }
 
 // methods for defining individual values of the meshgrid vertices, to define the terrain
 int createTerrainPlain(Vertex3D v1, float a, float b)
 {
     int i, j;
     float xtemp, ztemp;
     float ytemp;
     
     // setHomeVertex(v1);
     
     xtemp = v1.x;
     ztemp = v1.z;
     ytemp = v1.y;
     

     
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
         m1->v[i*m1->columns+j].y = ytemp;
         
         m1->v[i*m1->columns+j].x = xtemp;
         m1->v[i*m1->columns+j].z = ztemp;

         xtemp+=a;
        }
       ztemp+=b;
       xtemp = m1->v[0].x;
      }
     plotTerrain();
     return 1;
 }
 
 int randomizeTerrainY(float y1, float y2)
 {
     int i,j;
     float ytemp;
     
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          ytemp = (rand()%(int)y1)+y1;
          m1->v[i*m1->columns+j].y+=ytemp;
       }
     }
     
     return 1;
 }
 
 // transformations on the terrain
 int moveTo(float tx, float ty, float tz)
 {
     int i,j;
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          m1->v[i*m1->columns+j].x+=tx;
          m1->v[i*m1->columns+j].y+=ty;
          m1->v[i*m1->columns+j].z+=tz;
       }
     }
     return 1;
 }
 
 int translateX(float tx)
 {
     int i,j;
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          m1->v[i*m1->columns+j].x+=tx;
       }
     }
     return 1;
 }
 
 int translateY(float ty)
 {
     int i,j;
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          m1->v[i*m1->columns+j].y+=ty;
       }
     }
     return 1;
 }
 
 int translateZ(float tz)
 {
     int i,j;
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          m1->v[i*m1->columns+j].z+=tz;
       }
     }
     return 1;
 }
 
 // rotations
 int rotateY(int theta)
 {
     int i,j;
     float ytemp, ztemp, xtemp, xt, zt, yt;
     float rad;
     rad = theta*(3.1415/180);
     
     zt = m1->v[0].z; 
     xt = m1->v[0].x;
     yt = m1->v[0].y;
     
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          //if(j==0 && i==0)     continue;
          m1->v[i*m1->columns+j].z = m1->v[i*m1->columns+j].z - zt;
          m1->v[i*m1->columns+j].x = m1->v[i*m1->columns+j].x - xt;     
          m1->v[i*m1->columns+j].y = m1->v[i*m1->columns+j].y - yt;
          
          xtemp = m1->v[i*m1->columns+j].x*cos(rad) + m1->v[i*m1->columns+j].z*sin(rad);
          ztemp = -m1->v[i*m1->columns+j].x*sin(rad) + m1->v[i*m1->columns+j].z*cos(rad);
          ytemp = m1->v[i*m1->columns+j].y;
          
          m1->v[i*m1->columns+j].x = xtemp;
          m1->v[i*m1->columns+j].z = ztemp;
          m1->v[i*m1->columns+j].y = ytemp;
          
          m1->v[i*m1->columns+j].z = m1->v[i*m1->columns+j].z + zt;
          m1->v[i*m1->columns+j].x = m1->v[i*m1->columns+j].x + xt;     
          m1->v[i*m1->columns+j].y = m1->v[i*m1->columns+j].y + yt;
       }
     }
     return 1;
 }
 
 int rotateX(int theta)
 {
     int i,j;
     float ytemp, ztemp, xt, zt, yt;
     float rad;
     rad = theta*(3.1415/180);
     
     zt = m1->v[0].z; 
     xt = m1->v[0].x;
     yt = m1->v[0].y;
     
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          //if(j==0 && i==0)     continue;
          m1->v[i*m1->columns+j].z = m1->v[i*m1->columns+j].z - zt;
          m1->v[i*m1->columns+j].x = m1->v[i*m1->columns+j].x - xt;     
          m1->v[i*m1->columns+j].y = m1->v[i*m1->columns+j].y - yt;
          
          ytemp = m1->v[i*m1->columns+j].y*cos(rad) - m1->v[i*m1->columns+j].z*sin(rad);
          ztemp = m1->v[i*m1->columns+j].y*sin(rad) + m1->v[i*m1->columns+j].z*cos(rad);
          
          m1->v[i*m1->columns+j].z = ztemp;
          m1->v[i*m1->columns+j].y = ytemp;
          
          m1->v[i*m1->columns+j].z = m1->v[i*m1->columns+j].z + zt;
          m1->v[i*m1->columns+j].x = m1->v[i*m1->columns+j].x + xt;     
          m1->v[i*m1->columns+j].y = m1->v[i*m1->columns+j].y + yt;
       }
     }
     return 1;
 }
 
 int rotateZ(int theta)
 {
     int i,j;
     float ytemp, ztemp, xtemp, xt, zt, yt;
     float rad;
     rad = theta*(3.1415/180);
     
     zt = m1->v[2].z; 
     xt = m1->v[2].x;
     yt = m1->v[2].y;
     
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
          //if(j==0 && i==0)     continue;
          m1->v[i*m1->columns+j].z = m1->v[i*m1->columns+j].z - zt;
          m1->v[i*m1->columns+j].x = m1->v[i*m1->columns+j].x - xt;     
          m1->v[i*m1->columns+j].y = m1->v[i*m1->columns+j].y - yt;
          
          xtemp = m1->v[i*m1->columns+j].x*cos(rad) - m1->v[i*m1->columns+j].y*sin(rad);
          ytemp = m1->v[i*m1->columns+j].x*sin(rad) + m1->v[i*m1->columns+j].y*cos(rad);
          
          m1->v[i*m1->columns+j].x = xtemp;
          m1->v[i*m1->columns+j].y = ytemp;
          
          m1->v[i*m1->columns+j].z = m1->v[i*m1->columns+j].z + zt;
          m1->v[i*m1->columns+j].x = m1->v[i*m1->columns+j].x + xt;     
          m1->v[i*m1->columns+j].y = m1->v[i*m1->columns+j].y + yt;
       }
     }
     return 1;
 }
 
 int alterVertex(int row1, int col1, float x1, float y1, float z1)
 {
     if(row1>m1->rows || col1>m1->columns)
       return 0;
     
     m1->v[row1*m1->columns+col1].x = x1;
     m1->v[row1*m1->columns+col1].y = y1;
     m1->v[row1*m1->columns+col1].z = z1;
     return 1;
 }
 
 int alterVertex(int row1, int col1, Vertex3D v1)
 {
     if(row1>m1->rows || col1>m1->columns)
       return 0;
     
     m1->v[row1*m1->columns+col1].x = v1.x;
     m1->v[row1*m1->columns+col1].y = v1.y;
     m1->v[row1*m1->columns+col1].z = v1.z;
     m1->v[row1*m1->columns+col1].color = v1.color;
     return 1;
 }
 
 int alterVertexX(int row1, int col1, float x1)
 {
     if(row1>m1->rows || col1>m1->columns)
       return 0;
     
     m1->v[row1*m1->columns+col1].x += x1;

     return 1;
 }
 
 int alterVertexY(int row1, int col1, float y1)
 {
     if(row1>m1->rows || col1>m1->columns)
       return 0;
     
     m1->v[row1*m1->columns+col1].y += y1;

     return 1;
 }
 
 int alterVertexZ(int row1, int col1, float z1)
 {
     if(row1>m1->rows || col1>m1->columns)
       return 0;
     
     m1->v[row1*m1->columns+col1].z += z1;
     
     return 1;
 }
  
 // method to plot the vertices of the terrain
 int plotTerrain()
 {
     int i,j;
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns ; j++)
       {
         putpixel3D(m1->v[i*m1->columns+j].x, m1->v[i*m1->columns+j].y, m1->v[i*m1->columns+j].z, m1->v[i*m1->columns+j].color);
       }
     }
     return 1;
 }
 
 // method to draw the terrain's actual wiremesh
 int drawTerrain()
 {
     int i,j;
     // horizontal strips
     for(i=0 ; i<m1->rows ; i++)
     {
       for(j=0 ; j<m1->columns-1 ; j++)
       {
         line3D(m1->v[i*m1->columns+j].x,m1->v[i*m1->columns+j].y,m1->v[i*m1->columns+j].z,
                m1->v[i*m1->columns+j+1].x,m1->v[i*m1->columns+j+1].y,m1->v[i*m1->columns+j+1].z);
       }
     }
     
     // vertical strips
     for(i=0 ; i<m1->columns ; i++)
     {
       for(j=0 ; j<m1->rows-1 ; j++)
       {
         line3D(m1->v[j*m1->columns+i].x,m1->v[j*m1->columns+i].y,m1->v[j*m1->columns+i].z,
                m1->v[(j+1)*m1->columns+i].x,m1->v[(j+1)*m1->columns+i].y,m1->v[(j+1)*m1->columns+i].z);
       }
     }
     return 1;
 }
 
 ~Terrain()
 {
  delete m1;
 }
 
};

int main()
{
    initwindow(1018, 720);
    
    Window window1, viewport1;
    
    window1.initWindow(100, 100, 700, 500);
    viewport1.initWindow(720, 100, 1000, 600);
    
    setDrawWindow(window1);
    setViewport(viewport1);  // maps and draws content in current DrawWindow
        
    Terrain *t1;
    fstream saveFile;
    fstream loadFile;
       
    t1 = new Terrain(7, 7);
    
    Vertex3D v1(-20,8,1);
    t1->createTerrainPlain(v1, 1, 0.2);
    
    //Vertex3D v1(-20,8,2);
    //t1->createTerrainPlain(v1, 10, 12);
    
    t1->plotTerrain();
    t1->drawTerrain();
    
    putpixel3D(0, 0, 1, BLUE);
    getch();
    
    char c, ip;
    int ip1, ip2;
    float ipx, ipy, ipz;
    
    do{
       if(kbhit()==1)
       {
         c=getch();
         clearviewport();
         window1.drawWindow();
         viewport1.drawWindow();
       }
       switch(c)
       {
         case 'q':
              //t1->translateZ(-0.1);
              zvp++;
              break;
         case 'e':
              //t1->translateZ(+0.1);
              zvp--;
              break;
         case 'a':
              t1->translateX(-1);
              //xc--;
              break;
         case 'd':
              t1->translateX(+1);
              //xc++;
              break;
         case 'w':
              t1->translateY(-0.1);
              //yc--;
              break;
         case 's':
              t1->translateY(+0.1);
              //yc++;
              break;
         case 'z':
              //t1->moveTo(-10,0,0);
              //t1->rotateY(1);
              //t1->moveTo(0,10,0);
              break;
         case 'x':
              //t1->moveTo(10,0,0);
              t1->rotateX(10);
              //t1->moveTo(0,10,0);
              break;
         case 'c':
              //t1->moveTo(10,0,0);
              t1->rotateY(10);
              //t1->moveTo(0,10,0);
              break;
         case 'v':
              //t1->moveTo(10,0,0);
              t1->rotateZ(10);
              //t1->moveTo(0,10,0);
              break;
         case 'r':
              clearviewport();
              t1->drawTerrain();
              break;
         case 'o':
              do
              {
              printf("\nenter vertex index (row*col) : ");
              scanf("%d %d", &ip1, &ip2);
              printf("\nenter vertex coordinates : ");
              scanf("%f %f %f", &ipx, &ipy, &ipz);
              t1->alterVertex(ip1, ip2, ipx, ipy, ipz);
              printf("\n\ncontinue altering?y/n : ");
              scanf("%c", &c);
              clearviewport();
              t1->drawTerrain();
              }while(c!='n'); 
              break;
         case 'i':
              do
              {                
              printf("\nenter vertex index (row*col) : ");
              scanf("%d %d", &ip1, &ip2);
              printf("\nenter vertex Y displacement factor : ");
              scanf("%f", &ipy);
              t1->alterVertexY(ip1, ip2, ipy);
              
              clearviewport();
              t1->drawTerrain();
              
              printf("\n\ncontinue altering?y/n : ");
              scanf("%c", &ip);
              

              
              }while(ip!='n'); 
              printf("\nswitch to BGI window");
              break;
         case 'k':
              do
              {
              printf("\nenter vertex index (row*col) : ");
              scanf("%d %d", &ip1, &ip2);
              printf("\nenter vertex X displacement factor : ");
              scanf("%f", &ipx);
              t1->alterVertexX(ip1, ip2, ipx);
              printf("\n\ncontinue altering?y/n : ");
              scanf("%c", &c);
              clearviewport();
              t1->drawTerrain();
              }while(c!='n'); 
              break;
         case 'l':
              do
              {
              printf("\nenter vertex index (row*col) : ");
              scanf("%d %d", &ip1, &ip2);
              printf("\nenter vertex Z displacement factor : ");
              scanf("%f", &ipz);
              t1->alterVertexZ(ip1, ip2, ipz);
              printf("\n\ncontinue altering?y/n : ");
              scanf("%c", &c);
              clearviewport();
              t1->drawTerrain();
              }while(c!='n'); 
              break;
              
         // some preset maps : for minimum (10*10)
         case '1':
              t1->alterVertexY(3, 3, -0.2);
              t1->alterVertexY(3, 2, -0.3);
              t1->alterVertexY(3, 1, -0.1);
              t1->alterVertexY(3, 4, -1.2);
              t1->alterVertexY(4, 4, -1.3);
              t1->alterVertexY(4, 3, -0.9);
              t1->alterVertexY(4, 2, -1.2);
              t1->alterVertexY(4, 1, -1.5);
              t1->alterVertexY(5, 5, -1.7);
              break;
         
         case '2':
              t1->randomizeTerrainY(-2, 0.995);
              break;
         case '3':
              //delete t1->m1->v;
              //t1->m1->v = new Vertex3D[10*20];
              //printf("\nloading..");
//              loadFile.open("c://map1.dat", ios::in | ios::binary);
//              loadFile.seekg (0);
//              loadFile.read((char *)(t1->m1->v), sizeof(Vertex3D));
//              printf("\nloaded..");
//              t1->plotTerrain();
//              //t1->drawTerrain();
//              loadFile.close();
//              printf("\nclosed..");
              
              break;
         
       }
       
       t1->plotTerrain();
       t1->drawTerrain();
       
       if(c!='`') c='!';       // clearing input buffer
    }while(c!='`');
    
    //saveFile.open("c://map1.dat", ios::out | ios::binary);
//    if(saveFile.is_open())
//    {
//      printf("jhmmmmmmmm...");
//      saveFile.write((char *)(&t1->m1->v), sizeof(Vertex3D));
//      saveFile.close();
//    }
    
    getch();
    return 1;
}

