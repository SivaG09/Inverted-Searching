/*
Name: Sivasubramanian
Date: 10/12/2023
Discription:Display Function
*/

#include "inverted_search.h"

int display_HT(main_t **arr, int size)
{
    printf("DISPLAYING:\n");
    printf("index       word                      filecount        filename          wordcount  \n");


    for(int i = 0; i < size; i++)
    {
	main_t *temp_m = arr[i] ;

	printf("\n [%d] " , i); 

	//printf("index                     word                      filecount       \n");

	while ( temp_m)
	{
	    printf("        [%s]                      [%d]             " , temp_m -> word , temp_m -> file_count);
	    sub_t *temp = arr[i] ->sub_link;
	    while ( temp != NULL)
	    {
		printf("%s ", temp -> file_name);
		printf("            %d ", temp -> count); 
		//printf("\n=================STOP HERE====================\n");
	//	printf("\n");
		temp = temp ->slink;
	    }
	    temp_m = temp_m ->main_link ;
	}
    }
    printf("\n");
    return SUCCESS;
}
