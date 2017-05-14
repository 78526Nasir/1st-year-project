#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<string.h>



//function's//

void L1();
void m();	// Main Page function //
void v();
void load();
void clock();
void calender();
void stopwatch();
void help();
void L2();
void watch();


// for alarm//

struct time t_new,t_old,t_a;
void alarm();
void s();  // function for set alarm
void a();   //function for alarm generate
void m1();
void scan();

// for mouse control //
union REGS i, o;
int initmouse();
void showmouseptr();
void hidemouseptr();
void getmousepos(int*,int*,int*);
int mouse();


// for stopwatch //
int h1=0,m2=0,s1=0,ms1=0;
char ch1='p';

// for Calender //

#define LEAP_YEAR ((Year%4==0 && Year%100 != 0)||Year%400==0)
#define TRUE 1
#define CH '-'
#define MAX_NO 91

void cal();


//****************************** Main function **************************** //
//************************************************************************* //


void main()
{
	load();
	int i,j,mx,my,gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	mx=getmaxx();
	my=getmaxy();
	for(i=0;i<mx;i++)
	{
	for(j=0;j<my;j++)
	putpixel(i,j,8);
	}
	setcolor(0);
	settextstyle(4,0,6);
	outtextxy(25,180,"Welcome To Our Software");
	setcolor(7);
	settextstyle(0,0,1);
	outtextxy(380,450,"Press any key to continue.....");



	getch();

	v();      // verification function //
}



//========================= Flashing Loading Effect ========================//


void load()
{
	clrscr();
	int i;
	for(i=0;i<=100;i+=20)
	{
	clrscr();

	printf("Loading.............%d%",i);
	sleep(1);
	}
}


//========================= verification function ==========================//


void v()
{

   int i = 0, key, num, midx, gd = DETECT, gm;
   char a[10],cap[10];


   initgraph(&gd,&gm,"C:\\TC\\BGI");
   midx = getmaxx()/2;

   settextstyle(4,HORIZ_DIR,6);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   setcolor(2);
   outtextxy(midx,50,"Verification Page");
   settextstyle(1,HORIZ_DIR,1);
   setcolor(6);
   outtextxy(midx,125,"Press C or c to change the generated random code \"captcha\"");
   outtextxy(midx,145,"Or Press Enter to Input the \"Captcha\"");

   settextstyle(5,0,1);


   setcolor(WHITE);
   setviewport(100,200,600,400,1);
   setcolor(7);
   randomize();


  while(1)
  {
      settextstyle(0,0,1);
      while(i<6)
      {
	 num = random(3);

	 if ( num == 0 )
	    a[i] = 65 + random(26);     // 65 is the ASCII value of A //
	 else if ( num == 1)
	    a[i] = 97 + random(26);     // 97 is the ASCII value of a //
	 else
	    a[i] = 48 + random(10);     // 48 is the ASCII value of 0 //
	 i++;
      }  			// inner while end//
      a[i] = '\0';
      outtextxy(210,50,a);
      setcolor(7);

      key=getch();
      if(key==27)
      exit(0);


      if(key==67 || key==99)
      {
      clearviewport();
      i=0;
      continue;
      }

      if(key==13)
      {
      settextstyle(0,0,1);
      outtextxy(210,80,"Enter the exact captcha code for continue:");
      gotoxy(61,18);
      scanf("%s",cap);



      if(strcmp(a,cap)==0)
      {
      outtextxy(210,120,"You entered correct captcha.. :) ");
      outtextxy(210,140,"Press any key to continued..");
      key=getch();
      if(key==27)
      exit(0);

      L1();     //load 1 call here
      sleep(1);
      m();  			//main page call here //
      break;
      }


      else
      outtextxy(210,120,"Not match try again by pressing enter..");
      outtextxy(210,180,"Press escape key to exit...");

      key = getch();

      if( key == 27 )                     // escape key//
	exit(0);

      if(key==13)                          // enter key //
      {
      clearviewport();
      i = 0;
      }
			}   // enter if //

	} 	  // main while end //



} 	// varification(v) function end//




//========================= graphics Loading Function ======================//

