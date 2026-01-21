#include<stdio.h>
#include<string.h>
#include"view.h"
//#include"common.h"

Status read_and_validate(char *argv[],Datainfo *dinfo)
{
    if(strcmp(strstr(argv[2],"."),".mpeg")==0)
    {
	printf("read\n");
	dinfo->file_name=argv[2];
	//printf("%s\n",dinfo->file_name);
	if(open_file(dinfo)==e_success)
	{
	    printf("file open done\n");
	    view_file(dinfo);
	}
    }
    return e_success;
}
Status open_file(Datainfo *dinfo)
{
    dinfo->file=fopen(dinfo->file_name,"r");
    if(dinfo->file==NULL)
    {
	return e_failure;
    }
    else

    {
	return e_success;
    }
}
Status view_file(Datainfo *dinfo)
{
    char buffer1[5];
    fread(buffer1,3,1,dinfo->file);
    printf("%s\n", buffer1);
    //fwrite(buffer1,10,1,stdout);
    if(!(strcmp(buffer1,"ID3")))
    {
	printf("yes id3\n");
	int buffer2;
	fread(&buffer2,2,1,dinfo->file);
	printf("version=%d\n",buffer2);
	int buffer3;
	fread(&buffer3,1,1,dinfo->file);
//	printf("flag=%d\n",buffer3);
	int buffer4;
	fread(&buffer4,4,1,dinfo->file);
//	printf("size=%d\n",buffer4);
        //fwrite(&buffer4,4,1,stdout);
	char tit2[4];
	for (int i=0;i<4;i++)
	{
	int buffer5;
	fread(&buffer5,1,1,dinfo->file);
	tit2[i]=buffer5;
//	printf("%c ",buffer5);
	}
	tit2[4]='\0';
	printf("bh=%s\n ",tit2);
        //fwrite(&buffer5,4,1,stdout);
	//printf("%d",buffer5);
	printf("\n");
	/*
	int size;
	fread(&size,1,1,dinfo->file);
	printf("title size=%x\n",size);*/
	int s=ftell(dinfo->file);
	dinfo->t=s;
	int s1=0;
	//fread(&s,4,1,dinfo->file);
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    printf("TIT2 size=%d\n",s);
	    s1=s1|s;
           // fwrite(&s,1,1,stdout);
	}
	//intf("TIT2 size=%d\n",s1);
	int flag;
	fread(&flag,2,1,dinfo->file);
	char title[s1];
	fread(title,s1,1,dinfo->file);
	printf("--------------------------------------------------------------------------\n");
	printf("Tile / Song name: ");
        fwrite(title,s1,1,stdout);
	printf("\n");
	int buffer6;
	fread(&buffer6,4,1,dinfo->file);
//      fwrite(&buffer6,4,1,stdout);
	printf("\n");
	int s2=0;
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    s2=s2|s;
           // fwrite(&s,1,1,stdout);
	}
//	printf("TPE1 size=%d\n",s2);
	int flag1;
	fread(&flag1,2,1,dinfo->file);
	char ti[s2];
	fread(ti,s2,1,dinfo->file);
	printf("Artist name: ");
        fwrite(ti,s2,1,stdout);
	printf("\n");
	int buffer7;
	fread(&buffer7,4,1,dinfo->file);
//        fwrite(&buffer7,4,1,stdout);
	printf("\n");
	int s3=0;
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    s3=s3|s;
           // fwrite(&s,1,1,stdout);
	}
//	printf("TALB size = %d\n",s3);
	int flag2;
	fread(&flag2,2,1,dinfo->file);
	char talp[s3];
	fread(talp,s3,1,dinfo->file);
	printf("ALbum: ");
        fwrite(talp,s3,1,stdout);
	printf("\n");
	int buffer8;
	fread(&buffer8,4,1,dinfo->file);
//        fwrite(&buffer8,4,1,stdout);
	printf("\n");
	int s4=0;
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    s4=s4|s;
           // fwrite(&s,1,1,stdout);
	}
//	printf("TYER size = %d\n",s4);
	int flag3;
	fread(&flag3,2,1,dinfo->file);
	char tyer[s4];
	fread(tyer,s4,1,dinfo->file);
	printf("Year: ");
        fwrite(tyer,s4,1,stdout);
	printf("\n");
	int buffer9;
	fread(&buffer9,4,1,dinfo->file);
//        fwrite(&buffer9,4,1,stdout);
	printf("\n");
	int s5=0;
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    s5=s5|s;
           // fwrite(&s,1,1,stdout);
	}
//	printf("TCON size = %d\n",s5);
	int flag4;
	fread(&flag4,2,1,dinfo->file);
	char tcon[s5];
	fread(tcon,s5,1,dinfo->file);
	printf("Content type: ");
        fwrite(tcon,s5,1,stdout);
	printf("\n");
	int buffer10;
	fread(&buffer10,4,1,dinfo->file);
 //       fwrite(&buffer10,4,1,stdout);
	printf("\n");
	int s6=0;
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    s6=s6|s;
           // fwrite(&s,1,1,stdout);
	}
//	printf("COMM size = %d\n",s6);
	int flag5;
	fread(&flag5,2,1,dinfo->file);
	char comm[s6];
	fread(comm,s6,1,dinfo->file);
	printf("Composer: ");
        fwrite(comm,s6,1,stdout);
	printf("\n");
	printf("--------------------------------------------------------------------------\n");
	//printf("%d\n",dinfo->t);
    }
    else
    {
	printf("not id3\n");
    }
    return e_success;
}




