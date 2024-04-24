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
    scanf("%s", name); // Assuming name does not contain spaces

    printf("Contact: ");
    scanf("%s", contact); // Assuming contact does not contain spaces

    addCustomer(customerId, name, contact);

    // Display items along with customer details
    displayItems(customerId, name, contact);
    displayCustomers();

    return 0;
}