void L1()
{
 int x,y,i;
 int g=DETECT, d,j=0;
 initgraph(&g, &d,"C:\\TC\\BGI");
 x=getmaxx()/2-100;
 y=getmaxy()/2-100;

 int c=150;
 for(int e=0;e<20;e++)
 {
  for(int i=50;i<100;i++)
  {
    setcolor(3+j);
    j++;
    settextstyle(2,0,12);
    outtextxy(x,y,"Loading...");
    setcolor(3+j);
    settextstyle(2,0,5);
    outtextxy(160,180,"Please Wait... ");
    circle(x,y,i);
    j++;
    circle(x,y,c);
    c--;
    cleardevice();
  }
  }
}




//====================== Main Menu Page View Fuction =======================//


void m()
{

   int i = 0, key, num, midx, gd = DETECT, gm,mx,my,j;
   char a[10],cap[10];


	initgraph(&gd,&gm,"C:\\TC\\BGI");
	mx=getmaxx();
	my=getmaxy();

	for(i=0;i<mx;i++)
	{
	for(j=0;j<my;j++)
	putpixel(i,j,8);
	}

   midx = getmaxx()/2;
   setfillstyle(1,0);
   bar(10,10,630,120);
   settextstyle(4,0,9);

   settextjustify(CENTER_TEXT,CENTER_TEXT);
   setcolor(6);
   outtextxy(midx,50,"Main Menu");


//============================ Menu option =================================//
   setfillstyle(3,1);
   bar(1,170,170,190);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(50,180,"1. Clock");


   setfillstyle(3,1);
   bar(1,210,170,230);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(62,220,"2. Calender");


   setfillstyle(3,1);
   bar(1,250,170,270);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(50,260,"3. Alarm");


   setfillstyle(3,1);
   bar(1,290,170,310);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(66,300,"4. Stopwatch");

   setfillstyle(3,1);
   bar(1,330,170,350);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(47,340,"5. Help");


   setfillstyle(3,4);
   bar(1,370,170,390);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(47,380,"6. EXIT");

   setfillstyle(3,1);
   bar(200,270,430,290);
   settextstyle(0,0,1);
   setcolor(15);
   outtextxy(300,280,"Enter What you want :");
   gotoxy(50,18);
   scanf("%d",&key);
   if(key==1)
   clock();
   else if(key==2)
   calender();
   else if(key==3)
   alarm();
   else if(key==4)
   stopwatch();
   else if(key==5)
   help();
   else exit(1);


}







//==========================================================================//
//==========================Mouse control Function==========================//

int mouse()
{



   int gd = DETECT, gm, status, button, x, y, tempx, tempy;
   char array[50];

   initgraph(&gd,&gm,"C:\\TC\\BGI");
   settextstyle(0,0,1);

   status = initmouse();

   if ( status == 0 )
      printf("Mouse support not available.\n");
   else
   {
      showmouseptr();

      getmousepos(&button,&x,&y);

      tempx = x;
      tempy = y;

      while(!kbhit())
      {
	 getmousepos(&button,&x,&y);

	 if( x == tempx && y == tempy )
	 {}
	 else
	 {
	    cleardevice();
	    sprintf(array,"X = %d, Y = %d",x,y);
	    outtextxy(5,450,array);
	    tempx = x;
	    tempy = y;
	 }
      }
   }

   getch();
   return 0;
}

int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}


//==================== mouse main function close here======================//


//================================ Clock ===================================//


