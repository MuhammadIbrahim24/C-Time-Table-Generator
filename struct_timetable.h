#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
//(								FOR INPUT
struct subject
{
	char s_name[20];
	char abb[5];
	char teacher[30];
	int t_id;
	int ppw;		//periods per week
};

struct classs
{
	char cname[5];
	int n_sub;		//no. of subjects
	struct subject sub[12];
};

struct classs cls[10]={0};;
//)





//(								FOR ARRANGEMENT
struct p_and_t			//for relation between subjects and teachers
{
	int tc_id;
	char period[5];
};

struct clas
{
	struct p_and_t p_t[8];
};

struct day
{
	char dayname[4];
	struct clas clas_s[10];
};
struct day days[5]={0};;


//)
