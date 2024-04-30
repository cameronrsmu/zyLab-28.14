#include "ItemToPurchase.h"
#include <iostream>

// Constructor

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
    : itemName(name), itemDescription(description), itemPrice(price), itemQuantity(quantity) {}

// Setters

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

// Getters

string ItemToPurchase::GetName() const {
    return itemName;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

int ItemToPurchase::GetPrice() const {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

// Other Functions

void ItemToPurchase::PrintItemCost() const {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() const {
    cout << itemName << ": " << itemDescription << endl;
}
