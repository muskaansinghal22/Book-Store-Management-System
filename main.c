///BOOK STORE PROJECT

#include<stdio.h>
#include<string.h>

//USER-DEFINED FUNCTIONS
void add_book();
void delete_book();
void view_book();
void search_book();
void modify_book();
int unique_book_id();
int unique_book_name();
void display_desired_book(int);

//GLOBAL VARIABLE FOR NUMBER OF DISTINCT BOOKS IN THE LIBRARY
int count=0;

//BASIC STRUCTURE OF THE LIBRARY DATABASE
struct books
{
    int book_id;
    char book_name[50];
    char book_author[30];
    char book_publications[30];
    int book_pages;
    int book_price;
    int book_quantity;
}library[100];

int main()
{
    printf("\t\t\t***********************************************************************************");
    printf("\n\t\t\t                                                                                 ");
    printf("\n\t\t\t                                                                                 ");
    printf("\n\t\t\t                        Library management System Project in C                   ");
    printf("\n\t\t\t                                                                                 ");
    printf("\n\t\t\t                                                                                 ");
    printf("\n\t\t\t*********************************************************************************");

    int main_choice=1;
    while(main_choice!=0)
    {
        printf("\n********BOOK STORE MAIN MENU********\n");
        printf("\t0.Exit\n");
        printf("\t1.Add Book\n");
        printf("\t2.Delete Book\n");
        printf("\t3.View Books\n");
        printf("\t4.Search Book\n");
        printf("\t5.Modify Book\n");
        printf("\n\tEnter choice(0,1,2,3,4,5): ");
        scanf("%d",&main_choice);

        switch(main_choice)
        {
            //for exiting the menu
            case 0:
            {
                printf("EXITING THE PROGRAM!!! Thank you!!!");
                break;
            }

            //for adding books
            case 1:
            {
                add_book();
                break;
            }

            //for deleting books
            case 2:
            {
                delete_book();
                break;
            }

            //for viewing books
            case 3:
            {
                view_book();
                break;
            }

            //for searching books
            case 4:
            {
                search_book();
                break;
            }

            //for modifying details of the books
            case 5:
            {
                modify_book();
                break;
            }

            //if the input is invalid
            default:
            {
                printf("\n\n\t\tINVALID INPUT!!! Try again...");
            }
        }
    }

}

//USER-DEFINED FUNCTION TO ADD BOOK INTO THE LIBRARY
void add_book()
{
    printf("\n\tEnter Book_ID:");
    scanf("%d", &library[count].book_id);
    if(unique_book_id()==0)
    {
        printf("\tPlease enter unique Book_ID.\n");
        printf("\tReturning to Main Menu.\n");
        return;
    }

    printf("\tEnter Book_Name:");
    fflush(stdin);
    gets(library[count].book_name);
    if(unique_book_name()==0)
    {
        printf("\tPlease enter unique Book_Name.\n");
        printf("\tReturning to Main Menu.\n");
        return;
    }

    printf("\tEnter Book_Author:");
    gets(library[count].book_author);

    printf("\tEnter Publications:");
    gets(library[count].book_publications);

    printf("\tEnter Book_Pages:");
    scanf("%d", &library[count].book_pages);

    printf("\tEnter Book_Price:");
    scanf("%d", &library[count].book_price);

    printf("\tEnter Book_Quantity:");
    scanf("%d", &library[count].book_quantity);

    count++;
    printf("\n\tBOOK ADDED SUCCESSFULLY\n");
}

