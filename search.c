/*
Name: Sivasubramanian
Date: 10/12/23
Description: Search Function
*/


#include"inverted_search.h"

/*Function to search the word*/
int search_word(main_t **arr)
{
    printf("Enter the word to be searched: ");
    scanf(" %[^\n]",fword);  //To read the word from the user to be searched

    char ch = toupper(fword[0]);  //Calculating the index to dipaly the seaeching word deatials
    int index;
    index = ch % 65;

    main_t *temp_m = arr[index] ;

    if(arr[index] != NULL)
    {
	if(strcmp(temp_m->word,fword) == 0)  //Comparing the main_node word with entred word
	{
	    printf("index       word                      filecount        filename          wordcount  \n");
	    printf("\n [%d] " , index); 
	    //printf("I am in if\n");
	    while ( temp_m)  //Loop to traverse through the subnode
	    {
		printf("        [%s]                      [%d]             " , temp_m -> word , temp_m -> file_count);
		sub_t *temp = arr[index] ->sub_link;
		while ( temp != NULL)
		{
		    printf("%s ", temp -> file_name);
		    printf("            %d ", temp -> count); 
            printf("\n");
		    temp = temp ->slink;
		}
		temp_m = temp_m ->main_link ;
	    }
	    return SUCCESS;
	}
	else
	{
	    return FAILURE;
	}
    }
    return FAILURE;
}
