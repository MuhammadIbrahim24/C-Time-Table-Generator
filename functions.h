void input(int *);		//function to take input from user

void s_abb(char [], int, int);		//decleration of function for producing abbreviations of subjects

void teach_id(char [], int, int);	//decleration of function for assigning teacher id

void modify(int);		//to modify input

void writeinput(int *);		//to write input on file before arrangement

void arrange(int *);		//function to arrange subjects

void writearrange(int *);		//function to write on file

void readfile(int *);		//function to read from file

void pass(void);


int count_week[10][12];		//to check that the subject classes are not exceeding periods per week

int tcid=1;					//variable to assign unique teacher id




void pass(void)
{
	static char pass[]={"admin"};		//password is admin
	char str[8],ch;
	int cnt=0,count;
	do
	{
		system("cls");
		//system("color 40");
		printf("\n\n\n");
		printf("			  ");
		for(int i=1;i<26;i++)
		{
		printf("\xB0");
		}
		printf("\n			  \xB0\xB0 PASSWORD  PROTECTED \xB0\xB0\n");
		printf("			  ");
		for(int i=1;i<26;i++)
		{
			printf("\xB0");
		}
		printf("\n\n\n\n\n\n\t\t\t   Enter Password:  ");
		count=0;
		
		do		//ta take password from user
		{
			ch=getche();
			
			if(count>6 && ch!='\r' && ch!='\b')
				continue;
			
			if(ch=='\b')		//if user enters backspace
			{
				if(count==0)		//if cursor is at initial position
				{
					continue;
				}
				else		//if cursor is at some other location
				{
					count--;
					printf("\b \b");
					continue;
				}
			}
			
			if(ch=='\r')		//when user presses enter
			{
				str[count]='\0';
				break;
			}
			
			//printf("*");
			str[count++]=ch;
		}
		while(1);
		
		if(strcmpi(str,pass)==0)
		{
			printf("\n\n\t\t\t      Press any key");
			getche();	
			break;
		}
		printf("\n\n\t\t\t\t      Error\n\t\t\t      Password Incorrect");
		printf("\n\n\t\t\t      Press any key");
		getche();
	}
	while(cnt++<2);
	if((cnt>=2) && strcmpi(str,pass)!=0)
	{
		getche();
		exit(0);
	}
	system("cls");
}





void input(int *pn_cl)
{						//no. of classes
	int chc;		//to get choice of user before jumping to the next class
	char temp[3];		//temp: to store a number as string for conversion in integer
	
	puts("Enter No. of Classes:	");		//no. of classes
	gets(temp);
	*pn_cl=atoi(temp);	
	
	printf("\n\n\n");
	
	for(int aa=0;aa<*pn_cl;aa++)		//for classes
	{
		printf("Class %d\n\n",aa+1);
		puts("Enter Class Name:	");		//class name
		gets(cls[aa].cname);
		strupr(cls[aa].cname);
		
		printf("\n\n");
		
		puts("Enter No. of Subjects:	");		//for no. of subjects
		gets(temp);
		cls[aa].n_sub=atoi(temp);
		
		printf("\n\n");
		
		for(int bb=0;bb<cls[aa].n_sub;bb++)  		//for subjects
		{
			printf("\nSubject %d\n\n",bb+1);
			puts("Enter Subject Name:	");		//subject name
			gets(cls[aa].sub[bb].s_name);
			strupr(cls[aa].sub[bb].s_name);
		
			s_abb(cls[aa].sub[bb].s_name, aa, bb);		//produce subject abbreviation
			printf("\nSubject Abbreviation:\n%s\n\n",cls[aa].sub[bb].abb);
		
			puts("Enter Teacher name:	");		//teacher name
			gets(cls[aa].sub[bb].teacher);
			strupr(cls[aa].sub[bb].teacher);
		
			teach_id(cls[aa].sub[bb].teacher, aa, bb);		//to assign an id to the teacher
			printf("\nTeacher id:\n%d\n\n",cls[aa].sub[bb].t_id);
			
			puts("Enter No. of Classes per week:	");		//to store no. of classes per week of each subject
			gets(temp);
			cls[aa].sub[bb].ppw=atoi(temp);
			printf("\n");
		}
		do		//to ask user for correction
		{
			puts("\n\n1. Jump to Next Class\n2. Modify input");
			chc=atoi(gets(temp));
			switch(chc)
			{
				case 1: break;
				case 2: modify(aa);
			}
		}
		while(chc!=1);
		system("cls");
	}
	printf("\nend input\n");
}





