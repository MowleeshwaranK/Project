#include "common.h"
#include<stdio.h>
typedef struct datainfo_
{
    char *file_name;
    FILE *file;
    FILE *file2;
    int start;
    int t;
    int A;
    int a;
    int y;
    int ct;
    int C;
    int e;
    int ra;
    int len;
}Datainfo;

Operationtype check_cla(int argc,char *argv[]);
Status read_and_validate(char *argv[],Datainfo *dinfo);
Status open_file(Datainfo *dinfo);
Status view_file(Datainfo *dinfo);
Status read_and_validatefor_edit(char *argv[],Datainfo *dinfo);
//edit
Status read_and_validateedit(char *argv[],Datainfo *dinfo);
Status open_fileedit(Datainfo *dinfo);
Status view_fileedit(int a,Datainfo *dinfo);
void fun(char *argv[],Datainfo *dinfo);
