// welcome screen
HANDLE rHnd,wHnd;
void locate(int,int);
void locate(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition (wHnd,pos);

}

void welcome();
void welcome()
{
	int i;
	//system("color C4");
		//printf("\n\n");
	
	printf("\t\t");
	for(i=0; i<33 ; i++)
	printf("\xB0");
	
	printf("\n\t\t\xB0");
	printf("      TIME TABLE GENERATOR \t\xDB"); // 6 spaces, and ajdusted \xDB..
	
	printf("\n");
	printf("\t\t");
	for(i=0; i<33 ; i++)
	printf("\xDB");
	
    //locate(2,1);
    //Sleep(250);
    
}
//void mainwelcome();
//void mainwelcome()
//{
//		
//    Sleep(1000);
//    system("cls");
//    printf("\n\n\n\n");
//    welcome();
//    printf("\nMade by: ");
//    Sleep(1000);
//    system("cls");
//    printf("\n\n\n\n\n\n\n\n");
//	welcome();
//	printf("\t\tIbrahim");
//	Sleep(1000);
//	system("cls");
//	printf("\n\n\n\n\n\n\n\n\n");
//    welcome();
//    printf("\t\t\tShezad");
//    
//    Sleep(1000);
//    system("cls");
//    printf("\n\n\n\n\n\n\n\n\n");
//    welcome();
//    printf("\t\t\tand Waleed");
//    
//    Sleep(1000);
//    system("cls");
//}
//void welcome1(void);
//void welcome1(void)
//{
//   int gd = DETECT, gm, x = 25, y = 25, font = 3;
// 
//   initgraph(&gd,&gm,"C:\\TC\\BGI");
//   for (font = 0; font <= 10; font++)
//   {
//   	setfillstyle(LINE_FILL,1);
//   	bar(600,20,600,20);
//   	Sleep(2000);
//   	setcolor(1);
//   	setbkcolor(0);
//      settextstyle(3, HORIZ_DIR, 10);
//      outtextxy(x, y, "Time");
//      settextstyle(3,HORIZ_DIR,10);
//      x=150,y=150;
//      outtextxy(x,y, "Table");
//      x=250,y=300;
//	  settextstyle(3,HORIZ_DIR,8);
//      x=250,y=300;
//      outtextxy(x,y, "Generator");
//      
//	  Sleep(2000);
//      settextstyle(4,HORIZ_DIR,3);
//      Sleep(2000);
//      x=50; y=75;
//      setcolor(2);
//      outtextxy(x,y,"Created By: \n\n");
//      Sleep(2000);
//      setcolor(4);
//      settextstyle(8,HORIZ_DIR,3);
//      x=75,y=150;
//      outtextxy(x,y,"\t\tIbrahim\n");
//      Sleep(1000);
//      setcolor(5);
//      settextstyle(8,HORIZ_DIR,3);
//      x=100,y=235;
//      outtextxy(x,y,"\t\t\t\tShezad\n");
//      Sleep(1000);
//      settextstyle(8,HORIZ_DIR,3);
//      x=125,y=330;
//      setcolor(9);
//      outtextxy(x,y,"\t\t\t\t\t\tand Waleed");
//      Sleep(1000);
//      y = y + 25;
//   }
// 
//   getch();
//   closegraph();
//   system("color F0");
//   printf("\n\t\tAnd the rest of the w0rk is here\n\n");
//   Sleep(2000);
//   exit(0);
//   getche();
//   return 0;
//}
//#include"Untitled5.h"
//void mainscrn(void)
//{
//	int mode, i, j, n_cl, mode1;
//	char ch,grade[3],temp[3];
//	welcome();
//	printf("\n\n\n\n");
//	printf("\t\t1.Create a New Time Table\n\t\t2.Open An Existing Time Table\n\t\t3.Exit\n");
//	printf("\n\n\t\tEnter Your Choice: ");
//	gets(temp);
//	mode=atoi(temp);
//	
//	
//	switch(mode){
//		case 1: 
//		{
//			printf("\n\n\tWARNING:\n\n\t\t Creating a New Time Table would result in Overwriting the Older\t\t One.\n\t\t Do you wish to continue? Y/N");
//			if(getche()=='y')
//				{
//					system("cls");
//						//int n_cl;		//no.of classes
//						input(&n_cl);
//						writeinput(&n_cl);
//						arrange(&n_cl);
//						writearrange();
//						//readfile(&n_cl);
//						getch();
//				}
//		
//		//printf("\n\n\tThe Time Table Have Also Been Written in Text File named\n\t\t timetable.txt ");
//		   break;
//		}
//	   case 2: {
//	
//	
//	   	  system("cls");
//	   	  printf("\t\tOpen An Existing Time Table: ");
//				 system("cls");
//	   	  				do{
//			
//		   system("cls");
//		   printf("Enter Class To view its Generated Time Table: ");
//		   scanf("%s",grade);
//		   puts(grade);
//		   printf("After Creation...");
//		   Sleep(2000);
//		   int gd= DETECT,gm,x,y;
//		   initgraph(&gd,&gm,"C:\\TC\\BGI");
//		   settextstyle(3,HORIZ_DIR,1);
//		   //setbkcolor(4);
//		   x=150,y=25;
//		   outtextxy(x,y, "Time Table For Class ");
//		   x=350;y=25;
//		   outtextxy(x,y, grade);
//		   y=150;
//		   for(int d=0; d<5; d++)
//		   {
//		   		x=100;
//		   		for(int s=0; s<8; s++)
//		   		   { //settextstyle(0,HORIZ_DIR,1);
////					  	
////						  int k=rand()%5;
////		   			   	if(k==0)
////						outtextxy(x, y,s1);
////		   		   		else if(k==1)
////		   		   		outtextxy(x,y,s2);
////		   		   		else if(k==2)
////						outtextxy(x,y,s3);
////		   		   		else if(k==3)
////		   		   		outtextxy(x,y,s4);
////		   		   		else if(k==4)
////						outtextxy(x,y,s5);
////		   		   		x+=60;
////		   				Sleep(500);
//		   		}
////			y+=50;
////		
//		   }
//		   Sleep(2000);
//		   settextstyle(2,HORIZ_DIR,4);
//		   outtextxy(400,400, "Press any key to exit");
//		   getch();
//		   closegraph();
//		   printf("\n\n Display time table for Another Class? Y/N");
//		} while(getche()=='y'||getche()=='Y');
//	   	break;  	
//	   	}
//	   break;
//	   case 3:
//	   {
//		system("cls");
//	   	printf("\n\n\n\n\n\n\n\n\t\tSaving and Exiting..");
//	   	Sleep(2000);
//	   	printf("\n\n\n\n");
//	   	exit(0);
//	   	break;}
//	}
//	
//}
