#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<strings.h>
#include"welcome.h"
#include<time.h>
#include<cstring>
#include<winbase.h>
#include<dos.h>
#include<ctype.h>
#include<stdlib.h>
#include"struct_timetable.h"
#include<graphics.h>
#include"functions.h"


int main()
{
	
	system("color 4E");
   {
   		int gd = DETECT, gm, x = 25, y = 25, font = 3;
 
   		initgraph(&gd,&gm, "C:\\TC\\BGI");
		{
   		setcolor(1);
   		setbkcolor(0);
      	settextstyle(3, HORIZ_DIR, 10);
      	outtextxy(x, y, "Time");
      	settextstyle(3,HORIZ_DIR,10);
      	x=150,y=150;
      	outtextxy(x,y, "Table");
      	x=250,y=300;
	  	settextstyle(3,HORIZ_DIR,8);
      	outtextxy(x,y, "Generator");
      
	  	x=20;y=350;
      	settextstyle(4,HORIZ_DIR,3);
      	setcolor(2);
      	outtextxy(x,y,"Created By: \n\n");
      	Sleep(2000);
      	setcolor(4);
      	settextstyle(8,HORIZ_DIR,3);
      	x=150,y=420;
      	outtextxy(x,y,"\t\tIbrahim\n");
      	Sleep(500);
      	setcolor(14);
      	settextstyle(8,HORIZ_DIR,3);
      	x=280,y=420;
      	outtextxy(x,y,"\t\t\t\tShehzad\n");
      	Sleep(500);
      	settextstyle(8,HORIZ_DIR,3);
      	x=400,y=420;
      	setcolor(9);
      	outtextxy(x,y,"\t\t\t\t\t\tand Waleed");
      	Sleep(2000);
   		}
   		closegraph();
	}
	pass();
	//Sleep(2000);
	do
{
	int mode, i, j, n_cl, mode1, grade;
	char ch,temp[3];
	system("cls");
    welcome();
	printf("\n\n\n\n");
	printf("\t\t1.Create a New Time Table\n\t\t2.Open An Existing Time Table\n\t\t3.Exit\n");
	printf("\n\n\t\tEnter Your Choice: ");
	gets(temp);
	mode=atoi(temp);
	
	switch(mode){
		case 1: 
		{
			printf("\n\n\tWARNING:\n\n\t\t Creating a New Time Table would result in Overwriting the Older\t\t One.\n\t\t Do you wish to continue? Y/N	");
			if(getche()=='y' || getche()=='Y')
			{
				system("cls");
				input(&n_cl);
				writeinput(&n_cl);
				arrange(&n_cl);
				writearrange(&n_cl);
				system("cls");
				printf("\t\tTime Table Generated Successfully");
				Sleep(1500);
				continue;
			}
			else
				continue;
		}

		case 2: 
		do
		{
			readfile(&n_cl);
			system("cls");
			printf("\t\tOpen An Existing Time Table\n\n\n");
			for(int g=0;g<n_cl;g++)
			{
				printf("%d. %s\n",g+1,cls[g].cname);
			}
		   printf("\n\n\nEnter Class To view its Time Table: ");
		   gets(temp);
		   grade=atoi(temp);
		   grade--;
		   int gd= DETECT,gm,x,y;
		   initgraph(&gd,&gm,"C:\\TC\\BGI");
		   settextstyle(3,HORIZ_DIR,1);
		   x=150,y=25;
		   setcolor(1);
		   outtextxy(x,y, "Time Table For Class ");
		   x=350;y=25;
		   outtextxy(x,y, cls[grade].cname);
		   y=100;
		   //setcolor(9);
		   for(int d=0; d<5; d++)
		   {
		   		x=20;
		   		setcolor(4);
		   		outtextxy(x,y, days[d].dayname);
		   		x=80;
		   		for(int s=0; s<8; s++)
		   		{ 
		   			setcolor(9);
		   	  		outtextxy(x, y, days[d].clas_s[grade].p_t[s].period);
		   	  		Sleep(500);
		   	  		x+=70;
				}
				y+=50;
			}
			//y+=50;	
		Sleep(2000);
	   settextstyle(2,HORIZ_DIR,4);
	   setcolor(1);
	   outtextxy(400,400, "Press any key to exit");
	   getch();
	  closegraph();
	  system("cls");
		printf("\n\n Display Time Table for Another Class? Y/N  \n");
		} while(getche()=='y'|| getche()=='Y');
	   	continue;
	
	case 3: exit(0);
	default: continue;
}
}
while(1);
	
}
