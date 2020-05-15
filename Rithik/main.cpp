#include<iostream>
#ifdef _WIN64
    #include<GL/glut.h>
#elif _WIN32
    #include<GL/glut.h>
#elif __APPLE__
    #include<GLUT/glut.h>
#endif
#include <stdlib.h>
#include <thread>



using namespace std::chrono;
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0,b=0.0;
float p=0.75,q=0.47,r=0.14;
float e=0.0,f=0.0,g=0.0;
int count=0;
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0,count6=0,caseA=0,count7=0;
int caseS=0,caseR=0;
int grow=0;
int count8=0,count9=0;
int count10=0;
int count11=1;
int harvest=0,harvesting_man=0,harvest_man=0;
int farming_man=0;
int sell=0;
int rot=0;
int rotfan=1;
int near_home=0;
int homeee=0;


int light=1,day=1,plane=0,comet=0,xm=900,bird=0,door=1,window=0,farm=0,walking_LR=0,walking_down=0,walking_RL=0;
char ch;

void draw_man(int cnt,int cnt1);
void draw_man1(int cnt,int cnt1);
void draw_man_LR(int cnt,int cnt1);
void draw_harvest_man(int xval,int yval,int cnt);
void draw_harvesting_man(int cnt);
void draw_farming_man(int cnt);
//void draw_near_home(int near_home);
void fan1(int spin);
void fan2(int spin);
void fan3(int spin);
void draw_sell();
void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}


void draw_circle(GLint h, GLint k, GLint r)
{
    GLint d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(d<0) d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}

void fanpole1()
{
    

    glColor3f(0.5,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(-350,185);
    glVertex2f(-325,185);
    glVertex2f(-325,500);
    glVertex2f(-350,500);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    for(int l=0;l<=20;l++)
    {
        draw_circle(-337.5,500,l);
    }
    glEnd();
}


void draw_farm(int num,int cnt)
{

    glColor3f(0.0,0.1,0.0);
    glBegin(GL_LINES);
    glVertex2f(210+((cnt)*50),-50-(num*50));
    glVertex2f(220+((cnt)*50),-40-(num*50));
    glVertex2f(225+((cnt)*50),-20-(num*50));
    glVertex2f(220+((cnt)*50),-40-(num*50));
    glVertex2f(225+((cnt)*50),-20-(num*50));
    glVertex2f(223+((cnt)*50),-20-(num*50));
    glVertex2f(220+((cnt)*50),-40-(num*50));
    glVertex2f(230+((cnt)*50),-60-(num*50));
    glVertex2f(230+((cnt)*50),-60-(num*50));
    glVertex2f(233+((cnt)*50),-60-(num*50));
    glEnd();
}





void draw_grow(int num,int cnt)
{
        glColor3f(1.0,1.0,0.0);
        glBegin(GL_LINES);
        glVertex2f(210+((cnt)*50),-50-(num*50));
        glVertex2f(220+((cnt)*50),-40-(num*50));
        glVertex2f(225+((cnt)*50),-20-(num*50));
        glVertex2f(220+((cnt)*50),-40-(num*50));
        glVertex2f(225+((cnt)*50),-20-(num*50));
        glVertex2f(223+((cnt)*50),-20-(num*50));
        glVertex2f(220+((cnt)*50),-40-(num*50));
        glVertex2f(230+((cnt)*50),-60-(num*50));
        glVertex2f(230+((cnt)*50),-60-(num*50));
        glVertex2f(233+((cnt)*50),-60-(num*50));
        glEnd();
}

void draw_harvest(int num,int cnt)
{
    glColor3f(0.3,0.3,0.0);
    glBegin(GL_LINES);
    glVertex2f(1060-((cnt-1)*50),-50-(num*50));
    glVertex2f(1070-((cnt-1)*50),-40-(num*50));
    glVertex2f(1075-((cnt-1)*50),-20-(num*50));
    glVertex2f(1070-((cnt-1)*50),-40-(num*50));
    glVertex2f(1075-((cnt-1)*50),-20-(num*50));
    glVertex2f(1073-((cnt-1)*50),-20-(num*50));
    glVertex2f(1070-((cnt-1)*50),-40-(num*50));
    glVertex2f(1080-((cnt-1)*50),-60-(num*50));
    glVertex2f(1080-((cnt-1)*50),-60-(num*50));
    glVertex2f(1083-((cnt-1)*50),-60-(num*50));
    glEnd();
    
}
void draw_store(int num,int cnt)
{
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
    glVertex2f((-250+(i)*10),-350+(10*(cnt)));
    glVertex2f((-250+(i)*10),-360+(10*(cnt)));
    glEnd();
}
void draw_sell(int num,int cnt)
{
    glColor3f(0.3,0.3,0.0);
    glBegin(GL_LINES);
    glVertex2f((-250+(num)*10),-350+(10*(cnt)));
    glVertex2f((-250+(num)*10),-360+(10*(cnt)));
    glEnd();
    
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(-500,160);
glVertex2f(-500,700);
glVertex2f(1100,700);
glVertex2f(1100,160);
glEnd();

//sun


    for(l=0;l<=35;l++)
{
        glColor3f(1.0,0.9,0.0);
        draw_circle(100,625,l);
}


//plane
if(plane==1)
{
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(925+n,625+o);
glVertex2f(950+n,640+o);
    glVertex2f(1015+n,640+o);
    glVertex2f(1030+n,650+o);
    glVertex2f(1050+n,650+o);
    glVertex2f(1010+n,625+o);
glEnd();

    glColor3f(0.8,0.8,0.8);
    glBegin(GL_LINE_LOOP);
    glVertex2f(925+n,625+o);
glVertex2f(950+n,640+o);
    glVertex2f(1015+n,640+o);
    glVertex2f(1030+n,650+o);
    glVertex2f(1050+n,650+o);
    glVertex2f(1010+n,625+o);
glEnd();

}

//cloud1


    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(160+m,625,l);
    }


    for(l=0;l<=35;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(200+m,625,l);
        draw_circle(225+m,625,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(265+m,625,l);
    }

//cloud2


    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(370+m,615,l);
    }




    for(l=0;l<=35;l++)
    {

        glColor3f(1.0,1.0,1.0);
        draw_circle(410+m,615,l);
        draw_circle(435+m,615,l);
        draw_circle(470+m,615,l);
    }

for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(500+m,615,l);
}

