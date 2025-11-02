#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    if (addressBook->contact_count == 0) 
    {
        printf("No contacts found.\n");
        return;
    }
    for (int i = 0; i < addressBook->contact_count - 1; i++) 
    {
        for (int j = i + 1; j < addressBook->contact_count; j++) 
        {
            int cmp = 0;
            if (sortCriteria == 1)
                cmp = strcmp(addressBook->contacts[i].name, addressBook->contacts[j].name);
            else if (sortCriteria == 2)
                cmp = strcmp(addressBook->contacts[i].phone, addressBook->contacts[j].phone);
            else if (sortCriteria == 3)
                cmp = strcmp(addressBook->contacts[i].email, addressBook->contacts[j].email);
            if (cmp > 0) 
            {
                Contact temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < addressBook->contact_count; i++) 
    {
        printf("%d. %s | %s | %s\n", i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
}
void initialize(AddressBook *addressBook) 
{
    addressBook->contact_count = 0;
    populateAddressBook(addressBook);
    loadContactsFromFile(addressBook);
}
void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook);
    printf("Contacts saved. Exiting...\n");
    exit(EXIT_SUCCESS);
}
void createContact(AddressBook *addressBook) 
{
    if (addressBook->contact_count >= MAX_CONTACTS) 
    {
        printf("Address book is full.\n");
        return;
    }
    Contact c;
    printf("Enter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Phone: ");
    scanf(" %[^\n]", c.phone);
    printf("Enter Email: ");
    scanf(" %[^\n]", c.email);
    addressBook->contacts[addressBook->contact_count++] = c;
    printf("Contact added successfully.\n");
}
void searchContact(AddressBook *addressBook) 
{
    int choice;
    char query[NAME_LEN];
    printf("\nSearch by:\n1. Name\n2. Phone\n3. Email\nEnter choice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    scanf(" %[^\n]", query);
    for (int i = 0; i < addressBook->contact_count; i++) 
    {
        if ((choice == 1 && strcasecmp(addressBook->contacts[i].name, query) == 0) ||
            (choice == 2 && strcasecmp(addressBook->contacts[i].phone, query) == 0) ||
            (choice == 3 && strcasecmp(addressBook->contacts[i].email, query) == 0)) 
            {
            printf("Found: %s | %s | %s\n",
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}
void editContact(AddressBook *addressBook) 
{
    char name[NAME_LEN];
    printf("Enter name to edit: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < addressBook->contact_count; i++) 
    {
        if (strcasecmp(addressBook->contacts[i].name, name) == 0) 
        {
            int choice;
            printf("Editing %s\n", addressBook->contacts[i].name);
            printf("What do you want to edit?\n");
            printf("1. Phone\n");
            printf("2. Email\n");
            printf("3. Both Phone and Email\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            if (choice == 1 || choice == 3) 
            {
                printf("Enter new Phone: ");
                scanf(" %[^\n]", addressBook->contacts[i].phone);
            }
            if (choice == 2 || choice == 3) 
            {
                printf("Enter new Email: ");
                scanf(" %[^\n]", addressBook->contacts[i].email);
            }
            printf("Contact updated.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}
void deleteContact(AddressBook *addressBook) 
{
    char name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < addressBook->contact_count; i++) 
    {
        if (strcasecmp(addressBook->contacts[i].name, name) == 0) 
        {
            for (int j = i; j < addressBook->contact_count - 1; j++) 
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->contact_count--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
} 