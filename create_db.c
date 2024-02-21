/*
Name: Sivasubramanian
Date: 10/12/23
Description: Create Database Function
*/

#include "inverted_search.h"

/*Function to store the NULL in hash table*/
void store(main_t **arr,int size)
{
    for(int i = 0;i <size; i++) //Loop to initlizaes with null
    {
	arr[i] = NULL;
    }
}

/*Function to insert the data to the hash*/
int insert_hash(int index,char *word,char *fname)
{
    if(arr[index] == NULL)  //Checking the array of index is eqaul to NULL or not
    {
	main_t *new = malloc(sizeof(main_t));  //Creating the new main node
	if(new == NULL)
	{
	    return FAILURE;
	}

	new->file_count = 0;  //Initilaztion the file_count with zero
	strcpy(new->word,word);  //Copying the word to the new of word

	//printf("WORD = %s\n",new->word);
	new->main_link = NULL;  
	(new->file_count)++;   //Incremeneting the file count
	new->sub_link = NULL;
	arr[index] = new;  //assign the array of index with new 

	sub_t *snew = malloc(sizeof(sub_t));   //Creating the new sub node 

	if(snew == NULL)
	{
	    return FAILURE;
	}

	snew->count = 0;  //Initilzation of the count with zero 
	(snew->count)++;  //incrementing the count 
	strcpy(snew->file_name,fname);  //Copying the file name 
	new->sub_link = snew;    
	snew->slink = NULL;
	return SUCCESS;
    }
    else
    {
	//int flag=0; 
	main_t *temp = arr[index];  //Creating the temp pointer and updating the index of array 
	main_t *prev_main =temp ;   //Creating the prev pointer and updating the temp
	//printf("DATA : %s\n",temp -> word);

	while( temp  != NULL ) //Loop to travers the main-node 
	{
	    prev_main =temp ;

	    if ( strcmp (temp ->word ,word) == 0)  //Comparing the word is same as new word to be insert
	    {
		sub_t *temp_s= temp ->sub_link;  //Creating the temp pointer to sub node
		sub_t *prev_sub =temp_s;

		while( temp_s )  //loop to travers through the sub-node
		{
		    prev_sub =temp_s ;
		    if (strcmp( temp_s ->file_name , fname) == 0)  //Comparing the filename with new file name to be inserted
		    {
			(temp_s -> count)++;  //if condition is true then increment the temp_s->count
			return SUCCESS;
		    }
		    else
		    {
			temp_s = temp_s ->slink;  //ifcondition is flase then traverse the list 
		    }
		}
		//	temp -> file_count = 0;
		(temp ->file_count)++;
		sub_t *new = malloc(sizeof(sub_t));

		if ( new ==NULL)
		{
		    return FAILURE ;
		}

		(new ->count)++;
		new -> slink = NULL;
		strcpy(new ->file_name ,fname);
		prev_sub ->slink =new ;

		return SUCCESS;
	    }
	    else
	    {
		temp =temp ->main_link;
	    }
	}

	main_t * new = malloc(sizeof(main_t));
	if (new ==NULL)
	{
	    return FAILURE ;
	}

	strcpy(new -> word , word) ;
	//printf("NEW OF DATA : %s\n" , new ->word);
	new -> main_link=NULL;
	(new ->file_count )++ ;
	//printf("NEW OF count : %d\n" , new ->file_count);

	new -> sub_link =NULL;
	prev_main ->main_link =new;
	sub_t * s_new = malloc( sizeof(sub_t));
	if ( s_new ==NULL)
	{
	    return FAILURE;
	}

	(s_new -> count)++ ;
	strcpy( s_new -> file_name , fname);
	new ->sub_link =s_new;
	s_new ->slink =NULL;
	printf("SUCCESSFUL EXECUTION \n");
	return SUCCESS;
    }
}

/*Funtion Prototype to create the database*/
int create_database( Flist ** head)
{
    printf("CREATEING DATABASE:\n");
    store(arr,27); //Function call to store the null in the hash table
    Flist * temp = *head ; //Deaclaring the temp pointer and updating with head
    int count =0 ;
    char word[1000];  //word to read the words from the files

    while(temp)  //loop to travers through the list
    {  
	count++;
	//printf("FILE : %d\n" ,count);
	fptr = fopen( temp -> data , "r");   //opening the file in read mode 

	if ( fptr == NULL)  //Checking the file is opened correctly or not
	{
	    perror("fopen");
	    fprintf(stderr, "ERROR: Unable to open file %s\n", temp ->data);
	    return FAILURE;
	}

	while (fscanf(fptr, "%s", word) != EOF)  //Loop to read the words from the file
	{
	    char ch = toupper(*word);   //Decalring the ch variable to convert the word to upper case
	    int index; 
	    index = ch % 65;   //To get the index of array 
	    // printf("INDEX = %d\n",index);

	    if(insert_hash(index,word,temp->data) == SUCCESS)  //Function call to insert the data to the hash table
	    {
		printf("INFO: Inserted to hash\n");
	    }
	}
	fclose(fptr);  //Closing the opened the file
	temp = temp -> link ; 
    }
    flag = 1;  //Making the flag as 1 
    return SUCCESS;
}
