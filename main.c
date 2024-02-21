/*
 Name : Sivasubramanian
 Date : 10/12/23
 Title : Inverted Search
 Description :The purpose of storing an index is to optimize speed and performance in finding relavent documents for a search query. Without an index, the search engine would scan every document in the corpus, which would require considerable time and computing power.
 */
#include "inverted_search.h"

int main(int argc, char *argv[])
{
    int option;
    /* Define the main function here */
    if(argc <= 1 || argc > 5)
    {
	printf("ERROR: Please pass vaild Arguments\n");
	printf("USAGE: ./a.out file1.txt file2.txt file3.txt( Pleas Pass files only less 5 unique files)\n");
	return FAILURE;
    }

    if(file_vaildation(argc,argv) == SUCCESS)
    {
	printf("INFO: The read and vaildation is SUCCESSFULL\n");

	print_list(head);
	printf("Select your choice among following Options:\n");

	while(1)
	{
	    printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Save Database\n5. Update Database\n6. Exit\nEnter your choice : ");
	    scanf("%d",&option);

	    switch(option)
	    {
		case 1:
		    if (create_database(&head) == FAILURE) //Function call to create database
		    {
			printf("ERROR : Creating the database is Failure!!\n");
		    }
		    else
		    {
			printf("INFO: Creating the database is Success!!\n");
		    }
		    break;

		case 2:
		    if(display_HT(arr,27) == FAILURE)   //Function to dispaly the hash table
		    {
			printf("ERROR: The Hash Can't be able to Display!!\n");
		    }
		    else
		    {
			printf("INFO: THE Hash Displayed Succesfully!!\n");
		    }
		    break;

		case 3:
		    if(search_word(arr) == FAILURE)  //Function call to dearch word
		    {
			printf("INFO: No Data in Database!!\n");
		    }
		    else
		    {
			printf("INFO: The Search is Successfull!!\n");
		    }
		    break;

		case 4:
		    if( save_data(arr) == FAILURE)  //Function call to save the data 
		    {
			printf("ERROR: The Database Failed to Save!!\n");
		    }
		    else
		    {
			printf("INFO: The Database is Saved Successfully!!\n");
		    }
		    break;

		case 5:
		    if(update( ) == SUCCESS)   //Function call to update the data base
		    {
			printf("INFO: The Database is Updated Successfully!!\n");
		    }
		    else
		    {
			printf("INFO: The Database Failed to Update!!\n");
		    }
		    break;

		case 6:
		    return FAILURE;

	    }

	}

    }
}
