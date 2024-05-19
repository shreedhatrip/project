#ifndef ITEM_H
#define ITEM_H

typedef struct {
    int id;
    char description[100];
    int stock;
    float price;
} Item;

void readItemsFromFile(const char* filename);
void displayItems(int customerId, const char* customerName, const char* customerContact);
Item* findItemById(int id);

#endif
