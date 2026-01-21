/*
Name :K.Mowleeshwaran
Date :
Description :
sample input :
sample output :
 */

#include<stdio.h>
#include<string.h>
#include"main.h"
FILE *file4;
int print()
{
    char fn[50];
    printf("Enter the file name that you want to search: ");
    scanf("%s",fn);
    printf("\n");
    if((strcmp(strstr(fn,"."),".csv")))
    {
	printf("it is not .csv file\n");
	return 0;
    }
    else
    {
	FILE *fptr=fopen(fn,"r");
	if(fptr!=NULL)
	{
	    file4=fptr;
	}
	else
	{
	    printf("File not opened\n");
	    return 0;
	}
    }
    rewind(file4);
    char num[100];
    fscanf(file4,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file4,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file4))
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
	printf("Name: %s\nMobile Number: %s\nMail ID: %s\nLocation: %s\n",buff1,mn,mid,lo);
    }
}