void clock()
{
    closegraph();



    struct  time t;
    struct arccoordstype sec_arc, min_arc, hr_arc;
    int i;
    char key;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(RED);
    //Outer circle
    circle(320,240,100);
    circle(320,240,99);
    //Inner circle
    circle(320,240,80);
    circle(320,240,81);
    setcolor(WHITE);
    //mark four points
    line(320,160,320,165);//top
    line(320,315,320,320);//bottom
    line(400,240,395,240);//left
    line(240,240,245,240);//right

    while(!kbhit())
    {
	printf("Time is : %2d:%2d:%3d\r",t.ti_hour%12, t.ti_min, t.ti_sec);
	setcolor(0);
	line(320,240, sec_arc.xend, sec_arc.yend);
	line(320,240, min_arc.xend, min_arc.yend);
	line(320,240, hr_arc.xend, hr_arc.yend);
	//Store time into struct t
	gettime(&t);
	//hour
	setcolor(0);
	arc(320,240,270,90-(t.ti_hour*6*5),55);
	setcolor(YELLOW);
	getarccoords(&hr_arc);
	line(320,240, hr_arc.xend, hr_arc.yend);
	//minute
	setcolor(0);
	arc(320,240,270,90-t.ti_min*6,65);
	setcolor(CYAN);
	getarccoords(&min_arc);
	line(320,240, min_arc.xend, min_arc.yend);
	//center circle
	setcolor(WHITE);
	pieslice(320,240,0,360,5);
	//second
	setcolor(0);
	arc(320,240,270,90-t.ti_sec*6,75);
	setcolor(RED);
	getarccoords(&sec_arc);
	line(320,240, sec_arc.xend, sec_arc.yend);
	delay(250);
	}

	getch();
	setfillstyle(1,6);
	bar(100,450,600,470);
	settextstyle(0,0,1);
	setcolor(15);

	outtextxy(105,455,"Want to go the Main menu ? (Y, y or N, n):");

	gotoxy(70,25);

	key=getch();
	if(key=='Y' || key=='y')


	m();


}

//=================================Load 2 function =========================//



void L2()
{

 int x,y,i;
 int g=DETECT, d,j=0;
 initgraph(&g, &d,"C:\\TC\\BGI");
 x=getmaxx()/2-100;
 y=getmaxy()/2-100;

 int c=150;
 for(int e=0;e<15;e++)
 {
  for(int i=50;i<100;i++)
  {
    setcolor(3+j);
    j++;
    settextstyle(1,0,4);
    outtextxy(x,y,"Loading...");
    setcolor(3+j);
    settextstyle(0,0,1);
    outtextxy(180,180,"Please Wait... ");
    circle(x,y,i);
    j++;
    circle(x,y,c);
    c--;
    cleardevice();
  }
  }
}



//=============================== Alarm START ==============================//



void alarm()
{
closegraph();
m1();
}


void m1()
{
clrscr();
struct time t_new,t_old,t_a;
int key;


printf("*************************** Welcome to Alarm Page ****************************\n\n");
printf("          $         $               $          $$$$$$$      $         $       \n");
printf("         $ $        $              $ $         $      $     $ $     $ $       \n");
printf("        $   $       $             $   $        $     $      $   $ $   $       \n");
printf("       $$$$$$$      $            $$$$$$$       $$$$$        $    $    $       \n");
printf("      $       $     $           $       $      $    $       $         $       \n");
printf("     $         $    $          $         $     $     $      $         $       \n");
printf("    $           $   $$$$$$$$$ $           $    $      $     $         $       \n");
printf("\n******************************************************************************\n");
printf("\n     Alarm Menu");
printf("\n     -----------");
printf("\n 1. Current Time:");
printf("\n 2. Set Time:");
printf("\n 3. Goto Main Menu:");
printf("\n 4. EXIT");
printf("\n    Enter what you want :");

scanf("%d",&key);

if(key==1)
{
  clrscr();
  gettime(&t_old);
  gotoxy(5,5);
  cprintf("The Current time is : %d : %d : %d",t_old.ti_hour,t_old.ti_min,t_old.ti_sec);

  while(!kbhit())
  {
  gettime(&t_new);

  if(t_new.ti_sec!=t_old.ti_sec)
  t_old=t_new;
  gotoxy(5,5);
  cprintf("The current time is --> %d : %d : %d",t_old.ti_hour,t_old.ti_min,t_old.ti_sec);
  }
  m1();
}

if(key==2)
s();
if(key==3)
m();
if(key==4)
exit(1);
else exit(1);

} 		//main function close here

void s()
{

  clrscr();
  gettime(&t_old);
  gotoxy(5,5);
  cprintf("The Current time is : %d : %d : %d",t_old.ti_hour,t_old.ti_min,t_old.ti_sec);

  while(!kbhit())
  {
  gettime(&t_new);

  if(t_new.ti_sec!=t_old.ti_sec)
  t_old=t_new;
  gotoxy(5,5);
  cprintf("The current time is --> %d : %d : %d\n",t_old.ti_hour,t_old.ti_min,t_old.ti_sec);
  }
   gotoxy(5,6);
   cprintf("Enter hour, minute & second for set an alarm :");
   scanf("%d%d%d",&t_a.ti_hour,&t_a.ti_min,&t_a.ti_sec);

  while(1)
  {
  if(kbhit())
  scan();
  gettime(&t_new);
  if(t_a.ti_min==t_new.ti_min && t_a.ti_sec==t_new.ti_sec)
  a();

  }


} 			// s function close here

