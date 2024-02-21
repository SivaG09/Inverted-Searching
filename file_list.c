/*
Name: Sivasubramanian
Date: 10/12/23
Description: File Validation Function
*/

#include"inverted_search.h"

/*Function to file vaildation*/
int file_vaildation(int argc,char *argv[])
{
    int flag =1; 
    if(argc == 2)  //Checking the arguments is passed is equal to 2 or not
    {
	if(strcmp(strstr(argv[1], "."),".txt") == 0) //Checking the passed file is .txt file/not
	{
	    printf("INFO: YES!, argv[1] is a .txt file\n");
	    insert_at_last(&head,argv[1]);
	    print_list(head);
	    return SUCCESS;	    
	}
	else
	{
	    printf("ERROR: Please pass the correct Arguments\n");
	    printf("USAGE: ./a.out file1.txt file2.txt file3.txt( Please Pass files only less 5 unique files)\n");
	    return FAILURE;
	}
    }

    if(argc > 2)
    {
	//	printf("NOT WORKING\n");
	for(int i = 1;i < argc ;i++)  //Loop to check the all argc till NULL
	{
	    //	    printf("I am HERE\n");
	    if(strcmp(strstr(argv[i], "."),".txt") == 0) //Checking the passed file is .txt files/not
	    {
		//	printf("INFO: YES!, argv[%d] is a .txt file\n",i);
		if (flag)
		{
		    insert_at_last( &head , argv[i]); 
		    flag = 0;
		}
		else
		{
		    if (check_no_duplicate( head , argv[i]) ==SUCCESS)   //Function call to check their are no duplicate files or not
		    {
			insert_at_last(&head ,argv[i]);
			printf("INFO: No Duplicates and successfully created the linked list\n");
		    }
		}
	    }
	}
	print_list(head);

	if(open_files(&head) == SUCCESS)  //Checking the file is empty or not 
	{
	    printf("INFO: The checking of Empty files is SUCCESSFULL\n");
	}

	//	print_list(head);
    }
    return SUCCESS;
}

/*Function to insert at last in single lisnked list*/
int insert_at_last(Flist **head, data_t data)
{
    Flist *new = malloc(sizeof(Flist)); //Creating the new node
    if(new == NULL)  //Checking the node is created or not 
    {
	return FAILURE;  //if condition is true then return FAILURE
    }

    strcpy(new -> data,data); //Updating the data to new node
    new ->link = NULL; //Updating the new link as NULL

    if(*head == NULL) //Checking list is empty or not
    {
	*head = new;  //Updating the head with new 
	return SUCCESS;
    }

    Flist *temp = *head;   //Declaring temp pointer and initilaztion with head
    while(temp -> link != NULL) //Loop to traverse through the list 
    {
	temp = temp -> link;  //Updatig the the temp with temp of link
    }

    temp -> link = new;  //Updating the temp of link with new 
    return SUCCESS;
}

/*Function to print the linked list*/
void print_list(Flist *head)
{
    if (head == NULL)  //Checking the list is empty/not
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	while (head)	//Loop to go through the list 	
	{
	    printf("%s -> ", head -> data); 
	    head = head -> link;  //Updating the head with head of link 
	}

	printf("NULL\n");
    }
}

/*Function to check the file is duplicate or not*/
int check_no_duplicate( Flist  * head , char *data)
{
    int flag =0 ;

    while(head)  //loop to traverse through the list 
    {
	if (strcmp( head -> data , data) == 0)  //Comparing the file name with anothe file name  
	{
	    flag =1 ;
	}
	head = head ->link ;
    }

    if (flag)
    {
	return FAILURE ;
    }
    else
    {
	return SUCCESS ;
    }
}

/*Function to check the file is empty or not */
int open_files(Flist **head)
{
    /*Declaroing the pointer and updating with respective values*/
    Flist *temp = *head; 
    Flist *prev = temp;

    while(temp)  //Loop travers through the linked list 
    {
	fptr = fopen(temp->data ,"r");   //opening the file and store in the file pointer 
	if (fptr ==NULL)
	{
	    perror("fopen");
	    fprintf(stderr, "ERROR: Unable to open file %s\n", temp->data);
	    return FAILURE;
	} 
	/*Logic to check the empty file */
	fseek(fptr,0,SEEK_END);
	if(ftell(fptr) != 0)
	{
	    printf("INFO: This file is not empty\n");
	    temp = temp->link;
	    fclose(fptr);
	    // printf("Here Your are\n");
	}
	else
	{
	    prev = temp;
	    // printf("I am here\n");
	    temp = temp->link;
	    sl_delete_element(head,prev->data);
	    // printf("Function is working\n");
	    printf("INFO: The File is empty and removed\n");
	    fclose(fptr);
	}
    }
    return SUCCESS;
}

/*Function to delete the element from the linked list */
int sl_delete_element(Flist **head, data_t data) //function to delete the element
{
    if (*head ==NULL) //check the list is empty or not
    {
	return FAILURE ;
    }

    Flist *temp =*head; //Declare and initialize the value of temp as head
    Flist *prev= *head; //Declare and initialize the value of prev as head

    if ((*head) ->data == data) //check the head of data is given data
    {
	*head =temp ->link; //update the head to temp of link
	free(temp); //free the temp
	return SUCCESS;
    }

    else
    {
	while(temp) //loop to traverse through the list
	{
	    if(temp ->data != data) //check the temp of data is not given data
	    {
		prev =temp;
		temp =temp->link; //update temp as temp of link
	    }

	    else
	    {
		prev->link =temp ->link; //update prev of link as temp of link
		free(temp);  //free the temp
		return SUCCESS;
	    }
	}
    }
    return FAILURE;
}
