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
FILE *file1;
int edit()
{
    char fn[50];
    printf("Enter the file name that you want to edit: ");
    scanf("%s",fn);
    if((strcmp(strstr(fn,"."),".csv")))
    {
	printf("it is not .csv file\n");
	return 0;
    }
    else
    {
	FILE *fptr=fopen(fn,"r+");
	if(fptr!=NULL)
	{
	    file1=fptr;
	}
	else
	{
	    printf("File not opened\n");
	    return 0;
	}
    }

    char y='y';
    while(y=='y' ||y=='Y')
    {
	printf("1.Name\n2.number\n3.mail id\n4.Location\n");
	int t;
	scanf("%d",&t);
	if(t==1)
	{
	    getchar();
	    char str[100];
	    char str1[100];
	    printf("Enter the Name: ");
	    scanf("%[^\n]",str);
	    getchar();
	    printf("Enter new name: ");
	    scanf("%[^\n]",str1);
	    editname(str,str1,fn);

	}
	else if(t==2)
	{
	    char str[100];
	    char str1[100];
	    getchar();
	    printf("Enter the Mobile number: ");
	    scanf("%[^\n]",str);
	    getchar();
	    printf("Enter new Mobile number: ");
	    scanf("%[^\n]",str1);
	    editnum(str,str1,fn);
	}
	else if(t==3)
	{
	    char str[100];
	    char str1[100];
	    getchar();
	    printf("Enter the Mail ID: ");
	    scanf("%[^\n]",str);
	    getchar();
	    printf("Enter new Mail ID: ");
	    scanf("%[^\n]",str1);
	    editmid(str,str1,fn);
	}

	else if(t==4)
	{
	    char str[100];
	    char str1[100];
	    getchar();
	    printf("Enter the Location: ");
	    scanf("%[^\n]",str);
	    getchar();
	    printf("Enter new Location: ");
	    scanf("%[^\n]",str1);
	    editl(str,str1,fn);
	}
	printf("Do you want to continue to edit(Y/y): ");
	getchar();
	scanf("%c",&y);
    }
    fclose(file1);
}
int editl(char str[],char str1[],char fn[])
{
    rewind(file1);
    FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file1,"%s",num);
    fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file1,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file1))
	{
	    break;
	}
	char buff1[30];
	int i;
	for( i=0;buff[i]!='\0';i++)
	{
	    if(buff[i]!=',')
	    {
		buff1[i]=buff[i];
	    }
	    else
	    {
		buff1[i]='\0';
		break;
	    }
	}
	i++;
	int j;
	char mn[30];
	int u=0;
	for (j=i;buff[j]!='\0';j++)
	{
	    if(buff[j]!=',')
	    {
		mn[u]=buff[j];
	    }
	    else
	    {
		mn[u]='\0';
		break;
	    }
	    u=u+1;
	}
	//printf("n==%s\n",mn);
	j++;
	char mid[30];
	int k;
	int u1=0;
	for (k=j;buff[k]!='\0';k++)
	{
	    if(buff[k]!=',')
	    {
		mid[u1]=buff[k];
	    }
	    else
	    {
		mid[u1]='\0';
		break;
	    }
	    u1++;
	}
	k++;
	char lo[30];
	int l;
	int u2=0;
	for (l=k;buff[l]!='\0';l++)
	{
	    if(buff[l]!=',')
	    {
		lo[u2]=buff[l];
	    }
	    else
	    {
		lo[u2]='\0';
		break;
	    }
	    u2++;
	}
	//printf("new=====%s,%s,%s,%s\n",buff1,mn,mid,lo);
	if(!(strcmp(lo,str)))
	{
	        check=1;
		printf("Name: %s\nMobile Number: %s\nMail ID: %s\nLocation: %s\n",buff1,mn,mid,lo);
		getchar();
		printf("Do you want to change this one(y/Y): ");
		char r;
		scanf("%c",&r);
		if(r=='Y' || r=='y')
		{
		    fprintf(temp,"\n");
		    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,str1);
		}
		else
		{
		    fprintf(temp,"\n");
		    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,lo);
		}
	}
	else
	{
	    fprintf(temp,"\n");
	    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,lo);
	}
    }
    if(check==0)
    {
	printf("Entered name is not in the file\n");
	return 0;
    }
    rewind(temp);
    fclose(file1);
    file1=fopen(fn,"w");
    //rewind(file1);
    char num2[100];
    fscanf(temp,"%s",num2);
    int a=atoi(strtok(&num2[0],"#"));
    char num1[100];
    rewind(temp);
    fscanf(temp,"%s",num1);
    printf("a=%d\n",a);
    fprintf(file1,"%s\n",num1);
   // printf("-------------------------------\n");
    while(a--)
    {
	char buff[500];
	fscanf(temp,"%s",buff);
	//printf("%s\n",buff);
	fprintf(file1,"%s\n",buff);

    }
    fclose(temp);
    fclose(file1);
    FILE *fptr=fopen(fn,"r+");
    if(fptr!=NULL)
    {
	file1=fptr;
    }
    rewind(file1);
	   
}
	
