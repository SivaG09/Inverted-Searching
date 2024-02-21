/*
Name: Sivasubramanian
Date: 10/12/2023
Description: Update Function
*/

#include"inverted_search.h"

/*Function to delete the memory of the hash table*/
int delete_memory(main_t **arr)
{
    for(int i = 0; i < 27; i++)  //Loop to travers through the hash table
    {
	if(arr[i] != NULL)  //Checking the array index is not equal to NULL/not
	{
	    main_t *temp_m = arr[i] ;
	    main_t *prev_m = arr[i] ;

	    while ( temp_m)  //Loop to traverse through the main node
	    {
		sub_t *temp = arr[i] ->sub_link;
		sub_t *prev = arr[i] ->sub_link;
		while ( temp != NULL)  //Loop to traverse through the sub node
		{
		    /*Logic to free the memory*/
		    prev = temp;
		    temp = temp ->slink;
		    prev->slink = NULL;
		    (prev->count)--;
		    free(prev);
		}
		prev_m = temp_m;
		temp_m = temp_m ->main_link ;
		prev_m -> main_link = NULL;
		(prev_m -> file_count)--;
		free(prev_m);
	    }
	    printf("\n");
	}
	arr[i] = NULL;
    }
    return SUCCESS;
}

/*Function to update the data base*/
int update()
{
    if(flag == 0) 
    {
	printf("Enter the Backup File Name:");
	char file_name_[20];
	// scanf("\n");
	scanf(" %[^\n]" , file_name_); //read backup file name from the user

	printf("The File name is : %s\n",file_name_);

	if (open_files_check_empty(file_name_) == SUCCESS) //check file empty or not
	{
	    fptr = fopen(file_name_ , "r");  //open the file
	    if ( fptr == NULL) //check opened or not
	    {
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", file_name_);
		return FAILURE;
	    }
	    printf("INFO : Backup File Opened Successfully!!\n");
	   // printf("INFO: The hast table memory is cleared\n");
	    char line[1000];
	    while( fscanf(fptr, "%s", line) != EOF) //to read the file line by line
	    {
		//printf("I am in while\n");
		int index =atoi(strtok(line , "#;"));  //to get the index
		//printf("index : %d\n", index);
		char *word =strtok(NULL ,";");  //to get the word
		//printf("word : %s\n" , word);
		int f_count = atoi(strtok(NULL ,";"));  //to get the file count
		//printf("F_count : %d\n", f_count);

		for ( int i =0 ; i < f_count ; i++)  //to run the loop f_count times
		{
		    char *fname ;
		    fname =strtok(NULL , ";");  //to get the file names
		    //	printf("FILE :%s\n" , f_name);
		    if( check_no_duplicate(head,fname) == SUCCESS)
		    {
			insert_at_last(&head,fname);
		    }
		    int w_count = atoi(strtok(NULL , ";")); //to get word count
		    //	printf("W_COUNT : %d\n", w_count);
		    for( int j=0 ; j <w_count ; j++) //to run word count times
		    {
			insert_hash( index , word , fname);  //to insert the data to the hash table
		    }
		}
	    }
	    fclose(fptr);
	    return SUCCESS;
	}
	else
	{
	    printf("ERROR : Use a Existing Backup File\n");

	    return FAILURE ;
	}
    }
    else
    {
	printf("INFO: The DataBase is Updated You Can't Update Again\n");
	return FAILURE;
    }
}


/*Function to check the file is empty*/
int open_files_check_empty(char file_name_[])
{
    /*Logic to check file is empty or not*/
    fptr = fopen(file_name_,"r");
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) != 0)
    {
	printf("I am in if\n");
	return SUCCESS;
    }
    else
    {
	printf("I am in else\n");
	return FAILURE;
    }
    fclose(fptr);
}
