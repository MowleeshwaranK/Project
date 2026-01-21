#include <stdio.h>
#include "encode.h"
#include "types.h"
#include<string.h>
#include<unistd.h>
#include"common.h"
#include"decode.h"

/* Function Definitions */
//Status open_files(EncodeInfo *eninfo);
int secret_size_file;
Status read_and_validate_encode_args(char *argv[],EncodeInfo *eninfo,int argc)
{   
    if(argc>3)
    {
	char *check1=strstr(argv[2],".bmp");
	if(check1==NULL)
	{
	    printf("INFO: Error in 2nd argument\n");
	    return e_failure;
	}
	if(strcmp(strstr(argv[2],"."),".bmp")==0)
	{
	    eninfo->src_image_fname=argv[2];   
	    char *check2=strstr(argv[3],".txt");
	    if(check2==NULL)
	    {
	    	printf("INFO: Error in 3rd argument\n");
		return e_failure;
	    }
	    if(strcmp(strstr(argv[3],"."),".txt")==0)
	    {
		eninfo->secret_fname=argv[3]; 
		strcpy(eninfo->extn_secret_file,".txt");
	//	printf("hi\n");
		if(argc<=4)
		{
		    argv[4]="output.bmp";
		}
		//	return e_success;
		char *check3=strstr(argv[4],".bmp");
		if(check3==NULL)
		{
	    	    printf("INFO: Error in 4th argument\n");
		    return e_failure;
		}
		if(strcmp(strstr(argv[4],"."),".bmp")==0)
		{
		    eninfo->stego_image_fname=argv[4];
		    return e_success;
		}
		else
		{
	    	    printf("INFO: Error in 4th argument\n");
		}
	    }
	    else
	    {
	    	printf("INFO: Error in 3rd argument\n");
	    }
	}
	else
	{
	    printf("INFO: Error in 2nd argument\n");
	}

	return e_failure;
    }
    else
    {
	printf("INFO: Pass 4 argument\n");
	return e_failure;
    }
}
Status do_encoding(EncodeInfo *eninfo)
{
    if(open_files(eninfo)==e_success)
    {
	sleep(1);
	printf("INFO: File are operand successfully\n");
    }
    else
    {
	sleep(1);
	printf("INFO: Files cannot be opened\n");
	return e_failure;
    }
    if(check_capacity(eninfo)==e_success)
    {
//	printf("check\n");
	if(copy_bmp_header(eninfo->fptr_src_image,eninfo->fptr_stego_image)==e_success)
	{
	    if(encode_magic_string(MAGIC_STRING,eninfo->fptr_src_image,eninfo->fptr_stego_image)==e_success)
	    {
		int l=strlen(eninfo->extn_secret_file);
	//	printf("%d\n",l);
		if(encode_secret_file_extn_size(l,eninfo->fptr_src_image,eninfo->fptr_stego_image)==e_success)
		{
		    if(encode_secret_file_extn(eninfo->extn_secret_file,eninfo->fptr_src_image,eninfo->fptr_stego_image)==e_success)
		    {
			if(encode_secret_file_size(eninfo->size_secret_file,eninfo->fptr_src_image,eninfo->fptr_stego_image)==e_success)
			{
			    if(encode_secret_file_data(eninfo)==e_success)
			    {
				if(copy_remaining_img_data(eninfo->fptr_src_image, eninfo->fptr_stego_image)==e_success)
				{
				    printf("Encode Completed\n");
				}
			    }
			}
		    }
		}
	    }
	}
    }
    else
    {
	printf("INFO: Capacity is not equal\n");
    }
}
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;
    while(fread(&ch,1,1,fptr_src)!=0)
    {
	fwrite(&ch,1,1,fptr_dest);
    }
    sleep(1);
    printf("INFO: Remaining data is copied\n");
    return e_success;
}
Status encode_secret_file_data(EncodeInfo *eninfo)
{
    char str[eninfo->size_secret_file];
    fread(str,eninfo->size_secret_file,1,eninfo->fptr_secret);
    char buffer[8];
    for (int i=0;i<eninfo->size_secret_file;i++)
    {
	fread(buffer,8,1,eninfo->fptr_src_image);
	for (int j=0;j<8;j++)
	{
	    if(str[i]&(1<<j))
	    {
		buffer[j]=(buffer[j]&(~1))|1;
	    }
	    else
	    {
		buffer[j]=(buffer[j]&(~1))|0;
	    }
	}
	fwrite(buffer,8,1,eninfo->fptr_stego_image);
    }
	sleep(1);
	printf("INFO: Secret file data is encoded\n");

    return e_success;
   // printf("\n");
}
Status encode_secret_file_size(long file_size,FILE *fptr_src_image,FILE *fptr_stego_image)
{
    char buffer[32];
    fread(buffer,32,1,fptr_src_image);
    for (int i=0;i<32;i++)
    {
	if(file_size&(1<<i))
	{
	    buffer[i]=(buffer[i]&(~(1)))|1;
	}
	else
	{
	    buffer[i]=(buffer[i]&(~(1)))|0;
	}
    }
    fwrite(buffer,32,1,fptr_stego_image);
	sleep(1);
    printf("INFO: Secret file data size is encoded\n");
    return e_success;
   // printf("file size=%ld",file_size);
}
Status encode_secret_file_extn(const char *file_extn,FILE *fptr_src_image,FILE *fptr_stego_image)
{
    int l=strlen(file_extn);
   // printf("l=%d",l);
    char buffer[8];
    for (int i=0;i<l;i++)
    {
	fread(buffer,8,1,fptr_src_image);
//	printf("%c\n",file_extn[i]);
	for (int j=0;j<8;j++)
	{
	    if(file_extn[i]&(1<<j))
	    {
	//	printf("1 ");
		buffer[j]=(buffer[j]&(~(1)))|1;
	    }
	    else
	    {
	//	printf("0 ");
		buffer[j]=(buffer[j]&(~(1)))|0;
	    }
	}
	fwrite(buffer,8,1,fptr_stego_image);
//	printf("\n");
    }
	sleep(1);
    printf("INFO: Secret file data extention is encoded\n");
    return e_success;
   // printf("secret extn done\n");

}

