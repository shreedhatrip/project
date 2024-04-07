#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct {
    int id;
    char name[100];
    char contact[100];
} Customer;

void addCustomer(int id, const char* name, const char* contact);
void displayCustomers();

#endif
