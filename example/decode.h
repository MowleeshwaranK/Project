#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */
/*
#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4*/

typedef struct _DecodeInfo
{
    /* Source Image info */
    char *src_decode;     //name of image
    FILE *fptr_src_decode; 
    char outname[30];
    int extn_size;    //address of file
    int txt_size;
    char dest_name[30];
    char *d;
    FILE *file;
} DecodeInfo;


/* Encoding function prototype */

/* Check operation type */

/* Read and validate Encode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *deinfo,int argc);

/* Perform the encoding */
Status do_decoding(DecodeInfo *deInfo);
Status decode_magic_string(const char *magic_string,FILE *fptr_src_image);
Status decode_secret_file_extn_size(DecodeInfo *deinfo);
Status decode_secret_file_extn(DecodeInfo *deinfo);
Status dest_open(DecodeInfo *deinfo);
Status decode_secret_file_size(DecodeInfo *deinfo);
Status decode_secret_file_data(DecodeInfo *deinfo);
#endif