int editmid(char str[],char str1[],char fn[])
{
    rewind(file1);
    FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file1,"%s",num);
    fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file1,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file1))
	{
	    break;
	}
	char buff1[30];
	int i;
	for( i=0;buff[i]!='\0';i++)
	{
	    if(buff[i]!=',')
	    {
		buff1[i]=buff[i];
	    }
	    else
	    {
		buff1[i]='\0';
		break;
	    }
	}
	i++;
	int j;
	char mn[30];
	int u=0;
	for (j=i;buff[j]!='\0';j++)
	{
	    if(buff[j]!=',')
	    {
		mn[u]=buff[j];
	    }
	    else
	    {
		mn[u]='\0';
		break;
	    }
	    u=u+1;
	}
	printf("n==%s\n",mn);
	j++;
	char mid[30];
	int k;
	int u1=0;
	for (k=j;buff[k]!='\0';k++)
	{
	    if(buff[k]!=',')
	    {
		mid[u1]=buff[k];
	    }
	    else
	    {
		mid[u1]='\0';
		break;
	    }
	    u1++;
	}
	k++;
	char lo[30];
	int l;
	int u2=0;
	for (l=k;buff[l]!='\0';l++)
	{
	    if(buff[l]!=',')
	    {
		lo[u2]=buff[l];
	    }
	    else
	    {
		lo[u2]='\0';
		break;
	    }
	    u2++;
	}
	//printf("new=====%s,%s,%s,%s\n",buff1,mn,mid,lo);
	if(!(strcmp(mid,str)))
	{
	    check=1;

	    fprintf(temp,"\n");
	    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,str1,lo);
	}
	else
	{
	    fprintf(temp,"\n");
	    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,lo);
	}
    }
    if(check==0)
    {
	printf("Entered name is not in the file\n");
	return 0;
    }
    rewind(temp);
    fclose(file1);
    file1=fopen(fn,"w");
    //rewind(file1);
    char num2[100];
    fscanf(temp,"%s",num2);
    int a=atoi(strtok(&num2[0],"#"));
    char num1[100];
    rewind(temp);
    fscanf(temp,"%s",num1);
   // printf("a=%d\n",a);
    fprintf(file1,"%s\n",num1);
    //printf("-------------------------------\n");
    while(a--)
    {
	char buff[500];
	fscanf(temp,"%s",buff);
//	printf("%s\n",buff);
	fprintf(file1,"%s\n",buff);

    }
    fclose(temp);
    fclose(file1);
    FILE *fptr=fopen(fn,"r+");
    if(fptr!=NULL)
    {
	file1=fptr;
    }
    rewind(file1);
	   
}
int editnum(char str[],char str1[],char fn[])
{
    rewind(file1);
    FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file1,"%s",num);
    fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file1,"%s",buff);
//	printf("%s\n",buff);
	if(feof(file1))
	{
	    break;
	}
	char buff1[30];
	int i;
	for( i=0;buff[i]!='\0';i++)
	{
	    if(buff[i]!=',')
	    {
		buff1[i]=buff[i];
	    }
	    else
	    {
		buff1[i]='\0';
		break;
	    }
	}
	i++;
	int j;
	char mn[30];
	int u=0;
	for (j=i;buff[j]!='\0';j++)
	{
	    if(buff[j]!=',')
	    {
		mn[u]=buff[j];
	    }
	    else
	    {
		mn[u]='\0';
		break;
	    }
	    u=u+1;
	}