void a()
{


printf("\n\n\n");
  printf("     $       $        $        $    $     $$$$$$          $     $    $$$$$   ");
printf("\n     $       $       $ $       $  $       $               $     $    $    $  ");
printf("\n     $   $   $      $$$$$      $$         $$$$   !!!!!!!  $     $    $$$$$   ");
printf("\n     $ $   $ $     $     $     $  $       $               $     $    $       ");
printf("\n     $       $    $       $    $    $     $$$$$$          $$$$$$$    $       ");
printf("\n\n     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

while(1)
{
sound(350);
if(kbhit())
scan();
sleep(1);
sound(639);
if(kbhit())
scan();
sleep(1);
sound(520);
if(kbhit())
scan();
sleep(1);
sound(350);
if(kbhit())
scan();
sleep(1);
sound(850);
if(kbhit())
scan();
sleep(1);
sound(780);
if(kbhit())
scan();
sleep(1);
sound(453);
if(kbhit())
scan();
sleep(1);
sound(239);
if(kbhit())
scan();
sound(685);
if(kbhit())
scan();
sound(639);
if(kbhit())
scan();
sleep(1);
sound(520);
if(kbhit())
scan();
sleep(1);
sound(350);
if(kbhit())
scan();
sleep(1);
sound(840);
if(kbhit())
scan();
sleep(1);
sound(720);
if(kbhit())
scan();
sleep(1);
sound(453);
if(kbhit())
scan();
sleep(1);
sound(259);
if(kbhit())
scan();
sound(670);
if(kbhit())
scan();
sound(699);
if(kbhit())
scan();
sleep(1);
sound(590);
if(kbhit())
scan();
sleep(1);
sound(320);
if(kbhit())
scan();
sleep(1);
sound(750);
if(kbhit())
scan();
sleep(1);
sound(790);
if(kbhit())
scan();
sleep(1);
sound(453);
if(kbhit())
scan();
sleep(1);
sound(339);
if(kbhit())
scan();
sound(960);
if(kbhit())
scan();
else scan();



}

}





void scan()
{
nosound();
char w;
scanf("%*c");
printf("\n\n\t\tWant to set an alarm again(Y or y, N or n):");
scanf("%c",&w);

switch(w)
{
case 'n':
case 'N':
m1();

case 'Y':
case 'y':
s();
break;

default:
printf("Enter a valid character!");
scanf("%*c");
scanf("%c",&w);
if(w=='Y' || w=='y')
s();
else m1();

}

}
//============================== Alarm End here ========================//


//================================ Stopwatch start=========================//

void stopwatch()
{
closegraph();
watch();
int key;

while(1)
{
ch1=getch();
if(ch1=='s'||ch1=='S')
break;
if(ch1=='e'||ch1=='E')
{
printf("\n\n\t\t\twant to go Main menu?(Y,y or N,n)");
key=getch();
if(key=='Y' ||key=='y')
m();
else
 exit(0);
}

if(ch1==27)
exit(1);
}

while(1)
{
watch();
delay(10);

if(kbhit())
ch1=getch();

if(ch1=='r'||ch1=='R')
{
h1=m2=s1=ms1=0;
watch();

while(1)
{
ch1=getch();
if(ch1=='s'||ch1=='S')
break;

if(ch1=='e'||ch1=='E')
{
printf("\n\n\t\t\twant to go Main menu?(Y,y or N,n)");
key=getch();
if(key=='Y' ||key=='y')
m();
else
exit(0);
}
if(ch1==27)
exit(1);
}

}

else
if(ch1=='p'||ch1=='P')

while(1)
{
ch1=getch();
if(ch1=='s'||ch1=='S')
break;
if(ch1=='e'||ch1=='E')
{
printf("\n\n\t\t\twant to go Main menu?(Y,y or N,n)");
key=getch();
if(key=='Y' ||key=='y')
m();
else
 exit(0);
}

if(ch1==27)
exit(1);
if(ch1=='r'||ch1=='R')
{
ch1='c';
h1=m2=s1=ms1=0;
watch();
}

}
else
if(ch1=='e'||ch1=='E')
{
printf("\n\n\t\t\twant to go Main menu?(Y,y or N,n)");
key=getch();
if(key=='Y' ||key=='y')
m();
else
exit(0);
}

	if(ms1!=99)
	ms1++;
	else
	{
	ms1=0;
	if(s1!=59)
	s1++;
	else
	{
	s1=0;
	if(m2!=59)
	m2++;
	else
	{
	m2=0;
	h1++;
	}
	}

   }

 }

}

void watch()
{

clrscr();

printf("##############################################################################\n\n");
printf("   ####  #######  ######  #######  #      #  ######  #######  #####  #     #\n");
printf("  #         #     #    #  #     #  #      #  #    #     #     #      #     # \n");
printf("  #         #     #    #  #######  #      #  #    #     #     #      #     # \n");
printf("   ####     #     #    #  #        #  #   #  ######     #     #      #######\n");
printf("       #    #     #    #  #        # #  # #  #    #     #     #      #     #\n");
printf("       #    #     #    #  #        ##    ##  #    #     #     #      #     #\n");
printf("   ####     #     ######  #        #      #  #    #     #     #####  #     #\n");

printf("\n##############################################################################");
printf("\n\n\t\t\t\t%d: %d : %d : %d",h1,m2,s1,ms1);

printf("\n\n\n\t\t\t\t\t\t\tPress Key");
printf("\n\t\t\t\t\t\t\t");
printf("\n\t\t\t\t\t\t\ts -> Start");
printf("\n\t\t\t\t\t\t\tp -> Pause");
printf("\n\t\t\t\t\t\t\tr -> Reset");
printf("\n\t\t\t\t\t\t\te -> Exit");

}



//============================ end of stopwatch ===========================//

//=============================== Calender ================================//


void calender()
{
 int key;
 closegraph();
 cal();



}


int MonthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

char *MonthName[]={"January","February","March","April","May","June","July",
		"August","September","October","November","Decembeer"};

char *MonthName1[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP",
			"OCT","NOV","DEC"};


//================= FUNCTION TO CALCULATE ZELLER'S ALGORITHM ===============//

int getZeller(int Month,int Year)
{
	int Day = 1, ZMonth, ZYear, Zeller;
	if(Month < 3)
		ZMonth = Month+10;
	else
		ZMonth = Month-2;
	if(ZMonth > 10)
		ZYear = Year-1;
	else
		ZYear = Year;
	Zeller = ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
			(int)((ZYear%100)/4)-2*(int)(ZYear/100)+
			(int)(ZYear/400)+77)%7;
	return Zeller;
}