void s_abb(char sname[], int x, int y)
{
	int flag=0, xx=0;
	
	do		//to check if there is space in the name of subject
	{
		if(sname[xx]==32)
			flag=1;
	}
	while(sname[xx++]!='\0');
	
	if(flag==1)		//if there is space then abbreviate in this way
	{
		cls[x].sub[y].abb[0]=sname[0];
		int h=1,i=1;
		do
		{
			if(sname[i]==32)
			cls[x].sub[y].abb[h++]=sname[++i];
		}
		while((sname[i++]!='\0') && (h<3));
		cls[x].sub[y].abb[h]='\0';
	}
	
	if(flag==0)	//if there is no space then abbreviate in this way
	{
		cls[x].sub[y].abb[0]=sname[0];
		cls[x].sub[y].abb[1]=sname[1];
		cls[x].sub[y].abb[2]=sname[2];
		cls[x].sub[y].abb[3]='\0';
	}
}






void teach_id(char teach[], int x, int y)
{
	int n, flag1=0, q, r, m;
	
		for(q=0;q<=x;q++)		//to change classes
		{
			for(r=0;r<cls[q].n_sub;r++)		//to change subjects
			{
				if(q==x && r==y)
					continue;
				n=strcmpi(cls[q].sub[r].teacher,cls[x].sub[y].teacher);
				if(n==0)
				{
					flag1=1;		//if flag1=1 that means the name of this teacher has been entered before
					break;
				}
			}
			if(flag1==1)
				break;
		}
		if(flag1==1)									//if the entry of teacher has been done peviously
			cls[x].sub[y].t_id=cls[q].sub[r].t_id;		//assign him the same id
		else											//if the entry of teacher has not been done peviously
			cls[x].sub[y].t_id=tcid++;					//assign him a new id
}





void modify(int x)
{
	int choice, num, pp;
	char strtemp[5];		//temporary string to store number
	puts("\n\n\n\n1. Class Name\n2. Subject Name\n3. Subject Abbreviation\n4. Teacher Name\n5. No. of Classes per Week\n6. Add a subject");
	gets(strtemp);
	choice=atoi(strtemp);
	switch(choice)
	{
	case 1: puts("\n\nEnter Class Name:	");
			gets(cls[x].cname);
			strupr(cls[x].cname);
			break;
	case 2: puts("\n\nEnter Subject Number:	");
			num=atoi(gets(strtemp));
			puts("\nEnter Subject Name:	");
			gets(cls[x].sub[num-1].s_name);
			strupr(cls[x].sub[num-1].s_name);
			s_abb(cls[x].sub[num-1].s_name, x, num-1);		//produce subject abbreviation
			printf("\nSubject Abbreviation:\n%s\n\n",cls[x].sub[num-1].abb);
			break;
	case 3: puts("\n\nEnter Subject Number:	");
			num=atoi(gets(strtemp));
			puts("\nEnter Subject Abbreviation:	");
			gets(cls[x].sub[num-1].abb);
			strupr(cls[x].sub[num-1].abb);
			break;
	case 4: puts("\n\nEnter Subject Number:	");
			num=atoi(gets(strtemp));
			puts("\nEnter Teacher Name:	");
			gets(cls[x].sub[num-1].teacher);
			strupr(cls[x].sub[num-1].teacher);
			teach_id(cls[x].sub[num-1].teacher, x, num);		//to assign an id to the teacher
			printf("\nTeacher id:\n%d\n\n",cls[x].sub[num-1].t_id);
			break;
	case 5: puts("\n\nEnter Subject Number:	");
			num=atoi(gets(strtemp));
			puts("\nEnter Classes per Week:	");
			pp=atoi(gets(strtemp));
			cls[x].sub[num-1].ppw=pp;
			break;
	case 6: cls[x].n_sub++;
			printf("\n\nSubject %d",cls[x].n_sub);
			puts("\n\nEnter Subject name:	");
			gets(cls[x].sub[cls[x].n_sub-1].s_name);
			strupr(cls[x].sub[cls[x].n_sub-1].s_name);
			s_abb(cls[x].sub[cls[x].n_sub-1].s_name, x, cls[x].n_sub-1);		//produce subject abbreviation

			printf("\nSubject Abbreviation:\n%s\n\n",cls[x].sub[cls[x].n_sub-1].abb);

			puts("\nEnter Teacher name:	");		//teacher name
			gets(cls[x].sub[cls[x].n_sub-1].teacher);
		
			teach_id(cls[x].sub[cls[x].n_sub-1].teacher, x, cls[x].n_sub-1);		//to assign an id to the teacher
			printf("\nTeacher id:\n%d\n\n",cls[x].sub[cls[x].n_sub-1].t_id);
			
			puts("Enter No. of Classes per week:	");		//to store no. of classes per week of each subject
			gets(strtemp);
			cls[x].sub[cls[x].n_sub-1].ppw=atoi(strtemp);
			break;
	}
}