//cloud3


    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(-270+m,615,l);
    }




    for(l=0;l<=35;l++)
    {

        glColor3f(1.0,1.0,1.0);
        draw_circle(-310+m,615,l);
        draw_circle(-335+m,615,l);
        draw_circle(-370+m,615,l);
    }

for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(-400+m,615,l);
}






//grass
glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(-500,185);
glVertex2f(-170,380);
//glVertex2f(1,380);
glVertex2f(300,160);
glEnd();

glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(200,180);
glVertex2f(470,380);
//glVertex2f(300,160);
glVertex2f(1100,160);
glEnd();

}





else
{

//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-500,160);
glVertex2f(-500,700);
glVertex2f(1100,700);
glVertex2f(1100,160);
glEnd();

//moon
int l;

    for(l=0;l<=35;l++)
    {
        glColor3f(1.0,1.0,1.0);
        glPushMatrix();
        glRotatef(360,0,0,l);
        draw_circle(100,625,l);
        glPopMatrix();
    }

//star1

glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();

//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();

//star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();

//star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();

//star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

//star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();

//star7
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(100,528);
glVertex2f(95,520);
glVertex2f(105,520);
glVertex2f(100,518);
glVertex2f(95,525);
glVertex2f(105,525);
glEnd();

//star8
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(300,468);
glVertex2f(295,460);
glVertex2f(305,460);
glVertex2f(300,458);
glVertex2f(295,465);
glVertex2f(305,465);
glEnd();

//star9
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(500,543);
glVertex2f(495,535);
glVertex2f(505,535);
glVertex2f(500,532);
glVertex2f(495,540);
glVertex2f(505,540);
glEnd();

//star10
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(-165,543);
glVertex2f(-160,535);
glVertex2f(-170,535);
glVertex2f(-165,532);
glVertex2f(-160,540);
glVertex2f(-170,540);
glEnd();

//star11
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(-365,628);
glVertex2f(-360,620);
glVertex2f(-370,620);
glVertex2f(-365,618);
glVertex2f(-360,625);
glVertex2f(-370,625);
glEnd();

//star11
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(-50,628);
glVertex2f(-45,620);
glVertex2f(-55,620);
glVertex2f(-50,618);
glVertex2f(-45,625);
glVertex2f(-55,625);
glEnd();


//comet
if(comet==1)
{
    for(l=0;l<=7;l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(300+c,675,l);
    }

glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(200+c,675);
    glVertex2f(300+c,682);
    glVertex2f(300+c,668);
    glEnd();
}

//Plane
if(plane==1)
{

    for(l=0;l<=1;l++)
    {
        glColor3f(1.0,0.0,0.0);
        draw_circle(950+n,625+o,l);
        glColor3f(1.0,1.0,0.0);
        draw_circle(954+n,623+o,l);

    }



}

//grass
glColor3f(0.0,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(-500,185);
glVertex2f(-170,380);
//glVertex2f(1,380);
glVertex2f(300,160);
glEnd();

glColor3f(0.0,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(200,180);
glVertex2f(470,380);
//glVertex2f(300,160);
glVertex2f(1100,160);
glEnd();

}

//Farm border
glColor3f(0.3,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-500,0);
glVertex2f(-500,-20);
glVertex2f(1100,0);
glVertex2f(1100,-20);
glEnd();


glColor3f(0.3,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(150,-10);
glVertex2f(165,-10);
glVertex2f(150,-500);
glVertex2f(165,-500);
glEnd();

//Farm grass
glColor3f(0.3,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(-500,-500);
glVertex2f(-500,-10);
glVertex2f(150,-10);
glVertex2f(150,-500);
glEnd();

glColor3f(0.3,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(155,-500);
glVertex2f(155,-10);
glVertex2f(1100,-10);
glVertex2f(1100,-500);
glEnd();


//Farm
for(i=0;i<9;i++)
{
    
    if(farm==1)
    {
        int sim=1;
        
        while(sim<=count2)
        {
            draw_farm(i,sim);
            sim=sim+1;
        }
    }
}

    
for(i=0;i<9;i++)
{
    for(int sim=1;sim<18;sim++)
    {
        glColor3f(1.0,0.0,0.0);
        draw_circle(210+(sim*50),-50-(i*50),10);

    }
}
    

for(i=0;i<9;i++)
{
    
    if(grow==1)
    {
        int sim=1;
        if(count7<18)
        {
                while(sim<=count7)
            {
                draw_grow(i,sim);
                sim=sim+1;
            }
        }
    }
}
    
for(i=0;i<9;i++)
{
    
    if(harvest==1)
    {
        int sim=1;
        while(sim<=count10)
        {
            draw_harvest(i,sim);
            if(count10<17)
            {
                draw_store(i,sim);
            }
            else if(count10>=17)
            {
                int sim1=1;
                while(sim1<=17)
                {
                   draw_store(i,sim1);
                    sim1=sim1+1;
                }
            }
            sim=sim+1;
        }
    }
}

//Ground
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(-500,0);
glVertex2f(-500,185);
glVertex2f(1100,185);
glVertex2f(1100,0);
glEnd();


//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(280,185);
glVertex2f(280,255);
glVertex2f(295,255);
glVertex2f(295,185);
glEnd();


    for(l=0;l<=30;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(270,250,l);
        draw_circle(310,250,l);
    }

    for(l=0;l<=25;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(280,290,l);
        draw_circle(300,290,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(290,315,l);
    }


//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,135);
glVertex2f(100,285);
glVertex2f(140,285);
glVertex2f(140,135);
glEnd();


    for(l=0;l<=40;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(40,280,l);
        draw_circle(90,280,l);
        draw_circle(150,280,l);
        draw_circle(210,280,l);
        draw_circle(65,340,l);
        draw_circle(115,340,l);
        draw_circle(175,340,l);

    }

    for(l=0;l<=55;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(115,360,l);


    }
//tree2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(-175,185);
glVertex2f(-175,255);
glVertex2f(-160,255);
glVertex2f(-160,185);
glEnd();


    for(l=0;l<=30;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(-185,250,l);
        draw_circle(-145,250,l);
    }
//
    for(l=0;l<=25;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(-175,290,l);
        draw_circle(-155,290,l);
    }
//
    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
        draw_circle(-165,315,l);
    }

     //chim

    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

        glVertex2f(540,330);
        glVertex2f(540,430);
        glVertex2f(960,430);
        glVertex2f(960,330);

    glEnd();

    //home

    glColor3f(p,q,r);
    glBegin(GL_POLYGON);

        glVertex2f(550,100);
        glVertex2f(550,330);
        glVertex2f(950,330);
        glVertex2f(950,100);
        glVertex2f(650,100);
        glVertex2f(650,250);
        glVertex2f(650,250);
        glVertex2f(650,100);

    glEnd();

    //window border

    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

        glVertex2f(595,205);
        glVertex2f(595,285);
        glVertex2f(675,285);
        glVertex2f(675,205);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(825,205);
        glVertex2f(825,285);
        glVertex2f(905,285);
        glVertex2f(905,205);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(845,205);
        glVertex2f(845,285);
        glVertex2f(850,285);
        glVertex2f(850,205);

    glEnd();



    //door
    glColor3f(e,f,g);
    glBegin(GL_POLYGON);

        glVertex2f(800,100);
        glVertex2f(800,220);
        glVertex2f(700,220);
        glVertex2f(700,100);

    glEnd();

    if(door==1)
    {
        glColor3f(0.35,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(800,100);
        glVertex2f(800,220);
        glVertex2f(700,220);
        glVertex2f(700,100);
        glEnd();

    }
    else if(door==0)
    {
        glColor3f(0.35,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(760,120);
        glVertex2f(760,200);
        glVertex2f(700,220);
        glVertex2f(700,100);
        glEnd();
    }



    //window
    if(window==0)
    {
        glColor3f(e,f,g);
        glBegin(GL_POLYGON);

            glVertex2f(600,210);
            glVertex2f(600,280);
            glVertex2f(670,280);
            glVertex2f(670,210);

        glEnd();
    }

    glBegin(GL_POLYGON);

        glVertex2f(830,210);
        glVertex2f(830,280);
        glVertex2f(900,280);
        glVertex2f(900,210);

    glEnd();

    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

        glVertex2f(620,210);
        glVertex2f(620,280);
        glVertex2f(625,280);
        glVertex2f(625,210);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(650,210);
        glVertex2f(650,280);
        glVertex2f(655,280);
        glVertex2f(655,210);

    glEnd();



    glColor3f(0.35,0.0,0.0);
    glBegin(GL_POLYGON);

        glVertex2f(850,205);
        glVertex2f(850,285);
        glVertex2f(855,285);
        glVertex2f(855,205);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(880,205);
        glVertex2f(880,285);
        glVertex2f(885,285);
        glVertex2f(885,205);

    glEnd();


    if(bird==1)
    {
    /*glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

        glVertex2f(300+i-xm,250+b);
        glVertex2f(330+i-xm,250+b);
        glVertex2f(330+i-xm,280+b);


    glEnd();*/

    glColor3f(0.73,0.16,0.96 );
    glBegin(GL_POLYGON);

        glVertex2f(300+i-xm,265+b);
        glVertex2f(330+i-xm,265+b);
        glVertex2f(330+i-xm,250+b);


    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(330+i-xm,275+b);
        glVertex2f(340+i-xm,275+b);
        glVertex2f(330+i-xm,265+b);


    glEnd();

    //

    glBegin(GL_POLYGON);

        glVertex2f(200+i-xm,285+b);
        glVertex2f(230+i-xm,285+b);
        glVertex2f(230+i-xm,270+b);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(230+i-xm,295+b);
        glVertex2f(240+i-xm,295+b);
        glVertex2f(230+i-xm,285+b);


    glEnd();


    //

    glBegin(GL_POLYGON);

        glVertex2f(150+i-xm,285+b);
        glVertex2f(180+i-xm,285+b);
        glVertex2f(180+i-xm,270+b);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex2f(180+i-xm,295+b);
        glVertex2f(190+i-xm,295+b);
        glVertex2f(180+i-xm,285+b);


    glEnd();


}
    if(walking_RL==1)
    {
        draw_man(count3,count4);
    }
    if(walking_down==1)
    {
        draw_man1(count5,count6);
    }
    if(farming_man==1)
    {
        draw_farming_man(count8);
    }
    if(walking_LR==1)
    {
        draw_man_LR(count8,count9);
    }
    if(harvest_man==1)
    {
        int xval=-1200;
        int yval=-80;
        draw_harvest_man(xval,yval,count10);
    }
    if(harvesting_man==1)
    {
        draw_harvesting_man(count11);
    }
    if(sell==1)
    {
        for(int l=0;l<=9;l++)
        {
            int sim1=1;
            while(sim1<=17)
            {
                draw_sell(l,sim1);
                sim1=sim1+1;
            }
        }
    }
    //Fan
    fanpole1();
    fan1(rot);
    fan2(rot);
    fan3(rot);
    
    if(near_home==1)
    {
        int xval=-300;
        int yval=350;
        draw_harvest_man(xval,yval,near_home);
        
    }
    
    if(count3>0 && homeee==1)
    {
        near_home=0;
    }
    
        

    


glFlush();
}
void draw_harvesting_man(int cnt)
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    for(int l=0;l<=10;l++)
    {
        draw_circle(1060-((cnt-1)*50),-220,l);
    }
    glBegin(GL_LINES);
    glVertex2f(1060-((cnt-1)*50),-230);//Back part
    glVertex2f(1060-((cnt-1)*50),-260);
    glVertex2f(1060-((cnt-1)*50),-260);
    glVertex2f(1065-((cnt-1)*50),-280);
    glVertex2f(1060-((cnt-1)*50),-260);
    glVertex2f(1055-((cnt-1)*50),-280);
    glVertex2f(1060-((cnt-1)*50),-230);//Hand
    glVertex2f(1065-((cnt-1)*50),-250);
    glVertex2f(1060-((cnt-1)*50),-230);//Front hand
    glVertex2f(1055-((cnt-1)*50),-250);
    glEnd();
    glPopMatrix();

}
void draw_farming_man(int cnt)
{
    if(cnt<17)
    {
        glColor3f(1.0,1.0,1.0);
        glPushMatrix();
        glTranslatef(0,0,0);
        for(int l=0;l<=10;l++)
        {
            draw_circle(210+((cnt)*50),-220,l);
        }
        glBegin(GL_LINES);
        glVertex2f(210+((cnt)*50),-230);//Back part
        glVertex2f(210+((cnt)*50),-260);
        glVertex2f(210+((cnt)*50),-260);
        glVertex2f(215+((cnt)*50),-280);
        glVertex2f(210+((cnt)*50),-260);
        glVertex2f(205+((cnt)*50),-280);
        glVertex2f(210+((cnt)*50),-230);//Hand
        glVertex2f(215+((cnt)*50),-250);
        glVertex2f(210+((cnt)*50),-230);//Front hand
        glVertex2f(205+((cnt)*50),-250);
        glEnd();
        glPopMatrix();
    }
    else if(cnt>=17)
    {
        glColor3f(1.0,1.0,1.0);
        glPushMatrix();
        glTranslatef(0,0,0);
        for(int l=0;l<=10;l++)
        {
            draw_circle(1060,-220,l);
        }
        glBegin(GL_LINES);
        glVertex2f(1060,-230);//Back part
        glVertex2f(1060,-260);
        glVertex2f(1060,-260);
        glVertex2f(1065,-280);
        glVertex2f(1060,-260);
        glVertex2f(1055,-280);
        glVertex2f(1060,-230);//Hand
        glVertex2f(1065,-250);
        glVertex2f(1060,-230);//Front hand
        glVertex2f(1055,-250);
        glEnd();
        glPopMatrix();
        
    }

}
void draw_harvest_man(int xval,int yval,int cnt)
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(xval+((cnt-1)*50),yval+(cnt-1)*5,0.0);
    for(int l=0;l<=10;l++)
    {
        draw_circle(1060-((cnt-1)*50),-220,l);
    }
    glBegin(GL_LINES);
    glVertex2f(1060-((cnt-1)*50),-230);//Back part
    glVertex2f(1060-((cnt-1)*50),-260);
    glVertex2f(1060-((cnt-1)*50),-260);
    glVertex2f(1065-((cnt-1)*50),-280);
    glVertex2f(1060-((cnt-1)*50),-260);
    glVertex2f(1055-((cnt-1)*50),-280);
    glVertex2f(1060-((cnt-1)*50),-230);//Hand
    glVertex2f(1065-((cnt-1)*50),-250);
    glVertex2f(1060-((cnt-1)*50),-230);//Front hand
    glVertex2f(1055-((cnt-1)*50),-250);
    glEnd();
    glPopMatrix();
}

//void draw_near_home(int cnt)
//{
//    glColor3f(1,1,1);
//    glPushMatrix();
//    glTranslatef(1200+((cnt-1)*50),80+(cnt-1)*5,0.0);
//    for(int l=0;l<=10;l++)
//    {
//        draw_circle(2000,0,l);
//    }
//    glBegin(GL_LINES);
//    glVertex2f(1060-((cnt-1)*50),-230);//Back part
//    glVertex2f(1060-((cnt-1)*50),-260);
//    glVertex2f(1060-((cnt-1)*50),-260);
//    glVertex2f(1065-((cnt-1)*50),-280);
//    glVertex2f(1060-((cnt-1)*50),-260);
//    glVertex2f(1055-((cnt-1)*50),-280);
//    glVertex2f(1060-((cnt-1)*50),-230);//Hand
//    glVertex2f(1065-((cnt-1)*50),-250);
//    glVertex2f(1060-((cnt-1)*50),-230);//Front hand
//    glVertex2f(1055-((cnt-1)*50),-250);
//    glEnd();
//    glPopMatrix();
//
//}

void draw_man(int cnt,int cnt1)
{
        glPushMatrix();
        int x1=cnt1,a1=cnt1;

        if(cnt1>=570 && caseS==1)
        {
            glColor3f(1.0,1.0,1.0);
            for(int l=0;l<=10;l++)
            {
                    draw_circle(180,110,l);
            }
            glBegin(GL_LINES);
            glVertex2f(180,100);//Back part
            glVertex2f(180,70);
            glVertex2f(180,70.0);
            glVertex2f(185,50.0);
            glVertex2f(180,70.0);
            glVertex2f(175,50.0);
            glVertex2f(180,100);//Hand
            glVertex2f(185,80);
            glVertex2f(180,100);//Front hand
            glVertex2f(175,80);
            glEnd();

        }
        else if(cnt1<570 && caseS==1)
        {
            for(int jim=cnt;jim<cnt+1;jim++)
            {
                glColor3f(1.0,1.0,1.0);
                for(int l=0;l<=10;l++)
                {
                    draw_circle(750-x1,110,l);
                }
                glBegin(GL_LINES);
                glVertex2f(750-x1,100);//Back part
                glVertex2f(750-a1,70);
                glVertex2f(750-x1,70.0);
                glVertex2f(755-jim-a1,50.0);
                glVertex2f(750-x1,70.0);
                glVertex2f(745+jim-a1,50.0);
                glVertex2f(750-x1,100);//Hand
                glVertex2f(755-jim-a1,80);
                glVertex2f(750-x1,100);//Front hand
                glVertex2f(745+jim-a1,80);
                glEnd();
            }
            glPopMatrix();
        }

}

void draw_man1(int cnt,int cnt1)
{
        glPushMatrix();
        int x1=cnt1,a1=cnt1;
//        if(cnt1>=350 && (caseA==1 && caseS==0 && caseR==0) &&(count4>=570))
        if(cnt1>=350 && caseA==1)
        {
            glColor3f(1.0,1.0,1.0);
            for(int l=0;l<=10;l++)
            {
                draw_circle(180,-220,l);
            }
            glBegin(GL_LINES);
            glVertex2f(180,-230);//Back part
            glVertex2f(180,-260);
            glVertex2f(180,-260);
            glVertex2f(185,-280);
            glVertex2f(180,-260);
            glVertex2f(175,-280);
            glVertex2f(180,-230);//Hand
            glVertex2f(185,-250);
            glVertex2f(180,-230);//Front hand
            glVertex2f(175,-250);
            glEnd();

        }
        else if(cnt1<350 && caseA==1 && (count4>=570))
        {
            for(int jim=cnt;jim<cnt+1;jim++)
            {
                glColor3f(1.0,1.0,1.0);
                for(int l=0;l<=10;l++)
                {
                    draw_circle(180,110-x1,l);
                }
                glBegin(GL_LINES);
                glVertex2f(180,100-x1);//Back part
                glVertex2f(180,70-a1);
                glVertex2f(180,70.0-x1);
                glVertex2f(185,55.0-jim-a1);
                glVertex2f(180,70.0-x1);
                glVertex2f(175,45.0+jim-a1);
                glVertex2f(180,100-x1);//Hand
                glVertex2f(185,85-jim-a1);
                glVertex2f(180,100-x1);//Front hand
                glVertex2f(175,75+jim-a1);
                glEnd();
            }
            glPopMatrix();
        }
}

void draw_man_LR(int cnt,int cnt1)
{
        glPushMatrix();
        int x1=cnt1,a1=cnt1;

        if((cnt1>880 ) && (caseA==0 && caseS==0 && caseR==1) && (count6>=350))
        {

            glColor3f(1.0,1.0,1.0);
            draw_circle(1060,-220,10);
            glBegin(GL_LINES);
            glVertex2f(1060,-230);//Back part
            glVertex2f(1060,-260);
            glVertex2f(1060,-260);
            glVertex2f(1065,-280);
            glVertex2f(1060,-260);
            glVertex2f(1055,-280);
            glVertex2f(1060,-230);//Hand
            glVertex2f(1065,-250);
            glVertex2f(1060,-230);//Front hand
            glVertex2f(1055,-250);
            glEnd();

        }
        else if((cnt1<880) && (caseA==0 && caseS==0 && caseR==1) && (count6>=350))
        {
            for(int jim=cnt;jim<cnt+1;jim++)
            {
                glColor3f(1.0,1.0,1.0);
                draw_circle(180+x1,-220,10);
                glBegin(GL_LINES);
                glVertex2f(180+x1,-230);//Back part
                glVertex2f(180+a1,-260);
                glVertex2f(180+x1,-260);
                glVertex2f(185-jim+a1,-280);
                glVertex2f(180+x1,-260);
                glVertex2f(175+jim+a1,-280);
                glVertex2f(180+x1,-230);//Hand
                glVertex2f(185-jim+a1,-250);
                glVertex2f(180+x1,-230);//Front hand
                glVertex2f(175+jim+a1,-250);
                glEnd();
            }
            glPopMatrix();
        }

}

void fan1(int spin)
{
    glPushMatrix();
//    glLoadIdentity();
    glColor3f(1,1,1);
    glTranslatef (-337.5,500.0, 0.0);/*rotation about fixed point*/
    glRotatef(spin,0.0,0.0,1.0);
    glTranslatef(337.5,-500,0.0);
    glBegin(GL_POLYGON);/*1st fan*/
    glVertex2f(-460,510);
    glVertex2f(-460,490);
    glVertex2f(-337.5,500);
    glEnd();
    glPopMatrix();
}

void fan2(int spin)
{
    glPushMatrix();
//    glLoadIdentity();
    glColor3f(1,1,1);
    glTranslatef (-337.5,500.0, 0.0);/*rotation about fixed point*/
    glRotatef(spin,0.0,0.0,1.0);
    glTranslatef(337.5,-500,0.0);
    glBegin(GL_POLYGON);/*1st fan*/
    glVertex2f(-275,400);
    glVertex2f(-290,390);
    glVertex2f(-337.5,500);
    glEnd();
    glPopMatrix();
    
}

void fan3(int spin)
{
    glPushMatrix();
//    glLoadIdentity();
    glColor3f(1,1,1);
    glTranslatef (-337.5,500.0, 0.0);/*rotation about fixed point*/
    glRotatef(spin,0.0,0.0,1.0);
    glTranslatef(337.5,-500,0.0);
    glBegin(GL_POLYGON);/*1st fan*/
    glVertex2f(-275,590);
    glVertex2f(-290,600);
    glVertex2f(-337.5,500);
    glEnd();
    glPopMatrix();
    
}




void idle()
{

if(light==0 && (i>=0 && i<=1150))
 {

     i+=SPEED/10;
     m+=SPEED/150;
    n-=2;
     o+=0.2;
    c+=2;

 }

 if(light==0 && (i>=2600 && i<=3000))
 {

     i+=SPEED/10;
     m+=SPEED/150;
    n-=2;
     o+=0.2;
    c+=2;

 }

if(light==0)
 {
     i=i;
     m+=SPEED/150;
    n-=2;
     o+=0.2;
    c+=2;

 }
if(count<=3)
{

glClearColor(1.0,1.0,1.0,1.0);

     i+=SPEED/10;
     b+=SPEED/10;
     m+=SPEED/150;
    n-=2;
     o+=0.2;
    c+=2;
}
if(i>1900)
     i=800.0;
if(m>1100)
     m=0.0;
if( o>75)
 {
    plane=0;
 }
if(c>500)
 {
    comet=0;
 }
if(b>500)
{
    b=0.0;
    i=800.0;
    count=count+1;

}

glutPostRedisplay();

}


void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {

case 'd':
    case 'D':
        day=1;
        p=0.75;
        q=0.47;
        r=0.14;
        break;

    case 'n':
case 'N':
        day=0;
        p=0.52;
        q=0.37;
        r=0.26;
        break;

//    case 'b':
//case 'B':
//        bird=1;
//        i=800;
//        b=0.0;
//        count=0;
//        break;


        case 'l':
    case 'L':
        e=0.90;
        f=0.91;
        g=0.98;
        break;

        case 'f':
    case 'F':
        e=0.0;
        f=0.0;
        g=0.0;
        break;

        case 'x':
        case 'X':
            if(count3==0 && homeee==0)
            {
                if(count%2!=0)
                    door=1;
                else
                    door=0;
                count=count+1;
            }
            else if(count3>0 && homeee==0)
            {
                door=1;
            }
            else if(count3>0 && homeee==1)
            {
                if(count%2!=0)
                    door=1;
                else
                    door=0;
                count=count+1;
            }
            break;
        case 'w':
        case 'W':
            if(count3==0 && homeee==0)
            {
                if(count1%2!=0)
                    window=0;
                else
                    window=1;
                count1=count1+1;
            }
            else if(count3>0 && homeee==0)
            {
                window=0;
            }
            else if(count3>0 && homeee==1)
            {
                if(count1%2!=0)
                    window=0;
                else
                    window=1;
                count1=count1+1;
            }
//            if(count1%2!=0)
//                window=1;
//            else
//                window=0;
//            count1=count1+1;
            break;
        case 's':
        case 'S':
                count3=count3+1;
                count4=count4+1;
                if(count3==15)
                {
                    count3=0;
                }
                if(count5==0 || count4<=570)
                {
                    walking_RL=1;
                    caseS=1;
                }
            break;
            
        case 'a':
        case 'A':
            if(count4>=570)
            {
                count5=count5+1;
                count6=count6+1;
                if(count5==15)
                {
                    count5=0;
                }
                walking_down=1;
                caseA=1;
                caseS=0;
            }
            break;
        case 'z':
        case 'Z':
            if(count6>=350)
            {
                caseA=0;
                count8=count8+1;
                farming_man=1;
            }
            
            break;
            
        case 'r':
        case 'R':
            if(rot==360)
            {
                rot=0;
            }
            rot=rot+180;
            break;
        case 'q':
        case 'Q':
                harvest_man=0;
                harvest=1;
                count11=count10+1;
                harvesting_man=1;
            break;
        case 'v':
        case 'V':
            if(homeee==0)
            {
                harvest_man=0;
                near_home=1;
            }
            break;
            
        case 'h':
        case 'H':
            homeee=1;
            door=0;
            break;
        
        case 'm':
        case 'M':
            exit(0);
            break;

    };

}


void main_menu(int index)
{
    switch(index)
    {

    case 1:
    if(index==1)
     {
         if(count8>count2)
         {
             count2=count2+1;
             farm=1;
         }
     }
    break;
            
    case 2:
    if(index==2)
     {
         if(count7<count2)
         {
             count7=count7+1;
         }
         grow=1;
     }
    break;
    
    case 3:
    if(index==3)
     {
        count10=count10+1;
        if(count7>=17 && count11==count10)
        {
            farming_man=0;
            harvest_man=1;
            harvesting_man=0;
            harvest=1;
        }
         else if(count7>=17 && count10>count11)
         {
             count10=count11;
             farming_man=0;
             harvest_man=1;
             harvesting_man=0;
             harvest=1;
         }
     }
    break;
            
    case 4:
    if(index==4)
     {
         sell=1;
     }
    break;
    }
}



void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glLineWidth(5.0f);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0,1100.0,-500.0,700.0);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glFlush();
}


int main(int argc,char** argv)
{
int c_menu;
    std::cout<<("Insight into a farmer's life\n");

    std::cout<<("Press 'd' or 'D' to make it day. \n\n");
    std::cout<<("Press 'n' or 'N' to make it night. \n\n");
    std::cout<<("Press 'l' or 'L' to turn On the lights. \n\n");
    std::cout<<("Press 'f' or 'F' to turn Off the lights. \n\n");
    std::cout<<("Press 'x' or 'X' to close or open the door. \n\n");
    std::cout<<("Press 'w' or 'W' to close or open the window. \n\n");
    std::cout<<("Press 's' or 'S' to make the man move from his home. \n\n")
    std::cout<<("Press 'a' or 'A' to make the man move to his farm. \n\n")
    std::cout<<("Press 'z' or 'Z' to make the man do farming. \n\n")
    std::cout<<("Press 'q' or 'Q' to make the man do harvesting. \n\n")
    std::cout<<("Press 'v' or 'V' to make the man move to move back to his house. \n\n")
    std::cout<<("Press 'h' or 'H' to make the man move inside his house. \n\n")
    std::cout<<("Press 'r' or 'R' to make the windmill to rotate. \n\n")
    std::cout<<("Press RIGHT MOUSE BUTTON to display menu. \n\n");
    std::cout<<("Press 'm' or 'M' to quit the program. \n\n\n");
    std::cout<<("Press any key and Hit ENTER.\n");
    std::cin>>ch;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1100.0,700.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Simple Village");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboardFunc);
    glutFullScreen();
    myinit();
    c_menu=glutCreateMenu(main_menu);

    glutAddMenuEntry("Farm",1);
    glutAddMenuEntry("Grow",2);
    glutAddMenuEntry("Harvest",3);
    glutAddMenuEntry("Sell",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}



