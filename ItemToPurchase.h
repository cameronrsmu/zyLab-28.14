#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase(string name = "", string description = "none", 
                   int price = 0, int quantity = 0);

    void SetName(string name);
    void SetDescription(string description);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    string GetName() const;
    string GetDescription() const;
    int GetPrice() const;
    int GetQuantity() const;

    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif
