#include <stdio.h>
#include "item.h"

#define MAX_ITEMS 100

static Item items[MAX_ITEMS];
static int numItems = 0;

void readItemsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    while (fscanf(file, "%d %99s %d %f", &items[numItems].id, items[numItems].description,
                                             &items[numItems].stock, &items[numItems].price) == 4) {
        numItems++;
        if (numItems >= MAX_ITEMS) {
            printf("Maximum number of items reached\n");
            break;
        }
    }

    fclose(file);
}

void displayItems(int customerId, const char* customerName, const char* customerContact) {
    printf("Customer ID: %d, Name: %s, Contact: %s\n", customerId, customerName, customerContact);
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("ID: %d, Description: %s, Stock: %d, Price: %.2f\n",
                items[i].id, items[i].description, items[i].stock, items[i].price);
    }
}

