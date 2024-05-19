#include <stdio.h>
#include <stdlib.h>
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
    strcpy(customers[numCustomers].name, name);
    strcpy(customers[numCustomers].contact, contact);
    numCustomers++;

    // Write customer data to file
    FILE *file = fopen("customers.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %s %s\n", id, name, contact);
        fclose(file);
    }
}

void displayCustomers() {
    printf("Customers:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("ID: %d, Name: %s, Contact: %s\n",
                customers[i].id, customers[i].name, customers[i].contact);
    }
}

Customer* findCustomerById(int id) {
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].id == id) {
            return &customers[i];
        }
    }
    return NULL; // Customer not found
}