void PrintFile(int M,int Y, int Z)
{
	int i,j;
	char filename[12];
	char stryear[5];
	FILE *stream;

	strcpy(filename,MonthName1[M-1]);
	itoa(Y,stryear,10);
	strcat(filename,stryear);
	strcat(filename,".txt");

	if((stream=fopen(filename,"w"))==NULL)
	{
		printf("\nError-cannot create file.");
		getch();
		exit(1);
	}
	fprintf(stream,"\n\t\t\t%s %d\n\n\t",MonthName[M-1],Y);
	for(i=1;i<=MAX_NO;i++)
		fprintf(stream,"-");

	fprintf(stream,"\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\t");
	for(i=1;i<=MAX_NO;i++)
		fprintf(stream,"-");
	// setting starting position
	fprintf(stream,"\n");
	for(i = 1; i <= Z; i++)
		fprintf(stream,"\t -");
	j = Z;
	// printing dates
	for(i = 1; i <= MonthDay[M-1]; i++)
	{
		if(j++ % 7 == 0)
			fprintf(stream,"\n");
		fprintf(stream,"\t%2d",i);
	}
	fprintf(stream,"\n\t");
	for(i=1;i<=MAX_NO;i++)
		fprintf(stream,"-");

	fclose(stream);
}
void printchar(char c)
{
	int i=1;
	printf("\n\t");
	for(i=1;i<=51;i++)
		printf("%c",c);
	printf("\n");

}

