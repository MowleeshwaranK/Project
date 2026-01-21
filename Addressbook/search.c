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
FILE *file2;
int search()
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
	    file2=fptr;
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
	    printf("Enter the Name: ");
	    scanf("%[^\n]",str);
	    searchname(str);
	}
	if(t==2)
	{
	    getchar();
	    char str[100];
	    printf("Enter the Mobile Number: ");
	    scanf("%[^\n]",str);
	    searchm(str);
	}
	if(t==3)
	{
	    getchar();
	    char str[100];
	    printf("Enter the Mail ID: ");
	    scanf("%[^\n]",str);
	    searchmid(str);
	}
	if(t==4)
	{
	    getchar();
	    char str[100];
	    printf("Enter the Location: ");
	    scanf("%[^\n]",str);
	    searchl(str);
	}
	printf("Do you want to continue to search(Y/y): ");
	getchar();
	scanf("%c",&y);
    }
    fclose(file2);

}
int searchl(char str[])
{
    rewind(file2);
    // FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file2,"%s",num);
    //fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file2,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file2))
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
	}
    }

    if(check==0)
    {
	printf("Entered Location is not in the file\n");
    }
    

}



int searchmid(char str[])
{
    rewind(file2);
    // FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file2,"%s",num);
    //fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file2,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file2))
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
	if(!(strcmp(mid,str)))
	{
	    check=1;
	    printf("Name: %s\nMobile Number: %s\nMail ID: %s\nLocation: %s\n",buff1,mn,mid,lo);
	}
    }

    if(check==0)
    {
	printf("Entered Mail Id is not in the file\n");
    }

}





int searchm(char str[])
{

    rewind(file2);
    // FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file2,"%s",num);
    //fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[100];
	fscanf(file2,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file2))
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
//	printf("new=====%s,%s,%s,%s\n",buff1,mn,mid,lo);
	if(!(strcmp(mn,str)))
	{
	    check=1;
	    printf("Name: %s\nMobile Number: %s\nMail ID: %s\nLocation: %s\n",buff1,mn,mid,lo);
	}
    }

    if(check==0)
    {
	printf("Entered Mobile Number is not in the file\n");
    }

}


int searchname(char str[])
{
    rewind(file2);
    // FILE *temp=fopen("temp.csv","w+");
    char num[100];
    fscanf(file2,"%s",num);
    //fprintf(temp,"%s",num);
    int check=0;
    while(1)
    {
	char buff[500];
	fscanf(file2,"%s",buff);
	//printf("%s\n",buff);
	if(feof(file2))
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
	char *add=strstr(buff1,str);
	if(add!=NULL)
	{
	    check=1;
	    printf("Name: %s\nMobile Number: %s\nMail ID: %s\nLocation: %s\n",buff1,mn,mid,lo);
	}
    }
    if(check==0)
    {
	printf("Entered name is not in the file\n");
    }


}