void writeinput(int *pn_cl)		//function to write the data in binary form to the file after arrangement
{
	FILE *fptr;
	
	fptr=fopen("class.txt","w");
	fprintf(fptr,"%d",*pn_cl);
	
	fptr=fopen("data.txt","wb");	
	fwrite(cls,sizeof(cls[0]),10,fptr);
	fclose(fptr);
	printf("\nend filing input");
}





void arrange(int *pn_cl)
{
	int r, flag;
	
	
	strcpy(days[0].dayname,"MON");		//to save daynames in structures
	strcpy(days[1].dayname,"TUE");
	strcpy(days[2].dayname,"WED");
	strcpy(days[3].dayname,"THU");
	strcpy(days[4].dayname,"FRI");
	
	
	for(int a=0;a<5;a++)		//for days
	{
		static int count_day[10][12];		//to ensure that a subject has periods not more than two in a day
		for (int b=0;b<*pn_cl;b++)		//for classes
		{
			for(int c=0;c<8;c++)		//for periods
			{
				int cc=0;
				do
				{
					cc++;
					r=rand()%cls[b].n_sub;		//choose a number out of the total no. of subjects
					flag=1;
					if(count_week[b][r]==cls[b].sub[r].ppw)		//to check that the subject classes are not exceeding periods per week & to ensure that a subject has periods not more than two in a day
							flag=0;
						
					if(flag==1)
					{
						for(int e=0;e<b;e++)			//for checking the availability of teacher
						{
							if((cls[b].sub[r].t_id==days[a].clas_s[e].p_t[c].tc_id) || (count_day[b][r]>1))
								flag=0;
						}
						if(cc>=30)		//if the loop is repeated 30 times but the clash has not been resolved then arrange it anyway
							flag=1;
					}
				}
				while(flag==0);
				strcpy(days[a].clas_s[b].p_t[c].period,cls[b].sub[r].abb);
				days[a].clas_s[b].p_t[c].tc_id=cls[b].sub[r].t_id;		//to assign teacher id to the arrangement structure
				count_day[b][r]++;
				count_week[b][r]++;		//to increase subject classes in a week count by 1;
			}
		}
	}
	printf("\nend arrange");
}





void writearrange(int *pn_cl)		//to file timetable
{
	FILE *fptr;
	fptr=fopen("timetable.txt","wb");		//to store time table
	fwrite(days,sizeof(days[0]),5,fptr);
	fclose(fptr);
	printf("\nend filing arrange");
}




void readfile(int *pn_cl)		//to read data from file
{
	FILE *fptr;
	fptr=fopen("class.txt","r");
	fscanf(fptr,"%d",pn_cl);
	fclose(fptr);
	
	fptr=fopen("data.txt","rb");	
	fread(cls,sizeof(cls[0]),10,fptr);
	fclose(fptr);
	
	fptr=fopen("timetable.txt","rb");		//to store time table
	fread(days,sizeof(days[0]),5,fptr);
	fclose(fptr);
}
	
	
	
	
	
	
	
	
	
	
	