//	printf("n==%s\n",mn);
	j++;
	char mid[30];
	int k;
	int u1=0;
	for (k=j;buff[k]!='\0';k++)
	{
	    if(buff[k]!=',')
	    {
		mid[u1]=buff[k];
	    }
	    else
	    {
		mid[u1]='\0';
		break;
	    }
	    u1++;
	}
	k++;
	char lo[30];
	int l;
	int u2=0;
	for (l=k;buff[l]!='\0';l++)
	{
	    if(buff[l]!=',')
	    {
		lo[u2]=buff[l];
	    }
	    else
	    {
		lo[u2]='\0';
		break;
	    }
	    u2++;
	}
	//printf("new=====%s,%s,%s,%s\n",buff1,mn,mid,lo);
	if(!(strcmp(mn,str)))
	{
	    check=1;

	    fprintf(temp,"\n");
	    fprintf(temp,"%s,%s,%s,%s,",buff1,str1,mid,lo);
	}
	else
	{
	    fprintf(temp,"\n");
	    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,lo);
	}
    }
    if(check==0)
    {
	printf("Entered name is not in the file\n");
	return 0;
    }
    rewind(temp);
    fclose(file1);
    file1=fopen(fn,"w");
    //rewind(file1);
    char num2[100];
    fscanf(temp,"%s",num2);
    int a=atoi(strtok(&num2[0],"#"));
    char num1[100];
    rewind(temp);
    fscanf(temp,"%s",num1);
   // printf("a=%d\n",a);
    fprintf(file1,"%s\n",num1);
    //printf("-------------------------------\n");
    while(a--)
    {
	char buff[500];
	fscanf(temp,"%s",buff);
	//printf("%s\n",buff);
	fprintf(file1,"%s\n",buff);

    }
    fclose(temp);
    fclose(file1);
    FILE *fptr=fopen(fn,"r+");
    if(fptr!=NULL)
    {
	file1=fptr;
    }
    rewind(file1);
}
int editname(char str[],char str1[],char fn[])
{
    rewind(file1);
    FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file1,"%s",num);
    fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[500];
	fscanf(file1,"%s",buff);
//	printf("check=%s\n",buff);
	if(feof(file1))
	{
	    break;
	}
	int d=4;
	char buff1[30];
	int i;
	for( i=0;buff[i]!='\0';i++)
	{
	    if(buff[i]!=',')
	    {
		buff1[i]=buff[i];
	    }
	    else
	    {
		buff1[i]='\0';
		break;
	    }
	}
	i++;
	int j;
	char mn[30];
	int u=0;
	for (j=i;buff[j]!='\0';j++)
	{
	    if(buff[j]!=',')
	    {
		mn[u]=buff[j];
	    }
	    else
	    {
		mn[u]='\0';
		break;
	    }
	    u=u+1;
	}
//	printf("n==%s\n",mn);
	j++;
	char mid[30];
	int k;
	int u1=0;
	for (k=j;buff[k]!='\0';k++)
	{
	    if(buff[k]!=',')
	    {
		mid[u1]=buff[k];
	    }
	    else
	    {
		mid[u1]='\0';
		break;
	    }
	    u1++;
	}
	k++;
	char lo[30];
	int l;
	int u2=0;
	for (l=k;buff[l]!='\0';l++)
	{
	    if(buff[l]!=',')
	    {
		lo[u2]=buff[l];
	    }
	    else
	    {
		lo[u2]='\0';
		break;
	    }
	    u2++;
	}
//	printf("new=====%s,%s,%s,%s\n",buff1,mn,mid,lo);
	char *add=strstr(strtok(buff,","),str);
	if(add!=NULL)
	{
	    check=1;
	    int l1=strlen(add);
	    int l2=strlen(str);
	    if(l1==l2)
	    {
		fprintf(temp,"\n");
		fprintf(temp,"%s,%s,%s,%s,",str1,mn,mid,lo);
	    }
	    else
	    {
		printf("name : %s\n",buff1);
		getchar();
		printf("Do you want to change this one(y/Y): ");
		char r;
		scanf("%c",&r);
		if(r=='Y' || r=='y')
		{
		    fprintf(temp,"\n");
		    fprintf(temp,"%s,%s,%s,%s,",str1,mn,mid,lo);
		}
		else
		{
		    fprintf(temp,"\n");
		    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,lo);
		}
	    }
	}
	else
	{
	    //char *add=strtok(buff,",");
	    //int l1=strlen(add);
	    fprintf(temp,"\n");
	    fprintf(temp,"%s,%s,%s,%s,",buff1,mn,mid,lo);
	}

    }
    if(check==0)
    {
	printf("Entered name is not in the file\n");
	return 0;
    }
    rewind(temp);
    fclose(file1);
    file1=fopen(fn,"w");
    //rewind(file1);
    char num2[100];
    fscanf(temp,"%s",num2);
    int a=atoi(strtok(&num2[0],"#"));
    char num1[100];
    rewind(temp);
    fscanf(temp,"%s",num1);
    //printf("a=%d\n",a);
    fprintf(file1,"%s\n",num1);
    //printf("-------------------------------\n");
    while(a--)
    {
	char buff[500];
	fscanf(temp,"%s",buff);
	//printf("%s\n",buff);
	fprintf(file1,"%s\n",buff);

    }
    fclose(temp);
    fclose(file1);
    FILE *fptr=fopen(fn,"r+");
    if(fptr!=NULL)
    {
	file1=fptr;
    }
    rewind(file1);
    //return;
}
