#include <stdio.h>
#include <string.h>
#include "customer.h"

#define MAX_CUSTOMERS 100

static Customer customers[MAX_CUSTOMERS];
static int numCustomers = 0;

void addCustomer(int id, const char* name, const char* contact) {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached\n");
        return;
    }

    customers[numCustomers].id = id;
    strncpy(customers[numCustomers].name, name, sizeof(customers[numCustomers].name) - 1);
    customers[numCustomers].name[sizeof(customers[numCustomers].name) - 1] = '\0'; // Ensure null-termination
    strncpy(customers[numCustomers].contact, contact, sizeof(customers[numCustomers].contact) - 1);
    customers[numCustomers].contact[sizeof(customers[numCustomers].contact) - 1] = '\0'; // Ensure null-termination
    numCustomers++;
}

void displayCustomers() {
    printf("Customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("ID: %d, Name: %s, Contact: %s\n",
                customers[i].id, customers[i].name, customers[i].contact);
    }
}
