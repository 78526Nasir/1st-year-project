#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
clrscr();
int i;

for(i=0;i<=100;i+=20)
{
	clrscr();
	printf("Loading.........%d%",i) 
	sleep(1);
}

getch();
}
