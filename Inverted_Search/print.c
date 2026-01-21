

#include<stdio.h>
#include"invert.h"

int print(hash arr[])
{
    printf("----------------------------------------------------------\n");
    printf("Index\tword\tFile count\tfile name\tword count\n");
    printf("----------------------------------------------------------\n");
    for(int i=0;i<28;i++)
    {
	if(arr[i].h_link!=NULL)
	{
	    Mnodelist *temp=arr[i].h_link;
	    while(temp!=NULL)
	    {
		Snodelist *temp1=temp->Slink;
		int c=0;
		while(temp1!=NULL)
		{
		    c=c+1;
		    printf("%d\t",i);
		    if(c==1)
		    {
			printf("%s\t\t",temp->word);
		        printf("%d\t",temp->filecount);
		    }
		    else
		    {
			printf("\t\t");
			printf("\t");
		    }
		    printf("%s\t",temp1->file_name);
		    printf("%d\n",temp1->word_count);
		    temp1=temp1->Slink;
		}
		temp=temp->Mlink;
	    }
	    printf("----------------------------------------------------------\n");
	}
    
    }
}





