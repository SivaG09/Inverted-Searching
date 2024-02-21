/*
Name: Sivasubramanian
Date: 10/12/23
Description: Save Database Function
*/

#include"inverted_search.h"

/*Function to save te the data */
int save_data(main_t **arr)
{
    FILE *fptr_save = fopen( "backup.txt" , "w");  //Decalring the file pointer and creatig the backup file in write mode
    int size_data ;
    //fwrite ( "index\n" , 1 , 5, fptr_save); 
    for(int i = 0; i < 27; i++)  //Loop to run the through  hash table 
    { 
	if ( arr[i] != NULL)  //Checking the array of i is equal to NULL or not 
	{
	    main_t *temp_m = arr[i]; //Creating the temp pointer for main node  
	    while ( temp_m)  //Loop to traverse through the main_node
	    {
		/*TO STORE THE   # AT FIRST*/
		fwrite ( "#" , 1 , 1, fptr_save);

		/*TO STORE THE INDEX*/
		char data[4];
		sprintf( data , "%d" , i);
		size_data=strlen(data);
		fwrite( data , 1 , size_data , fptr_save);
		fwrite(";" , 1, 1 , fptr_save);

		/*To store data */
		size_data = strlen(temp_m->word);
		fwrite(temp_m ->word , 1 , size_data,fptr_save);
		fwrite(";" , 1, 1 , fptr_save);

		/*To store file count */

		size_data = strlen(temp_m->word);
		char file_count_[4] ;
		sprintf( file_count_, "%d" , temp_m -> file_count);
		size_data = strlen(file_count_);
		fwrite( file_count_ , 1 , size_data , fptr_save);
		fwrite(";" , 1, 1 , fptr_save);

		sub_t *temp = temp_m ->sub_link;

		while ( temp !=NULL)
		{
		    /*To store File name */
		    size_data = strlen(temp -> file_name);
		    fwrite( temp -> file_name , 1 ,  size_data , fptr_save);
		    fwrite(";" , 1, 1 , fptr_save);

		    /*To store word count */
		    char word_count_[4] ;
		    sprintf( word_count_ , "%d" , temp -> count);
		    size_data = strlen(word_count_);
		    fwrite( word_count_ , 1 ,size_data , fptr_save);
		    fwrite(";" , 1, 1 , fptr_save);
		    temp = temp ->slink; //update temp as temp of link
		}

		temp_m = temp_m -> main_link ;  //update temp_m with temp_m of main_link

		/*to store hash at last */
		fwrite("#" , 1, 1 , fptr_save);

		/* to move to next line */
		fwrite("\n" , 1, 1 , fptr_save);
	    }
	}
    }

    fclose(fptr_save);  //Closing the opened file
    return SUCCESS;
}
