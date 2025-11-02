#include <stdio.h>
#include "contact.h"
int main() 
{
    AddressBook addressBook;
    initialize(&addressBook);
    int choice, sortOption;
    while (1) 
    {
        printf("\n--- Address Book ---\n");
        printf("1. List Contacts\n");
        printf("2. Create Contact\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Sort by: 1. Name 2. Phone 3. Email\nEnter: ");
                scanf("%d", &sortOption);
                listContacts(&addressBook, sortOption);
                break;
            case 2:
                createContact(&addressBook);
                break;
            case 3:
                searchContact(&addressBook);
                break;
            case 4:
                editContact(&addressBook);
                break;
            case 5:
                deleteContact(&addressBook);
                break;
            case 6:
                saveAndExit(&addressBook);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}

