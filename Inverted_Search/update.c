

#include<stdio.h>
#include"invert.h"
//char string[100][100];
int update_data(hash arr[],char file1[],Slist **head)
{
    if(!strcmp(strstr(file1,"."),".txt"))
    {
	FILE *fptr=fopen(file1,"r");
	if(fptr!=NULL)
	{
	    fseek(fptr,0,SEEK_SET);
	    fseek(fptr,0,SEEK_END);
	    int a=ftell(fptr);
	    if(a!=0&&a!=1)
	    {
		if(working_of_update(arr,file1,head)==FAILURE)
		{
		    return FAILURE;
		}
		else
		{
		    return SUCCESS;
		}
	    }
	    else
	    {
		printf("%s is empty\n",file1);
		return FAILURE;
	    }
	}
	else
	{
	    printf("File is not in the directory\n");
	    return FAILURE;
	}
    }
    else
    {
	printf("Please pass the .txt extension file\n");
	return FAILURE;
    }
}
int working_of_update(hash arr[],char file1[],Slist **head)
{
    for (int i=0;i<28;i++)
    {
	if(arr[i].h_link!=NULL)
	{
	    printf("Database is already created\n");
	    return FAILURE;
	}
    }
    FILE *fptr=fopen(file1,"r");

    char str[500];
    fscanf(fptr,"%s",str);
    if(str[0]!='#')
    {
	printf("It is not the backup file\n");
	return FAILURE;
    }
    rewind(fptr);
    int j=1;
    while(j)
    {
	char str[500];
	fscanf(fptr,"%s",str);
	//printf("string=%s\n",str);
	if(feof(fptr))
	{
	    break;
	}
	int index=atoi(strtok(&str[1],";"));
	//printf("%d",index);
	Mnodelist *m_new=malloc(sizeof(Mnodelist));
	char w[50];
	strcpy(m_new->word,strtok(NULL,";"));
	//printf("w=%s\n",m_new->word);
	int fc=atoi(strtok(NULL,";"));
	//printf("fc=%d\n",fc);
	m_new->filecount=fc;
	int c=0;
	Snodelist *temp;
	for (int i=0;i<fc;i++)
	{
	    c=c+1;
	    Snodelist *s_new=malloc(sizeof(Snodelist));
	    char wordcp[50];
	    strcpy(wordcp,strtok(NULL,";"));
	    fun(wordcp,head);
	    strcpy(s_new->file_name,wordcp);
	    int wc=atoi(strtok(NULL,";"));
	    //printf("wc=%d\n",wc);
	    s_new->word_count=wc;
	    s_new->Slink=NULL;
	    if(c==1)
	    {
		m_new->Slink=s_new;
		temp=m_new->Slink;
	    }
	    else
	    {
		while(temp->Slink!=NULL)
		{
		    temp=temp->Slink;
		}
		temp->Slink=s_new;
	    }
	}
	m_new->Mlink=NULL;
	if(arr[index].h_link==NULL)
	{
	    arr[index].h_link=m_new;
	}
	else
	{
	    Mnodelist *temp1=arr[index].h_link;
	    while(temp1->Mlink!=NULL)
	    {
		temp1=temp1->Mlink;
	    }
	    temp1->Mlink=m_new;
	}

    }
    return SUCCESS;
}
int fun(char str[],Slist **head)
{
    Slist *temp=*head;
    Slist *add;
    while(temp!=NULL)
    {
	if(!(strcmp(temp->file,str)))
	{
	    if(temp==*head)
	    {
		if(temp->link==NULL)
		{
		    free(temp);
		    *head=NULL;
		    return SUCCESS;
		}
		else
		{
		    *head=temp->link;
		    free(temp);
		    return SUCCESS;
		}
	    }
	    else
	    {
		add->link=temp->link;
		free(temp);
		return SUCCESS;
	    }
	}
	add=temp;
	temp=temp->link;
    }
}
