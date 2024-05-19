#include <stdio.h>
#include "item.h"
#include "customer.h"

int main() {
    readItemsFromFile("items.txt");

    int customerId;
    char name[100];
    char contact[100];

    printf("Enter customer details:\n");
    printf("Customer ID: ");
    scanf("%d", &customerId);

    printf("Name: ");
    scanf("%s", name); 

    printf("Contact: ");
    scanf("%s", contact); 

    addCustomer(customerId, name, contact);

  
    displayItems(customerId, name, contact);
    displayCustomers();

    return 0;
}

