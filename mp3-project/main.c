/*
Name :K.Mowleeshwaran
Date :
Description :
sample input :
sample output :
 */

#include <stdio.h>
#include <string.h>
#include "view.h"
//#include "common.h"
int main(int argc,char *argv[])
{
    Datainfo dinfo;
    if(argc>=3)
    {
	int a=check_cla(argc,argv);
	if(a==0)
	{
	    printf("User selected view\n");
	    read_and_validate(argv,&dinfo);
	}
	else if(a==1)
	{
	    printf("User selected edit\n");
	    read_and_validatefor_edit(argv,&dinfo);
	}
    }
    else
    {
	printf("Pass 3 or 4 arguments\n");
    }
    return 0;
}
Operationtype check_cla(int argc,char *argv[])
{
    if(strcmp(argv[1],"-v")==0)
    {
	return e_v;
    }
    else if(strcmp(argv[1],"-e")==0)
    {
	return e_e;
    }
    else if((strcmp(argv[1],"-Help")) ||(strcmp(argv[1],"-help"))) 
    {
	return e_h;
    }
    else
    {
	return e_unsupport;
    }
}
    






