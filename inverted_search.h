#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef char* data_t;

typedef struct node
{
	char data[30];
	struct node *link;
}Flist;

typedef struct sub_node
{
    int count;
    char file_name[30];
    struct sub_node *slink;
}sub_t;

typedef struct main_node
{
    int file_count;
    char word[30];
    sub_t *sub_link;
    struct main_node *main_link;
}main_t;

/* Gloabal file pointer decalration*/
extern FILE *fptr;

/*Golabal variables Decalration*/
extern Flist *head;

/*Golbal Hash array declartion*/
extern main_t *arr[27];             

/*Golbal decalration*/
extern char fword[100];

/*Global declartion*/
extern int flag;

/*Function ProtoTypes*/

/*Function prototype for read and vaildate arguments function */
int file_vaildation(int argc,char *agrv[]);

/*Function Prototype to insert at last*/
int insert_at_last(Flist **head, data_t data);

/*Function Prototype to print linked list*/
void print_list(Flist *head);

/*Function Prototype to delete the linked list element*/
int sl_delete_element(Flist **head, data_t data);

/*Function Prototype to check the duplicate function*/
int check_no_duplicate( Flist  * head , char *data);

/*Function Prototype to open files and check for empty Function*/
int open_files(Flist **head);
int open_files_check_empty(char file_name_[]);

/*Function Prototyppe to store the null*/
void store(main_t **arr,int size);

/*Function Prototype to create the database*/
int create_database(Flist **head);

/*Function Prototype to dispaly the hash table*/
int display_HT(main_t **arr, int size);

/*Function Prototype to insert the data to hash */
int insert_hash(int index,char *word,char *fname);

/*Funtion Prototype to search Function*/
int search_word(main_t **arr);

/*Function Prototype to save data function*/
int save_data(main_t **arr);

/*Function to free the array memory*/
int delete_memory(main_t **arr);

int display(main_t **arr, int size);

/*Function Prototype to update the file*/
int update( );

#endif
