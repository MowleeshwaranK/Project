
#include<stdio.h>
#include"invert.h"
#include<string.h>
#include<stdlib.h>
int read_and_validate(int argc,char **argv)
{
    int c=0;
    for (int i=1;i<argc;i++)
    {
	if(!(strcmp(strstr(argv[i],"."),".txt")))
	{
	    c=c+1;
	}
    }
    if(c==argc-1)
    {
	return SUCCESS;
    }
    else
    {
	return FAILURE;
    }
}
int check_file_exist(int argc,char **argv)
{
    //printf("argv=%d\n",argc);
    int c=0;
    int s=0;
    for (int i=1;i<argc;i++)
    {
	FILE *fptr=fopen(argv[i],"r");
	if(fptr==NULL)
	{
	    printf("%s is not in the directory\n",argv[i]);
	    c=1;
	}
    }
    if(c==1)
    {
	return FAILURE;
    }
    else
    {
	return SUCCESS;
    }
}
int check_file_empty(int argc,char **argv)
{
    int c1=0;
    for (int i=1;i<argc;i++)
    {
	FILE *fptr=fopen(argv[i],"r");
	fseek(fptr,0,SEEK_SET);
	fseek(fptr,0,SEEK_END);
	int a=ftell(fptr);
	//rewind(fptr);
	//printf("a= %d\n",a);
	if(a<=1)
	{
	    c1=1;
	    printf("%s is Empty File\n",argv[i]);
	    //return FAILURE;
	}
    }
	return SUCCESS;
}

int Duplicate(int argc,char **argv,Slist **head)
{
    int arr[argc-1];
    for (int i=0;i<argc-1;i++)
    {
	arr[i]=1;
    }
    for (int i=1;i<argc;i++)
    {
	int c=0;
	for (int j=1;j<argc;j++)
	{
	    if(arr[j-1]!=0)
	    {
		if(!(strcmp(argv[i],argv[j])))
		{
		    c=c+1;
	     if(c>1)
		    {
			arr[j-1]=0;
		    }
		}
	    }
	}
    }
    
    for (int i=1;i<argc;i++)
    {
	if(arr[i-1]==1)
	{
	    Slist *new=malloc(sizeof(Slist));
	    strcpy(new->file,argv[i]);
	    new->link=NULL;
	    if(*head==NULL)
	    {
		*head=new;
	    }
	    else
	    {
		Slist *temp=*head;
		while(temp->link!=NULL)
		{
		    temp=temp->link;
		}
		temp->link=new;
	    }
	}
	else
	{
	    printf("%s is empty file\n",argv[i]);
	}
    }
    return SUCCESS;
}












