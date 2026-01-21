#include<stdio.h>
#include<string.h>
#include"view.h"
char str[6][5]={"-t","-A","-a","-y","-ct","-C"};
char str1[6][50]={"TIT2","TPE1","TALB","TYER","TCON","COMM"};
Status read_and_validatefor_edit(char *argv[],Datainfo *dinfo)
{
    read_and_validateedit(argv,dinfo);

    dinfo->file2=fopen("result.mpeg","w");
    int l=strlen(argv[3]);
    int ra=dinfo->ra;
    int len=dinfo->len;
    rewind(dinfo->file);
    char copy[ra];
    fread(copy,ra,1,dinfo->file);
    fwrite(copy,ra,1,dinfo->file2);
    fwrite(&l,4,1,dinfo->file2);

    int waste;
    fread(&waste,4,1,dinfo->file);
    int flag;
    fread(&flag,2,1,dinfo->file);
    fwrite(&flag,2,1,dinfo->file2);
    fwrite(argv[3],l,1,dinfo->file2);
    fseek(dinfo->file,len,SEEK_SET);
    char eof;
    while(eof!=EOF)
    {
	fread(&eof,1,1,dinfo->file);
	fwrite(&eof,1,1,dinfo->file2);
    }

}

/*
   Status read_and_validatefor_edit(char *argv[],Datainfo *dinfo)
   {
   if(!(strcmp(argv[2],"-t")))
   {
   read_and_validateedit(argv,dinfo);
   printf("Title/Song Name\n");
   if((strcmp(argv[4],"result.mpeg"))==0)
   {
   dinfo->file2=fopen("result1.mpeg","w");
   }
   else
   {
   dinfo->file2=fopen("result.mpeg","w");
   }
   int l=strlen(argv[3]);
   int t=dinfo->t;
   rewind(dinfo->file);
   char copy[t];
   fread(copy,t,1,dinfo->file);
   fwrite(copy,t,1,dinfo->file2);
   fwrite(&l,4,1,dinfo->file2);
   int waste;
   fread(&waste,4,1,dinfo->file);
   int flag;
   fread(&flag,2,1,dinfo->file);
   fwrite(&flag,2,1,dinfo->file2);
   fwrite(argv[3],l,1,dinfo->file2);
   fseek(dinfo->file,(dinfo->A)-4,SEEK_SET);
   char eof;
   while(eof!=EOF)
   {
   fread(&eof,1,1,dinfo->file);
   fwrite(&eof,1,1,dinfo->file2);
   }
   printf("------------------------------------------------------------------------\n");
   printf("Title/Song Name:%s\n",argv[3]);
   printf("------------------------------------------------------------------------\n");


   return e_success;
   }
   else if(!(strcmp(argv[2],"-A")))
   {
   printf("Artist Name\n");
   read_and_validateedit(argv,dinfo);
   dinfo->file2=fopen("result.mpeg","w");
   int l=strlen(argv[3]);
   int A=dinfo->A;
   rewind(dinfo->file);
   char copy[A];
   fread(copy,A,1,dinfo->file);
   fwrite(copy,A,1,dinfo->file2);
   fwrite(&l,4,1,dinfo->file2);
   int waste;
   fread(&waste,4,1,dinfo->file);
   int flag;
   fread(&flag,2,1,dinfo->file);
   fwrite(&flag,2,1,dinfo->file2);
   fwrite(argv[3],l,1,dinfo->file2);
   fseek(dinfo->file,(dinfo->a)-4,SEEK_SET);
   char eof;
   while(eof!=EOF)
   {
   fread(&eof,1,1,dinfo->file);
   fwrite(&eof,1,1,dinfo->file2);
   }
   printf("------------------------------------------------------------------------\n");
   printf("Artist Name:%s\n",argv[3]);
   printf("------------------------------------------------------------------------\n");

}
else if(!(strcmp(argv[2],"-a")))
{
    printf("Album\n");
    read_and_validateedit(argv,dinfo);
    dinfo->file2=fopen("result.mpeg","w");
    int l=strlen(argv[3]);
    int a=dinfo->a;
    rewind(dinfo->file);
    char copy[a];
    fread(copy,a,1,dinfo->file);
    fwrite(copy,a,1,dinfo->file2);
    fwrite(&l,4,1,dinfo->file2);
    int waste;
    fread(&waste,4,1,dinfo->file);
    int flag;
    fread(&flag,2,1,dinfo->file);
    fwrite(&flag,2,1,dinfo->file2);
    fwrite(argv[3],l,1,dinfo->file2);
    fseek(dinfo->file,(dinfo->y)-4,SEEK_SET);
    char eof;
    while(eof!=EOF)
    {
	fread(&eof,1,1,dinfo->file);
	fwrite(&eof,1,1,dinfo->file2);
    }
    printf("------------------------------------------------------------------------\n");
    printf("Album Name:%s\n",argv[3]);
    printf("------------------------------------------------------------------------\n");

    return e_success;

}
else if(!(strcmp(argv[2],"-y")))
{
    printf("Year\n");
    read_and_validateedit(argv,dinfo);
    dinfo->file2=fopen("result.mpeg","w");
    int l=strlen(argv[3]);
    int y=dinfo->y;
    rewind(dinfo->file);
    char copy[y];
    fread(copy,y,1,dinfo->file);
    fwrite(copy,y,1,dinfo->file2);
    fwrite(&l,4,1,dinfo->file2);
    int waste;
    fread(&waste,4,1,dinfo->file);
    int flag;
    fread(&flag,2,1,dinfo->file);
    fwrite(&flag,2,1,dinfo->file2);
    fwrite(argv[3],l,1,dinfo->file2);
    fseek(dinfo->file,dinfo->ct-4,SEEK_SET);
    char eof;
    while(eof!=EOF)
    {
	fread(&eof,1,1,dinfo->file);
	fwrite(&eof,1,1,dinfo->file2);
    }
    printf("------------------------------------------------------------------------\n");
    printf("Year:%s\n",argv[3]);
    printf("------------------------------------------------------------------------\n");

    return e_success;

}
else if(!(strcmp(argv[2],"-ct")))
{
    printf("Content type\n");
    read_and_validateedit(argv,dinfo);
    dinfo->file2=fopen("result.mpeg","w");
    int l=strlen(argv[3]);
    int ct=dinfo->ct;
    rewind(dinfo->file);
    char copy[ct];
    fread(copy,ct,1,dinfo->file);
    fwrite(copy,ct,1,dinfo->file2);
    fwrite(&l,4,1,dinfo->file2);
    int waste;
    fread(&waste,4,1,dinfo->file);
    int flag;
    fread(&flag,2,1,dinfo->file);
    fwrite(&flag,2,1,dinfo->file2);
    fwrite(argv[3],l,1,dinfo->file2);
    fseek(dinfo->file,(dinfo->C)-4,SEEK_SET);
    char eof;
    while(eof!=EOF)
    {
	fread(&eof,1,1,dinfo->file);
	fwrite(&eof,1,1,dinfo->file2);
    }
    printf("------------------------------------------------------------------------\n");
    printf("Content Type:%s\n",argv[3]);
    printf("------------------------------------------------------------------------\n");

}
else if(!(strcmp(argv[2],"-C")))
{
    printf("Composer\n");
    fun(argv,dinfo);
}
else
{
    printf("wrong option\n");
}
return e_success;


}
void fun(char *argv[],Datainfo *dinfo)
{
    read_and_validateedit(argv,dinfo);
    dinfo->file2=fopen("result.mpeg","w");
    int l=strlen(argv[3]);
    int C=dinfo->C;
    rewind(dinfo->file);
    char copy[C];
    fread(copy,C,1,dinfo->file);
    fwrite(copy,C,1,dinfo->file2);
    fwrite(&l,4,1,dinfo->file2);
    int waste;
    fread(&waste,4,1,dinfo->file);
    int flag;
    fread(&flag,2,1,dinfo->file);
    fwrite(&flag,2,1,dinfo->file2);
    fwrite(argv[3],l,1,dinfo->file2);
    fseek(dinfo->file,(dinfo->e)+1,SEEK_SET);
    char eof;
    while(eof!=EOF)
    {
	fread(&eof,1,1,dinfo->file);
	fwrite(&eof,1,1,dinfo->file2);
    }
    printf("------------------------------------------------------------------------\n");
    printf("Composer:%s\n",argv[3]);
    printf("------------------------------------------------------------------------\n");

}*/
Status read_and_validateedit(char *argv[],Datainfo *dinfo)
{
    int a;
    for (int i=0;i<6;i++)
    {
	if(!(strcmp(argv[2],str[i])))
	{
	    a=i;
	}
    }
    printf("check=%d",a);

    if(strcmp(strstr(argv[4],"."),".mpeg")==0)
    {
	printf("read\n");
	dinfo->file_name=argv[4];
	//	printf("%s\n",dinfo->file_name);
	if(open_file(dinfo)==e_success)
	{
	    printf("file open done\n");
	    view_fileedit(a,dinfo);
	}
    }
    return e_success;
}
Status open_fileedit(Datainfo *dinfo)
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
Status view_fileedit(int a,Datainfo *dinfo)
{
    char buffer1[6];
    fread(buffer1,3,1,dinfo->file);
    printf("check=%s\n", buffer1);

    if(strcmp(buffer1,"ID3")==0)
    {
	//	printf("yes id3\n");
	int buffer2;
	fread(&buffer2,2,1,dinfo->file);
	//	printf("version=%d\n",buffer2);
	int buffer3;
	fread(&buffer3,1,1,dinfo->file);
	//	printf("flag=%d\n",buffer3);
	int buffer4;
	fread(&buffer4,4,1,dinfo->file);
	//int buffer5;
	int r=6;
	while(r--)
	{
	    char tit2[6];
	    int i;
	    for (i=0;i<4;i++)
	    {
		int buffer5;
		fread(&buffer5,1,1,dinfo->file);
		tit2[i]=buffer5;
		//	printf("%c ",buffer5);
	    }
	    tit2[4]='\0';
	    int ra=ftell(dinfo->file);
	    /*
	       if(!(strcmp(str1[a],tit2)))
	       {	
	       int t=ftell(dinfo->file);
	       dinfo->ra=t;
	       }*/
	    /*
	       printf("ra=%d",dinfo->ra);*/



	    printf("bh=%s\n ",tit2);
	    //fread(&buffer5,4,1,dinfo->file);
	    //	printf("\n");
	    //int t=ftell(dinfo->file);
	    //dinfo->t=t;
	    int s1=0;
	    for (int i=0;i<4;i++)
	    {
		char s;
		fread(&s,1,1,dinfo->file);
		s1=s1|s;
	    }
	    //	printf("TIT2 size=%d\n",s1);
	    int flag;
	    fread(&flag,2,1,dinfo->file);
	    char title[s1];
	    fread(title,s1,1,dinfo->file);
	    int len=ftell(dinfo->file);
	    if(!(strcmp(str1[a],tit2)))
	    {	
		dinfo->ra=ra;
		dinfo->len=len;
	    }
	}
	//printf("ra=%d",dinfo->ra);
	//	printf("Tile / Song name: ");

	//int buffer6;
	/*
	   char tpe1[6];
	   int i1;
	   for (i1=0;i1<4;i1++)
	   {
	   int buffer6;
	   fread(&buffer6,1,1,dinfo->file);
	   tpe1[i1]=buffer6;
	//	printf("%c ",buffer5);
	}
	tpe1[i1]='\0';
	int ra1=ftell(dinfo->file);
	//fread(&buffer6,4,1,dinfo->file);
	//      fwrite(&buffer6,4,1,stdout);
	//	printf("\n");
	int A=ftell(dinfo->file);
	dinfo->A=A;
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
	int len1=ftell(dinfo->file);
	if(!(strcmp(str1[a],tpe1)))
	{	
	dinfo->ra=ra1;
	dinfo->len=len1;
	}
	printf("ra1=%d",dinfo->ra);
	//	printf("Tile / Song name: ");

	//printf("Artist name: ");	
	//int buffer7;
	//fread(&buffer7,4,1,dinfo->file);

	char talp[6];
	int i2;
	for (i2=0;i2<4;i2++)
	{
	int buffer7;
	fread(&buffer7,1,1,dinfo->file);
	talp[i2]=buffer7;
	//	printf("%c ",buffer5);
	}

	talp[i2]='\0';
	printf("talp=%s\n",talp);
	int ra2=ftell(dinfo->file);
	//        fwrite(&buffer7,4,1,stdout);
	int a=ftell(dinfo->file);
	dinfo->a=a;
	//	printf("\n");
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
	char talp1[s3];
	fread(talp1,s3,1,dinfo->file);
	int len2=ftell(dinfo->file);
	int y=1;

	for (int i=0;str1[a][i]!='\0';i++)
	{
	    printf("%c %c\n",str1[a][i],talp[i]);

	    if(str1[a][i]!=talp[i])
	    {

		y=0;
		break;
	    }
	}
	if(y)
	{

	    dinfo->ra=ra2;
	    dinfo->len=len2;
	}

	printf("ra1=%d",dinfo->ra);
	//	printf("Tile / Song name: ");

	//printf("ALbum: ");


	int buffer8;
	fread(&buffer8,4,1,dinfo->file);
	int y=ftell(dinfo->file);
	dinfo->y=y;
	//        fwrite(&buffer8,4,1,stdout);
	//	printf("\n");
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
	//printf("Year: ");
	int buffer9;
	fread(&buffer9,4,1,dinfo->file);
	//        fwrite(&buffer9,4,1,stdout);
	int ct=ftell(dinfo->file);
	dinfo->ct=ct;
	//	printf("\n");
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
	//printf("Content type: ");

	int buffer10;
	fread(&buffer10,4,1,dinfo->file);
	//       fwrite(&buffer10,4,1,stdout);

	int C=ftell(dinfo->file);
	dinfo->C=C;
	//	printf("\n");
	int s6=0;
	for (int i=0;i<4;i++)
	{
	    char s;
	    fread(&s,1,1,dinfo->file);
	    s6=s6|s;
	}
	//	printf("COMM size = %d\n",s6);
	int flag5;
	fread(&flag5,2,1,dinfo->file);
	char comm[s6];
	fread(comm,s6,1,dinfo->file);
	//printf("Composer: ");

	int e=ftell(dinfo->file);
	dinfo->e=e;*/
    }
    else
    {
	printf("not id3\n");
    }
    return e_success;
}





