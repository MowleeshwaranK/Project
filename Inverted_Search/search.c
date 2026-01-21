#include<stdio.h>
#include"invert.h"
int searching(hash arr[],char str[])
{
    int t=0;
    for (int i=0;i<28;i++)
    {
	if(arr[i].h_link==NULL)
	{
	    t=t+1;
	}
    }
    if(t==28)
    {
	printf("Database Not Created\n");
	return LIST_EMPTY;
    }
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
    Mnodelist *temp=arr[index].h_link;
    while(temp!=NULL)
    {
	if(!(strcmp(temp->word,str)))
	{
	    
	    if(index==26)
	    {
		printf("[%d]-%s-%d",index,temp->word,temp->filecount);
	    }
	    else if(index==27)
	    {
		printf("[%d]-%s-%d",index,temp->word,temp->filecount);
	    }
	    else
	    {
		printf("[%d]-%s-%d",index,temp->word,temp->filecount);
	    }
	    Snodelist *temp1=temp->Slink;
	    while(temp1!=NULL)
	    {
		printf("-->%d-%s",temp1->word_count,temp1->file_name);

		temp1=temp1->Slink;
	    }
	    printf("-->NULL\n");
	    return SUCCESS;
	}
	temp=temp->Mlink;
    }
    return FAILURE;
}


