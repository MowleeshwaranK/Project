/*
Name :K.Mowleeshwaran
Date :28-02-2024
 */

#include<stdio.h>
#include"invert.h"
int main(int argc,char *argv[])
{
    hash arr[28];
    for (int i=0;i<28;i++)
    {
	arr[i].index=i;
	arr[i].h_link=NULL;
    }
    Slist *head;
    head=NULL;
    if(argc==1)
    {
	printf("Please pass the file name\n");
    }
    else
    {
	if(read_and_validate(argc,argv)==FAILURE)
	{
	    printf("Please pass the .txt extension file\n");
	}
        else
	{
	    if(check_file_exist(argc,argv)==SUCCESS)
	    {
		//printf("All files are existed\n");
		if(check_file_empty(argc,argv)==SUCCESS)
		{
		    if(Duplicate(argc,argv,&head)==SUCCESS)
		    {
			    printf("1.Creat Database\n2.Display\n3.Searching the word\n4.Save\n5.Update \n6.Exit\nEnter the choices:");
			while(1)
			{
			    int ch;
			    scanf("%d",&ch);
			    //printf("%d\n",ch);
			    switch(ch)
			    {
				case(1):
				    if(creating_database(head,arr)==SUCCESS)
				    {
					printf("Database created successfully\n");
				    }
				    break;
				case(2):
				    print(arr);
				    break;
				case(3):
				    printf("Enter the word you want to search :");
				    char str[30];
				    scanf("%s",str);
				    if(searching(arr,str)==FAILURE)
				    {
					printf("Data is not found !.Please enter the correct word\n");
				    }
				    break;
				case(4):
				    printf("Enter the File name,which you want to save the data:");
				    char file[30];
				    scanf("%s",file);
				    if(save_database(file,arr)==SUCCESS)
				    {
					printf("The data is successfully stored in %s file\n",file);
				    }
				    else
				    {
					printf("Please enter .txt extension file\n");
				    }
				    break;
				case(5):
				    printf("Enter the the file name that you want to update:");
				    char file1[30];
				    scanf("%s",file1);
				    if(update_data(arr,file1,&head)==SUCCESS)
				    {
					printf("Update successfully completed\n");
				    }
				    break;
				case(6):
				    return SUCCESS;
				default:
				    printf("Enter proper choice\n");
			    }
			}
			//	}
		    }
		}
		else
		{
		    printf("File is empty\n");
		}
	    }
	}
    }
    return 0;
}

