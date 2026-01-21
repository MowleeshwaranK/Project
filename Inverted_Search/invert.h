#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define SUCCESS 0
#define FAILURE 1
#define LIST_EMPTY -1
typedef struct list
{
    char file[50];
    struct list *link;
} Slist;
typedef struct main_node
{
    int filecount;
    char word[50];
    struct sub_node *Slink;
    struct main_node *Mlink;
}Mnodelist;
typedef struct sub_node
{
    int word_count;
    char file_name[50];
    struct sub_node *Slink;
}Snodelist;
typedef struct hashing
{
    int index;
    Mnodelist *h_link;
}hash;
int read_and_validate(int argc,char **argv);
int check_file_exist(int argc,char **argv);
int check_file_empty(int argc,char **argv);
int Duplicate(int argc,char **argv,Slist **head);
int creating_database(Slist *head,hash arr[]);
int print(hash arr[]);
int searching(hash arr[],char str[]);
int save_database(char file[],hash arr[]);
int update_data(hash arr[],char file1[],Slist **head);
int working_of_update(hash arr[],char file1[],Slist **head);
//int function_for_remove_dupilcate(char file1[],Slist **head,hash arr[]);
int function_for_remove_dupilcate(char str[],Slist **head);
int fun(char str[],Slist **head);