void delete_book()
{
    int choice=0;
    printf("\n\t*********DELETE SUB MENU:**********\n");

    printf("\t0=> BACK TO MAIN MENU\n");
    printf("\t1=> Delete by : Book_ID\n");
    printf("\t2=> Delete by : Book_Name\n");
    printf("\t3=> Delete All Record\n");

    printf("\n\tEnter Your Choice(0,1,2,3): ");
    scanf("%d", &choice);

    view_book();

    //EXITING TO MAIN MENU WITHOUT DELETING ANY BOOK
    if(choice==0)
    {
        printf("\tReturning Back to the Main Menu.\n");
    }

    //DELETING BY BOOK_ID
    else if(choice==1)
    {
        int book_id_to_delete=0;
        printf("\tEnter The Book_ID to delete: ");
        scanf("%d", &book_id_to_delete);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_id_to_delete == library[i].book_id)
            {
                int j=0;
                for(j=i; j<count; j++)
                {
                    library[j]=library[j+1];
                }
                count--;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("\tBOOK WITH BOOK_ID %d HAS BEEN DELETED!\n", book_id_to_delete);
        }
        else
        {
            printf("\tBOOK WITH BOOK_ID %d NOT FOUND!\n", book_id_to_delete);
        }
        view_book();
    }

    //DELETING BY BOOK_NAME
    else if(choice==2)
    {
        char book_name_to_delete[50];
        fflush(stdin);
        printf("\tEnter Book_Name to Delete: ");
        gets(book_name_to_delete);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_name_to_delete, library[i].book_name)==0)
            {
                int j=0;
                for(j=i; j<count; j++)
                {
                    library[j]=library[j+1];
                }
                count--;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("\tBOOK WITH BOOK_NAME %s HAS BEEN DELETED!\n", book_name_to_delete);
        }
        else
        {
            printf("\tBOOK WITH BOOK_NAME %s NOT FOUND!\n", book_name_to_delete);
        }
        view_book();
    }

    //DELETING ALL RECORDS
    else if(choice==3)
    {
        count=0;
        printf("\tALL RECORDS HAVE BEEN DELETED!\n");
        view_book();
    }

    //DEFAULT CONDITION FOR INVALID INPUT
    else
    {
        printf("\tKindly Enter a Valid Input...\n");
        printf("\tReturning Back to the Main Menu.\n");
    }
    return;
}

void view_book()
{
	if(count==0)
	{
    	printf("\tLIBRARY IS EMPTY.\n");
    	return;
	}
	else
	{
    	int i=0;

    	//PRINTING TABLE FOR ALL THE BOOKS IN THE LIBRARY
    	printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
    	for(i=0; i<count; i++)
    	{
        	//Printing S.No.
        	printf("|   %d   ", i+1);

        	//Printing Book_ID
        	printf("|   %d   ", library[i].book_id);

        	//Printing Book_Name
        	printf("|   %s   ", library[i].book_name);

        	//Printing Book_Author
        	printf("|   %s   ", library[i].book_author);

        	//Printing Book_Publications
        	printf("|  %s  ", library[i].book_publications);

        	//Printing Book_Pages
        	printf("|    %d    ", library[i].book_pages);

        	//Printing Book_Price
        	printf("|    %d    ", library[i].book_price);

        	//Printing Book_Quantity
        	printf("|    %d    |\n", library[i].book_quantity);
    	}
	}
}

