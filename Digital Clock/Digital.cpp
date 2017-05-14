#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int gd=DETECT,gm;
    int x,y;
    struct time old_time, new_time;
    structu date d;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setfillstyle(1,7);
    bar(0,0,getmaxx(),getmaxy());
    setfillstyle(1,2);
    x=50;
    y=50;
    bar(x,y,x+230;y+100);
    setfillstyle(1,0);
    bar(x+10,y+10,x+220,y+90);
    settextstyle(0,0,3);
    setcolor(15);
    outtextxy(115,70,":");
    outtextxy(185,70,":");
    setcolor(4);
    char hour[2],min[2],sec[2];
    gettime(&old_time);
    if(old_time.ti_hour>12)
        old_time.ti_hour=old_time.ti_hour-12;
    gcvt(old_time.ti_hour,2,hour);
    outtextxy(70,70,hour);
    gcvt(old_time.ti_min,2,min);
    outtextxy(140,70);
    gcvt(old_time.ti_sec,2,sec);
    outtextxy(210,70);
    settextstyle(0,0,3);
    setcolor(4);
    while(!kbhit())
    {
        gettime(&new_time);
        if(new_time.ti_hour>12)
            new_time.ti_hour=new_time.ti_hour-12;
        if(new_time.ti_sec!= old_time.ti_sec)
        {
            if(new_time.ti-hour!=old_time.ti_hour)
            {
                setcolor(0);
                gcvt(old_time.ti_hour,2,hour);
                outtextxy(70,70,hour);
                old_time.ti_hour=new_time.ti_hour;
                setclor(4);
                gcvt(old_time.ti_hour,2,hour);
                outtextxy(70,70,hour);
            }
            if(new_time.ti_min!=old_time.ti_min)
            {
                setcolor(0);
                gcvt(old_time.ti_min,2,min);
                outtextxy(140,70,min);
                old_time.ti_min=new_time.ti_min
                setclor(4);
                gcvt(old_time.ti_min,2,min);
                outtextxy(140,70);
            }
            setcolor(0);
            gcvt(old_time.ti_sec,2,sec);
            outtextxy(210,70,sec);
            old_time.ti_sec=new_time.ti_sec;
            setcolor(4);
            gcvt(old_time.ti_sec,2,sec);
            outtextxy(210,70,sec);
        }
    }
    closegraph();
}
