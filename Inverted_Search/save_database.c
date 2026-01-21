#include"invert.h"
int save_database(char file[],hash arr[])
{
    if(!(strcmp(strstr(file,"."),".txt")))
    {
	FILE *fptr=fopen(file,"w");
	for(int i=0;i<28;i++)
	{
	    if(arr[i].h_link!=NULL)
	    {
		Mnodelist *temp=arr[i].h_link;
		while(temp!=NULL)
		{
		    Snodelist *temp1=temp->Slink;
		    int c=0;
		    fprintf(fptr,"#%d;%s;%d;",i,temp->word,temp->filecount);
		    while(temp1!=NULL)
		    {
			fprintf(fptr,"%s;%d;",temp1->file_name,temp1->word_count);
			temp1=temp1->Slink;
		    }
		    fprintf(fptr,"#\n");
		    temp=temp->Mlink;
		}
	    }
	}
	return SUCCESS;
    }
    else
    {
	return FAILURE;
    }
}