Status encode_secret_file_extn_size(int extn_size,FILE *fptr_src_image,FILE *fptr_stego_image)
{
    int f=sizeof(extn_size);
    char buffer[32];
    fread(buffer,32,1,fptr_src_image);
    for (int i=0;i<32;i++)
    {
	if(extn_size&(1<<i))
	{
	    buffer[i]=(buffer[i]&(~(1)))|1;
	}
	else
	{
	    buffer[i]=(buffer[i]&(~(1)))|0;
	}
    }
    fwrite(buffer,32,1,fptr_stego_image);
	sleep(1);
    printf("INFO: Secret file extention size is encoded\n");
    return e_success;
   // printf("extn size done\n");
}



Status encode_magic_string(const char *magic,FILE *fptr_src_image,FILE *fptr_stego_image)
{

    int l=strlen(magic);
    char buffer[8];
    for (int i=0;i<l;i++)
    {
	fread(buffer,8,1,fptr_src_image);
	for (int j=0;j<8;j++)
	{
	    buffer[j]=buffer[j]&~(1);
	    if(magic[i]&(1<<j))
	    {
		buffer[j]=buffer[j]|1;
	    }
	    else
	    {
		buffer[j]=buffer[j]|0;
	    }
	}
	fwrite(buffer,8,1,fptr_stego_image);
    }
	sleep(1);
    printf("INFO: Magic string is encoded\n");
    return e_success;
}
Status copy_bmp_header(FILE *fptr_src_image,FILE *fptr_stego_image)
{
    char buffer[54];
    rewind(fptr_src_image);
    fread(buffer,54,1,fptr_src_image);
    fwrite(buffer,54,1,fptr_stego_image);
    printf("INFO: Header is copied\n");
    return e_success;
}
Status check_capacity(EncodeInfo *eninfo)
{
    eninfo->image_capacity=get_image_size_for_bmp(eninfo->fptr_src_image);//.bmp file size
    uint size=(get_file_size(eninfo->fptr_secret));
    eninfo->size_secret_file=size;
    secret_size_file=size;
   // printf("%d\n",size);
    if((16+54+32+32+32+(size*8))<(eninfo->image_capacity))
    {
	sleep(1);
	printf("INFO: Check capacity is done\n");
	return e_success;
    }
    else
    {
	sleep(1);
	printf("INFO: Capacity is not equal\n");
	return e_failure;
    }
}

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_file_size(FILE *fptr_secret)
{
    fseek(fptr_secret,0,SEEK_SET);
    fseek(fptr_secret,0,SEEK_END);
    uint size=ftell(fptr_secret);
    rewind(fptr_secret);
    return size;
}

uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
   // printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    //printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

	return e_failure;
    }

    // No failure return e_success
    return e_success;
}
