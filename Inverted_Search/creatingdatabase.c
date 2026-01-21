#include<stdio.h>
#include"invert.h"

int creating_database(Slist *head,hash arr[])
{
    Slist *temp=head;
    while(temp!=NULL)
    {
	//printf("checking=%s\n",temp->file);
	FILE *fptr=fopen(temp->file,"r");
	if(fptr==NULL)
	{
	    printf("NULL-%s\n",temp->file);
	    break;
	}
	printf("Database created for %s\n",temp->file);
	/*
	else
	{
	    printf("opened-%s %p\n",temp->file,temp->link);
	}*/

	int i=1;
	while(i)
	{
	    char str[50];
	    fscanf(fptr,"%s",str);
	    //printf("%s ",str);
	    if(feof(fptr))
	    {
		break;
	    }
	    //printf("%s ",str);
	    int index;
	    if((str[0]>=48) && (str[0]<=57))
	    {
		index=26;
	    }
	    else if(((str[0]>=33) && (str[0]<=47))||(str[0]>=58) && (str[0]<=63))
	    {
		index=27;
	    }
	    else
	    {
		 index=(tolower(str[0])-97);
	    }
		//printf("%d",index);
		if(arr[index].h_link==NULL)
		{
		    Snodelist *s_new=malloc(sizeof(Snodelist));
		    strcpy(s_new->file_name,temp->file);
		    s_new->word_count=1;
		    s_new->Slink=NULL;
		    Mnodelist *m_new=malloc(sizeof(Mnodelist));
		    m_new->filecount=1;
		    strcpy(m_new->word,str);
		    m_new->Slink=s_new;
		    m_new->Mlink=NULL;
		    arr[index].h_link=m_new;
		}
		else
		{
		    Mnodelist *t=arr[index].h_link;
		    Mnodelist *adres;
		    int check=0;
		    while(t!=NULL)
		    {
			adres=t;
			//printf("check  ==%s %s\n",t->word,str);
			if(!(strcmp(str,t->word)))
			{
			    check=1;
			    Snodelist *temp1=t->Slink;
			    Snodelist *add;
			    int c=0;
			    while(temp1!=NULL)
			    {
				add=temp1;
				if(!(strcmp(temp1->file_name,temp->file)))
				{
				    c=1;
				    temp1->word_count=(temp1->word_count)+1;
				}
				temp1=temp1->Slink;
			    }
			    if(c==0)
			    {
				t->filecount=t->filecount+1;
				Snodelist *s_new=malloc(sizeof(Snodelist));
				strcpy(s_new->file_name,temp->file);
				s_new->word_count=1;
				add->Slink=s_new;
			    }
			}
			t=t->Mlink;
		    }
		    if(check==0)
		    {
			Snodelist *s_new=malloc(sizeof(Snodelist));
			strcpy(s_new->file_name,temp->file);
			s_new->word_count=1;
			s_new->Slink=NULL;
			Mnodelist *m_new=malloc(sizeof(Mnodelist));
			m_new->filecount=1;
			strcpy(m_new->word,str);
			m_new->Slink=s_new;
			m_new->Mlink=NULL;
			adres->Mlink=m_new;
		    }
		}
	    
	}
	temp=temp->link;
    }
}

