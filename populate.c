#include <string.h>
#include "populate.h"

void populateAddressBook(AddressBook *addressBook) 
{
    strcpy(addressBook->contacts[0].name, "John Doe");
    strcpy(addressBook->contacts[0].phone, "1234567890");
    strcpy(addressBook->contacts[0].email, "john@example.com");
    addressBook->contact_count = 1;
}

