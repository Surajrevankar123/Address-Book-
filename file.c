#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define DATA_FILE "contacts.txt"

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp = fopen(DATA_FILE, "r");
    if (!fp) return;
    while (fscanf(fp, "%49[^|]|%14[^|]|%49[^\n]\n",
                  addressBook->contacts[addressBook->contact_count].name,
                  addressBook->contacts[addressBook->contact_count].phone,
                  addressBook->contacts[addressBook->contact_count].email) == 3) 
                  {
                    addressBook->contact_count++;
                }
                fclose(fp);
            }
void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fp = fopen(DATA_FILE, "w");
    if (!fp) 
    {
        printf("Error saving file.\n");
        return;
    }
    for (int i = 0; i < addressBook->contact_count; i++) 
    {
        fprintf(fp, "%s|%s|%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    fclose(fp);
}
