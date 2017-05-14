#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

struct time t_new,t_old,t_a;

void m();
void s();
void c();
void a();

void main()
{
m();
}


void m()
{
clrscr();
struct time t_new,t_old,t_a;
int key;


printf("*************************** Welcome to Alarm Page ****************************\n");
printf("------------------------------------------------------------------------------\n");
printf("          $         $               $          $$$$$$$      $         $       \n");
printf("         $ $        $              $ $         $      $     $ $     $ $       \n");
printf("        $   $       $             $   $        $     $      $   $ $   $       \n");
printf("       $$$$$$$      $            $$$$$$$       $$$$$        $    $    $       \n");
printf("      $       $     $           $       $      $    $       $         $       \n");
printf("     $         $    $          $         $     $     $      $         $       \n");
printf("    $           $   $$$$$$$$$ $           $    $      $     $         $       \n");
printf("------------------------------------------------------------------------------\n");
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

}

if(key==2)
s();

if(key==4)
exit(1);

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
  gettime(&t_new);
  if(t_a.ti_min==t_new.ti_min && t_a.ti_sec==t_new.ti_sec)
  a();

  }

} 			// s function close here

void a()
{
char w;

printf("\n\n\n");
  printf("       $     $        $        $    $     $$$$$$          $     $    $$$$$   ");
printf("\n       $     $       $ $       $  $       $               $     $    $    $  ");
printf("\n       $  $  $      $$$$$      $$         $$$$   !!!!!!!  $     $    $$$$$   ");
printf("\n       $$   $$     $     $     $  $       $               $     $    $       ");
printf("\n       $     $    $       $    $    $     $$$$$$          $$$$$$$    $       ");
printf("\n\n       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");



sound(500);
sleep(1);
sound(639);
sleep(1);
sound(520);
sleep(1);
sound(350);
sleep(1);
sound(850);
sleep(1);
sound(780);
sleep(1);
sound(453);
sleep(1);
sound(239);
sound(685);
sound(639);
sleep(1);
sound(520);
sleep(1);
sound(350);
sleep(1);
sound(840);
sleep(1);
sound(720);
sleep(1);
sound(453);
sleep(1);
sound(259);
sound(670);
sound(699);
sleep(1);
sound(590);
sleep(1);
sound(320);
sleep(1);
sound(750);
sleep(1);
sound(790);
sleep(1);

sound(453);
sleep(1);
sound(339);
sound(960);
nosound();
scanf("%*c");
printf("\n\n\t\tWant to set an alarm again(Y or y, N or n):");
scanf("%c",&w);

switch(w)
{
case 'n':
case 'N':
m();

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
else m();

}


}
