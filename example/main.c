/*
Name :K.Mowleeshwaran
Date :04-01-2024
Description :LSB image Steganography
sample input : -e <bmp file> <secrete file> or -d <output bmp file> <secrete file>
sample output : check the final .txt file.
*/
#include <stdio.h>
#include "encode.h"
#include "types.h"
#include<unistd.h>
#include"decode.h"
int main(int argc,char *argv[])
{
    if(argc>=2)
    {
	EncodeInfo eninfo;
	int res=check_operation_type(argv);
	if(res==0)
	{
	    printf("INFO: Starting to encode\n");
	    sleep(1);
	    if(read_and_validate_encode_args(argv,&eninfo,argc)!=e_failure)
	    {
		printf("INFO: read and validation is successfully completed\n");
		sleep(1);
		do_encoding(&eninfo);
	    }
	    else
	    {
		printf("INFO: read and validation is not completed\n");
		printf("failure\n");
	    }
	}
	else if(res==1)
	{
	    printf("Starting to decode\n");
	    DecodeInfo deinfo;
	    if(read_and_validate_decode_args(argv,&deinfo,argc)!=e_failure)
	    {
		do_decoding(&deinfo);
	    }
	    else
	    {
		printf("INFO: Read and validation is failed\n");
	    	printf("failure\n");
	    }

	}
	else
	{
	    printf("unsuportted\n");
	}
    }
    else
    {
	printf("INFO: Pass four arguments in CLA\n");
    }
    return 0;
}
OperationType check_operation_type(char *argv[])
{
    char str1[2]="-e";
    char str2[2]="-d";
    int c1=0;
    int c2=0;
    for (int i=0;i<2;i++)
    {
	if(argv[1][i]==str1[i])
	{
	    c1=c1+1;
	}
	if(argv[1][i]==str2[i])
	{
	    c2=c2+1;
	}

    }
    if(c1==2)
    {
	return e_encode;
    }
    else if(c2==2)
    {
	return e_decode;
    }
    else
    {
	return e_unsupported;
    }
}
