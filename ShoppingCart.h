#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"
#include <vector>
#include <string>
using namespace std;

class ShoppingCart {
public:
    ShoppingCart(string customerName = "none", string date = "January 1, 2016");

    string GetCustomerName() const;
    string GetDate() const;

    void AddItem(const ItemToPurchase& item);
    void RemoveItem(string itemName);
    void ModifyItem(const ItemToPurchase& item);

    int GetNumItemsInCart() const;
    double GetCostOfCart() const;

    void PrintTotal() const;
    void PrintDescriptions() const;

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};

#endif
