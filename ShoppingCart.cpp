#include "ShoppingCart.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart(string customerName, string date)
    : customerName(customerName), currentDate(date) {}

string ShoppingCart::GetCustomerName() const {
    return customerName;
}

string ShoppingCart::GetDate() const {
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
        if (it->GetName() == itemName) {
            cartItems.erase(it);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
    for (auto& it : cartItems) {
        if (it.GetName() == item.GetName()) {
            if (item.GetDescription() != "none") it.SetDescription(item.GetDescription());
            if (item.GetPrice() != 0) it.SetPrice(item.GetPrice());
            if (item.GetQuantity() != 0) it.SetQuantity(item.GetQuantity());
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() const {
    int totalQuantity = 0;
    for (const auto& item : cartItems) {
        totalQuantity += item.GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::GetCostOfCart() const {
    double totalCost = 0;
    for (const auto& item : cartItems) {
        totalCost += item.GetQuantity() * item.GetPrice();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        for (const auto& item : cartItems) {
            item.PrintItemCost();
        }
    }

    cout << endl << "Total: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl << "Item Descriptions" << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        for (const auto& item : cartItems) {
            item.PrintItemDescription();
        }
    }
}