//============================== MAIN FUNCTION =============================//
void cal()
{
	int Month, Year, Zeller;
	int i, j, Key;



Top:    // goto statement
	textcolor(WHITE);
	clrscr();
	printf("\n\tThis program shows calendar of \n");
	printf("\n\ta given month. Enter month, year...format is mm-yyyy.\n");

	while(TRUE)
	{
		fflush(stdin);
		printf("\n\n\tEnter mm-yyyy: ");
		scanf("%d-%d", &Month, &Year);
		if(Year < 0)
		{
			printf("\nInvalid year value...");
			continue;
		}
		if(Year < 100)
			Year += 1900;
		if(Year < 1582 || Year > 4902)
		{
			printf("\nInvalid year value...");
			continue;
		}
		if(Month < 1 || Month > 12)
		{
			printf("\nInvalid month value...");
			continue;
		}
		break;
	}	// End of while loop

	do
	{
		// calculating day of 1st date of given month
		Zeller = getZeller(Month,Year);
		clrscr();
		printf("\n\n\t\t\t");

		// printing the corresponding month name
		textbackground(Month);
		cprintf("%s %d\n",MonthName[Month-1],Year);
		textbackground(BLACK);

		// adjusting February in case of Leap Year
		MonthDay[1] = LEAP_YEAR ? 29 : 28;

		// giving output
		printchar(CH);

		//textcolor(12);
	      //	printf("\t");
	       //	cprintf("SUN");
	       //	textcolor(LIGHTGREEN);
		cprintf("       SUN     MON     TUE     WED     THU     FRI     SAT");
		textcolor(15);

		printchar(CH);

	       // setting starting position
		for(i = 1; i <= Zeller; i++)
			printf("\t -");
		j = Zeller;
		// printing dates //
		for(i = 1; i <= MonthDay[Month-1]; i++)
		{
			if(j++ %7 == 0)
			{
				printf("\n\t");
			       //	textcolor(12);
				cprintf("%2d",i);
				//textcolor();
			}
			else
				printf("      %2d",i);
		}

		printchar(CH);
		printf("\n\n\t\t(*) Use Left,Right,Up & Down Arrow.");
		printf("\n\n\t\t(*) Press I for New Month & Year.");
		printf("\n\n\t\t(*) Press P for Print to File.");
		printf("\n\n\t\t(*) Press ESC for Exit Calender.");


		Key = getch();         // getting Key Code

		if(Key == 72)           // Up Arrow
			Year++;

		if(Key == 80)           // Down Arrow
			Year--;

		if(Key == 77)           // Right Arrow
		{
			Month++;
			if(Month > 12)
			{
				Month = 1;
				Year++;
			}
		}

		if(Key == 75)            // Left Arrow
		{
			Month--;
			if(Month < 1)
			{
				Month = 12;
				Year--;
			}
		}

		if(Key == 80 || Key==112)             // Code of P
			PrintFile(Month,Year,Zeller);

		if(Key == 105 || Key==73)             // Code of I
			goto Top;
		if(Key == 27)
		{
		clrscr();
		printf("\n\n\t\tWant to go the Main Menu(y,Y or N,n): ");
		Key=getch();
		if(Key=='Y' || Key=='y')
		m();
		else exit(0);

		}


	}while(1);	// End of do-while loop


}

//=================================== Help =================================//

void help()
{
int key;
closegraph();
clrscr();
printf("************************** How to Operate our Software  ************************");
printf("\nBy Pressing Control F9  anyone can run our software. The first phase is welcome Page. By pressing any key a user able to go the next phase. The next phase is   \"Varification Page\" in this phase user will be forced for input a \"CAPTCHA\" code to varify that the user is \"Human\" not a \"Robot\". If the \"CAPTCHA\" code Match  user can able to go the \"Main Menu\" of our Software.");
printf("\nIn \"Main Menu\" user will find 6 option and 0ne input filled. By input 1 a user  can able to go tha clock program.");

getch();
clrscr();
printf("\n\n\t\tWant to go the Main Menu(y,Y or N,n): ");
key=getch();
if(key=='Y' || key=='y')
m();

}

//============================ End of Help Function ========================//