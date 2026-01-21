/*
Name :K.Mowleeshwaran
Date :
Description :
sample input :
sample output :
 */

#include<stdio.h>
#include"main.h"
#include<string.h>
#include<stdlib.h>
FILE *file;
int main()
{
    char y='y';
    while(y=='y' ||y=='Y')
    {
	printf("1.Add\n2.edit\n3.search\n4.delete\n5.print\n");
	int t;
	printf("Enter your choice: ");
	scanf("%d",&t);
	if(t==1)
	{
	    add();
	}
	else if(t==2)
	{
	    edit();
	}
	else if(t==3)
	{
	    search();
	}
	else if(t==4)
	{
	    delete_();
	}
	else if(t==5)
	{
	    print();
	}

	printf("Do you want to continue(Y/y): ");
	getchar();
	scanf("%c",&y);
    }

    return 0;
}
int add()
{
    char str[50];
    struct temp
    {
	char name[50];
	char mn[50];
	char mid[50];
	char l[50];
    };
    printf("Enter the file name that you want to add: ");
    scanf("%s",str);
    if((strcmp(strstr(str,"."),".csv")))
    {
	printf("it is not .csv file\n");
	return 0;
    }
    else
    {
	FILE *fptr=fopen(str,"r");
	if(fptr!=NULL)
	{
	    file=fptr;
	}
	else
	{
	    printf("File not opened\n");
	    return 0;
	}
    }

    struct temp stu;
    int arr[4]={1,1,1,1};
    int f1,f2,f3,f4;
    f1=f2=f3=f4=0;
    char y='y';
    while(y=='y' ||y=='Y')
    {
	printf("1.Name\n2.number\n3.mail id\n4.Location\n");
	int t;
	scanf("%d",&t);
	if(t==1)
	{
	    f1=1;
	    getchar();
	    printf("Enter the Name: ");
	    scanf("%[^\n]",stu.name);
	    rewind(file);
	    if(checkname(stu.name)==0)
	    {
		arr[0]=0;
	    }
	    else
	    {
	       	arr[0]=1;
		
	    }

	}
	else if(t==2)
	{
	    f2=1;
	    printf("Enter the Mobile Number: ");
	    scanf("%s",stu.mn);
	    if(checknum(stu.mn)==0)
	    {
		arr[1]=0;
	    }
	    else
	    {

		arr[1]=1;

	    }

	}
	else if(t==3)
	{
	    f3=1;
	    printf("Enter the Mail ID: ");
	    scanf("%s",stu.mid);
	    if(checkmid(stu.mid)==0)
	    {
		arr[2]=0;
	    }
	    else
	    {
		arr[2]=1;

	    }
	}
	else if(t==4)
	{
	    f4=1;
	    printf("Enter the Location: ");
	    scanf("%s",stu.l);
	}
	printf("Do you want to continue to add(Y/y): ");
	getchar();
	scanf("%c",&y);
    }
    int s=0;
    for (int i=0;i<4;i++)
    {
	if(arr[i]==1)
	{
	    s=s+1;
	}
	//printf("%d ",arr[i]);
    }

    if(s==4)
    {
	fclose(file);
	file=fopen(str,"r+");
	char str2[100];
	fscanf(file,"%s",str2);
	int a=atoi(strtok(&str2[1],"#"));
	int w=a;
	while(a--)
	{
	    char str[100];
	    fscanf(file,"%s",str);
	}
	fprintf(file,"\n");

//	printf("ftell=%d\n",ftell(file));
	char str1[500];
	//strcpy(stu.name,"");
	if(f1==0)
	{
	    fprintf(file,",");
	}
	else
	{
	    //strcpy(str1,stu.name);
	    fprintf(file,"%s,",stu.name);
	}
	if(f2==0)
	{
	    fprintf(file,",");
	    //(stu.mn)[0]="";
	}
	else
	{
	    //strcat(str1,stu.mn);
	    fprintf(file,"%s,",stu.mn);
	}
	if(f3==0)
	{
	    //strcpy(stu.mid,"");
	    //strcat(str1,",");
	   fprintf(file,",");
	    //(stu.mid)[0]="";
	}
	else
	{
	    //strcat(str1,stu.mid);
	    fprintf(file,"%s,",stu.mid);
	}
	if(f4==0)
	{
	   // strcpy(stu.l,"");
	   // strcat(str1,",");
	    fprintf(file,",");
	    //(stu.l)[0]="";
	    //(stu.l)[1]='\n';
	}
	else
	{
	    //strcat(str1,stu.l);
	    fprintf(file,"%s,",stu.l);
	}
	rewind(file);
	fprintf(file,"#%d#",w+1);
	fclose(file);

    }
    else
    {
	printf("Problem in Entering the details\n");
    }
}
int checkmid(char stu[])
{
    if(strstr(stu,"@")!=NULL)
    {
	if(strstr(stu,".")!=NULL)
	{
	    if((strcmp(strstr(stu,"."),".com")))
	    {
		printf("Enter .com mail id\n");
		return 0;
	    }
	    return 1;
	}
	else
	{
	    printf("Enter .com in mail id\n");
	    return 0;
	}
    }
    else
    {
	printf("Enter @ in mail id\n");
	return 0;
    }
}

int checknum(char stu[])
{
    int c=0;
    if(strlen(stu)==10)
    {
	for (int i=0;stu[i]!='\0';i++)
	{
	    if(stu[i]>='0' && stu[i]<='9')
	    {
		c=1;
	    }
	    else
	    {
		c=0;
		printf("Enter digits\n");
		return 0;
	    }
	}
	if(c)
	{
	    return 1;
	}
    }
    else
    {
	printf("Enter 10 digit\n");
	return 0;
    }
}
int checkname(char stu[])
{

    char str[100];
    fscanf(file,"%s",str);
    while(1)
    {
	char str[100];
	fscanf(file,"%s",str);
	if(feof(file))
	{
	    break;
	}
	if(!(strcmp(strtok(str,","),stu)))
	{
	    printf("Entered name is already there try  again\n");
	    return 0;
	}
    }
    return 1;
}







