#include<stdio.h>
#include<string.h>
#include"common.h"
#include<unistd.h>
#include"types.h"
#include"decode.h"
Status read_and_validate_decode_args(char *argv[],DecodeInfo *deinfo,int argc)
{
    if(argc>=3)
    {
	if(argc==4)
	{
	    strcpy(deinfo->outname,argv[3]);
	}
	else
	{
	    strcpy(deinfo->outname,"final");
	    //deinfo->outname="final";
	}
	deinfo->fptr_src_decode=fopen(argv[2],"r");
	if(deinfo->fptr_src_decode!=NULL)
	{
	    return e_success;
	}
	else
	{
	    return e_failure;
	}
    }
    else
    {
	printf("Info : Pass three arguments\n");
	return e_failure;
    }
}
Status do_decoding(DecodeInfo *deinfo)
{
    if(decode_magic_string(MAGIC_STRING,deinfo->fptr_src_decode)==e_success)
    {
	sleep(1);
	printf("INFO: Magic string is decoded\n");
	if(decode_secret_file_extn_size(deinfo)==e_success)
	{
	    sleep(1);
	    if(decode_secret_file_extn(deinfo)==e_success)
	    {
		sleep(1);
		if(dest_open(deinfo)==e_success)
		{
		    sleep(1);
		    if(decode_secret_file_size(deinfo)==e_success)
		    {
			sleep(1);
			if(decode_secret_file_data(deinfo)==e_success)
			{
			    sleep(1);
			    printf("Decode Completed\n");
			}
			else
			{
			    printf("INFO: Decode secret file is failed\n");
			}
		    }
		    else
		    {
			printf("INFO: Decode secret file size is failed\n");
		    }
		}
		else
		{
		    printf("INFO: Dest is failed\n");
		}
	    }
	    else
	    {
		printf("INFO: Decode secret extension is failed\n");
	    }
	}
	else
	{
	    printf("INFO: Decode secret file extension size is failed\n");
	}
    }
    else
    {
	printf("INFO: Decode magic string is failed\n");
    }
}
Status decode_secret_file_data(DecodeInfo *deinfo)
{

    int size=deinfo->txt_size;
    // printf("n=%d\n",size);
    char str[size];
    char buffer[8];
    int i;
    for (i=0;i<size;i++)
    {
	fread(buffer,8,1,deinfo->fptr_src_decode);
	char sum=0;
	for (int j=0;j<8;j++)
	{
	    sum=((buffer[j]&1)<<j)|sum;
	}
	str[i]=sum;
        printf("data=%d\n",sum);
    }
    printf("data=%s\n",str);
    fwrite(str,size,1,deinfo->file);
    printf("INFO: Secret file data decoded\n");
    return e_success;
}

Status decode_secret_file_size(DecodeInfo *deinfo)
{
    char buffer[32];
    fread(buffer,32,1,deinfo->fptr_src_decode);
    int sum=0;
    for (int i=0;i<32;i++)
    {
	if(buffer[i]&1)
	{
	    sum=sum|(1<<i);
	}
    }
    deinfo->txt_size=sum;
    printf("txt=%d\n",sum);
    printf("INFO: Secret file size decoded\n");
    return e_success;
     printf("txt=%d\n",sum);
}

Status dest_open(DecodeInfo *deinfo)
{

    //char str[30]="final";
    strcat(deinfo->outname,deinfo->dest_name);
    //deinfo->d=;
    //printf("%s",str);
    deinfo->file=fopen(deinfo->outname,"w");
    return e_success;
}

Status decode_secret_file_extn(DecodeInfo *deinfo)
{
    int size=deinfo->extn_size;
    //printf("n=%d\n",size);
    char str[size];
    char buffer[8];
    int i;
    for (i=0;i<size;i++)
    {
	fread(buffer,8,1,deinfo->fptr_src_decode);
	int sum=0;
	for (int j=0;j<8;j++)
	{
	    sum=((buffer[j]&1)<<j)|sum;
	}
	//printf("\nd=%d",sum);
	str[i]=sum;
    }
    str[i]='\0';
    printf("str=%s\n",str);
    strcpy(deinfo->dest_name,str);
    printf("INFO: Secret file extension decoded\n");
    return e_success;
}
Status decode_secret_file_extn_size(DecodeInfo *deinfo)
{
    char buffer[32];
    fread(buffer,32,1,deinfo->fptr_src_decode);
    char sum=0;
    for (int i=0;i<32;i++)
    {
	if(buffer[i]&1)
	{
	    sum=sum|(1<<i);
	}
    }
    deinfo->extn_size=sum;
    printf("extnsize=%d\n",sum);
    printf("INFO: Secret file extension size decoded\n");
    return e_success;
    // printf("%d\n",sum);
}

Status decode_magic_string(const char *magic_string,FILE *fptr_src_image)
{   
    rewind(fptr_src_image);
    fseek(fptr_src_image,54,SEEK_SET);
    int l=strlen(magic_string);
    // printf("%d\n",l);
    char buffer[8];
    char magic[l];
    int c=0;
    int i;
    for ( i=0;i<l;i++)
    {
	fread(buffer,8,1,fptr_src_image);
	char sum=0;
	for (int j=0;j<8;j++)
	{
	    if(buffer[j]&1)
	    {
		sum=sum|(1<<j);
	    }
	}
	magic[i]=sum;
	if(magic_string[i]==sum);
	{
	    c=c+1;
	}
    }
    magic[i]='\0';
    //printf("ref1=%s\n",magic);
    //printf("count=%d",c);
    if(c==l)
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
}