void search_book()
{
    int choice=0;
    printf("\n\t*********SEARCH SUB MENU:**********\n");

    printf("\t0=> BACK TO MAIN MENU\n");
    printf("\t1=> Search by : Book_ID\n");
    printf("\t2=> Search by : Book_Name\n");
    printf("\t3=> Search by : Book_Author\n");
    printf("\t4=> Search by : Book_Publications\n");
    printf("\t5=> Search by : Book_Pages\n");
    printf("\t6=> Search by : Book_Price\n");
    printf("\t7=> Search by : Book_Quantity\n");

    printf("\n\tEnter Your Choice(0,1,2,3,4,5,6,7): ");
    scanf("%d", &choice);

    //EXITING TO MAIN MENU WITHOUT SEARCHING ANY BOOK
    if(choice==0)
    {
        printf("\tReturning Back to the Main Menu.\n");
    }

    //SEARCHING BY BOOK_ID
    else if(choice==1)
    {
        int book_id_to_search=0;
        printf("\tEnter the Book_ID to Search: ");
        scanf("%d", &book_id_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_id_to_search == library[i].book_id)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
                break;
            }
        }
        if(flag==0)
        {
            printf("\tBook_ID not found.\n");
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_NAME
    else if(choice==2)
    {
        char book_name_to_search[50];
        printf("\tEnter the Book_Name to Search: ");
        fflush(stdin);
        gets(book_name_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_name_to_search, library[i].book_name)==0)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
                break;
            }
        }
        if(flag==0)
        {
            printf("\tBook_Name not found.\n");
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_AUTHOR
    else if(choice==3)
    {
        char book_author_to_search[30];
        printf("\tEnter the Book_Author to Search: ");
        fflush(stdin);
        gets(book_author_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_author_to_search, library[i].book_author)==0)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %s BOOK_AUTHOR\n", book_author_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_PUBLICATIONS
    else if(choice==4)
    {
        char book_publications_to_search[30];
        printf("\tEnter the Book_Publications to Search: ");
        fflush(stdin);
        gets(book_publications_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_publications_to_search, library[i].book_publications)==0)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %s BOOK_PUBLICATION\n", book_publications_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_PAGES
    else if(choice==5)
    {
        int book_pages_to_search=0;
        printf("\tEnter the Book_Pages to Search: ");
        scanf("%d", &book_pages_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_pages_to_search==library[i].book_pages)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %d BOOK PAGES\n", book_pages_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_PRICE
    else if(choice==6)
    {
        int book_price_to_search=0;
        printf("\tEnter the Book_Price to Search: ");
        scanf("%d", &book_price_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_price_to_search==library[i].book_price)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %d BOOK PRICE\n", book_price_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_QUANTITY
    else if(choice==7)
    {
        int book_quantity_to_search=0;
        printf("\tEnter the Book_Quantity to Search: ");
        scanf("%d", &book_quantity_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_quantity_to_search==library[i].book_quantity)
            {
                flag=1;
                printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");
                //Printing S.No.
                printf("|   %d   ", i+1);

                //Printing Book_ID
                printf("|   %d   ", library[i].book_id);

                //Printing Book_Name
                printf("|   %s   ", library[i].book_name);

                //Printing Book_Author
                printf("|   %s   ", library[i].book_author);

                //Printing Book_Publications
                printf("|  %s  ", library[i].book_publications);

                //Printing Book_Pages
                printf("|    %d    ", library[i].book_pages);

                //Printing Book_Price
                printf("|    %d    ", library[i].book_price);

                //Printing Book_Quantity
                printf("|    %d    |\n", library[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %d BOOK QUANTITY\n", book_quantity_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }
    else
    {
        printf("\tPlease Enter a Valid Option.\n");
        printf("\tReturning to Main Menu.\n");
    }
    return;
}

void modify_book()
{
    int choice=0;
    printf("\n\t********MODIFY MENU*********\n");
    printf("\t0=> Back to the Main Menu.\n");
    printf("\t1=> Search for the Book using Book_ID.\n");
    printf("\t2=> Search for the Book using Book_Name.\n");
    printf("\n\tEnter your Choice(0/1/2): ");
    scanf("%d", &choice);

    //RETURNING TO THE MAIN MENU
    if(choice==0)
    {
        printf("\tRETURNING TO MAIN MENU...\n");
        return;
    }

    //MODIFYING USING BOOK_ID
    else if(choice==1)
    {
        int book_id_to_search;
        view_book();
        printf("\tEnter Book_ID to search for the book to Modify: ");
        scanf("%d", &book_id_to_search);

        int i=0, index=0;
        for(i=0; i<count; i++)
        {
            if(book_id_to_search==library[i].book_id)
            {
                index=i;
                break;
            }
            else
            {
                index=-1;
            }
        }
        if(index==-1)
        {
            printf("\tBook_ID %d NOT FOUND.\n", book_id_to_search);
        }
        else
        {
            int choice_1=0;
            printf("\tBook_ID %d FOUND.\n", book_id_to_search);
            display_desired_book(index);

            printf("\n\t\t********MODIFY SUB-MENU********\n");
            printf("\t\t0=> Back to the Main Menu.\n");
            printf("\t\t1=> Modify Book_ID.\n");
            printf("\t\t2=> Modify Book_Name.\n");
            printf("\t\t3=> Modify Book_Author.\n");
            printf("\t\t4=> Modify Book_Publications.\n");
            printf("\t\t5=> Modify Book_Pages.\n");
            printf("\t\t6=> Modify Book_Price.\n");
            printf("\t\t7=> Modify Book_Quantity.\n");
            printf("\n\t\tEnter your Choice(0,1,2,3,4,5,6,7): ");
            scanf("%d", &choice_1);

            //RETURNING TO MAIN MENU
            if(choice_1==0)
            {
                printf("\n\tReturning to Main Menu.\n");
            }

            //MODIFYING BOOK_ID
            else if(choice_1==1)
            {
                int new_book_id;
                printf("\t\tModifying Book_ID...\n");
                printf("\t\tEnter New Book_ID: ");
                scanf("%d", &new_book_id);
                printf("\t\tOld Book_ID: %d ", library[index].book_id);
                library[index].book_id=new_book_id;
                printf("has been changed to: %d\n", library[index].book_id);
            }

            //MODIFYING BOOK_NAME
            else if(choice_1==2)
            {
                char new_book_name[50];
                printf("\t\tModifying Book_Name...\n");
                printf("\t\tEnter New Book_Name: ");
                fflush(stdin);
                gets(new_book_name);
                printf("\t\tOld Book_Name: %s ", library[index].book_name);
                strcpy(library[index].book_name, new_book_name);
                printf("has been changed to: %s\n", library[index].book_name);
            }

            //MODIFYING BOOK_AUTHOR
            else if(choice_1==3)
            {
                char new_book_author[30];
                printf("\t\tModifying Book_Author...\n");
                printf("\t\tEnter New Book_Author: ");
                fflush(stdin);
                gets(new_book_author);
                printf("\t\tOld Book_Author: %s ", library[index].book_author);
                strcpy(library[index].book_author, new_book_author);
                printf("has been changed to: %s\n", library[index].book_author);
            }

            //MODIFYING BOOK_PUBLICATIONS
            else if(choice_1==4)
            {
                char new_book_publications[30];
                printf("\t\tModifying Book_Publications...\n");
                printf("\t\tEnter New Book_Publications: ");
                fflush(stdin);
                gets(new_book_publications);
                printf("\t\tOld Book_Publications: %s ", library[index].book_publications);
                strcpy(library[index].book_publications, new_book_publications);
                printf("has been changed to: %s\n", library[index].book_publications);
            }

            //MODIFYING BOOK_PAGES
            else if(choice_1==5)
            {
                int new_book_pages;
                printf("\t\tModifying Book_Pages...\n");
                printf("\t\tEnter New Book_Pages: ");
                scanf("%d", &new_book_pages);
                printf("\t\tOld Book_Pages: %d ", library[index].book_pages);
                library[index].book_pages=new_book_pages;
                printf("has been changed to: %d\n", library[index].book_pages);
            }

            //MODIFYING BOOK_PRICE
            else if(choice_1==6)
            {
                int new_book_price;
                printf("\t\tModifying Book_Price...\n");
                printf("\t\tEnter New Book_Price: ");
                scanf("%d", &new_book_price);
                printf("\t\tOld Book_Price: %d ", library[index].book_price);
                library[index].book_price=new_book_price;
                printf("has been changed to: %d\n", library[index].book_price);
            }

            //MODIFYING BOOK_QUANTITY
            else if(choice_1==7)
            {
                int new_book_quantity;
                printf("\t\tModifying Book_Quantity...\n");
                printf("\t\tEnter New Book_Quantity: ");
                scanf("%d", &new_book_quantity);
                printf("\t\tOld Book_Quantity: %d ", library[index].book_quantity);
                library[index].book_quantity=new_book_quantity;
                printf("has been changed to: %d\n", library[index].book_quantity);
            }

            //DEFAULT FOR WRONG INPUT
            else
            {
                printf("\t\tPlease Enter a Valid Option.");
            }
        }
    }

    //MODIFYING USING BOOK_Name
    else if(choice==2)
    {
        char book_name_to_search[50];
        printf("\t\tEnter Book_Name to search for the book to Modify: ");
        fflush(stdin);
        gets(book_name_to_search);

        int i=0, index=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_name_to_search, library[i].book_name)==0)
            {
                index=i;
                break;
            }
            else
            {
                index=-1;
            }
        }
        if(index==-1)
        {
            printf("\t\tBook_Name %s NOT FOUND.\n", book_name_to_search);
        }
        else
        {
            int choice_1=0;
            printf("\t\tBook_Name %s FOUND.\n", book_name_to_search);
            display_desired_book(index);

            printf("\n\t\t********MODIFY SUB-MENU********\n");
            printf("\t\t0=> Back to the Main Menu.\n");
            printf("\t\t1=> Modify Book_ID.\n");
            printf("\t\t2=> Modify Book_Name.\n");
            printf("\t\t3=> Modify Book_Author.\n");
            printf("\t\t4=> Modify Book_Publications.\n");
            printf("\t\t5=> Modify Book_Pages.\n");
            printf("\t\t6=> Modify Book_Price.\n");
            printf("\t\t7=> Modify Book_Quantity.\n");
            printf("\n\t\tEnter your Choice(0,1,2,3,4,5,6,7): ");
            scanf("%d", &choice_1);

            //RETURNING TO MAIN MENU
            if(choice_1==0)
            {
                printf("\t\tReturning to Main Menu.\n");
            }

            //MODIFYING BOOK_ID
            else if(choice_1==1)
            {
                int new_book_id;
                printf("\t\tModifying Book_ID...\n");
                printf("\t\tEnter New Book_ID: ");
                scanf("%d", &new_book_id);
                printf("\t\tOld Book_ID: %d ", library[index].book_id);
                library[index].book_id=new_book_id;
                printf("has been changed to: %d\n", library[index].book_id);
            }

            //MODIFYING BOOK_NAME
            else if(choice_1==2)
            {
                char new_book_name[50];
                printf("\t\tModifying Book_Name...\n");
                printf("\t\tEnter New Book_Name: ");
                fflush(stdin);
                gets(new_book_name);
                printf("\t\tOld Book_Name: %s ", library[index].book_name);
                strcpy(library[index].book_name, new_book_name);
                printf("has been changed to: %s\n", library[index].book_name);
            }

            //MODIFYING BOOK_AUTHOR
            else if(choice_1==3)
            {
                char new_book_author[30];
                printf("\t\tModifying Book_Author...\n");
                printf("\t\tEnter New Book_Author: ");
                fflush(stdin);
                gets(new_book_author);
                printf("\t\tOld Book_Author: %s ", library[index].book_author);
                strcpy(library[index].book_author, new_book_author);
                printf("has been changed to: %s\n", library[index].book_author);
            }

            //MODIFYING BOOK_PUBLICATIONS
            else if(choice_1==4)
            {
                char new_book_publications[30];
                printf("\t\tModifying Book_Publications...\n");
                printf("\t\tEnter New Book_Publications: ");
                fflush(stdin);
                gets(new_book_publications);
                printf("\t\tOld Book_Publications: %s ", library[index].book_publications);
                strcpy(library[index].book_publications, new_book_publications);
                printf("has been changed to: %s\n", library[index].book_publications);
            }

            //MODIFYING BOOK_PAGES
            else if(choice_1==5)
            {
                int new_book_pages;
                printf("\t\tModifying Book_Pages...\n");
                printf("\t\tEnter New Book_Pages: ");
                scanf("%d", &new_book_pages);
                printf("\t\tOld Book_Pages: %d ", library[index].book_pages);
                library[index].book_pages=new_book_pages;
                printf("has been changed to: %d\n", library[index].book_pages);
            }

            //MODIFYING BOOK_PRICE
            else if(choice_1==6)
            {
                int new_book_price;
                printf("\t\tModifying Book_Price...\n");
                printf("\t\tEnter New Book_Price: ");
                scanf("%d", &new_book_price);
                printf("\t\tOld Book_Price: %d ", library[index].book_price);
                library[index].book_price=new_book_price;
                printf("has been changed to: %d\n", library[index].book_price);
            }

            //MODIFYING BOOK_QUANTITY
            else if(choice_1==7)
            {
                int new_book_quantity;
                printf("\t\tModifying Book_Quantity...\n");
                printf("\t\tEnter New Book_Quantity: ");
                scanf("%d", &new_book_quantity);
                printf("\t\tOld Book_Quantity: %d ", library[index].book_quantity);
                library[index].book_quantity=new_book_quantity;
                printf("has been changed to: %d\n", library[index].book_quantity);
            }

            //DEFAULT FOR WRONG INPUT
            else
            {
                printf("\t\tPlease Enter a Valid Option.");
            }
        }
        printf("\t\tReturning to Main Menu.\n");
        return;
    }
}

int unique_book_id()
{
    int i=0, flag=1;
    for(i=0; i<count; i++)
    {
        if(library[count].book_id==library[i].book_id)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int unique_book_name()
{
    int i=0, flag=1;
    for(i=0; i<count; i++)
    {
        if(strcmp(library[count].book_name,library[i].book_name)==0)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display_desired_book(int index)
{
    int i=0;
    for(i=0; i<count; i++)
    {
        if(i==index)
        {
            //PRINTING TABLE FOR THE DESIRED BOOK IN THE LIBRARY
            printf("| S.No. | book_id | book_name | book_author | book_publications | book_pages | book_price | book_quantity |\n");

            //Printing S.No.
            printf("|   %d   ", i+1);

            //Printing Book_ID
            printf("|   %d   ", library[i].book_id);

            //Printing Book_Name
            printf("|   %s   ", library[i].book_name);

            //Printing Book_Author
            printf("|   %s   ", library[i].book_author);

            //Printing Book_Publications
            printf("|  %s  ", library[i].book_publications);

            //Printing Book_Pages
            printf("|    %d    ", library[i].book_pages);

            //Printing Book_Price
            printf("|    %d    ", library[i].book_price);

            //Printing Book_Quantity
            printf("|    %d    |\n", library[i].book_quantity);
        }
    }
    return;
}
