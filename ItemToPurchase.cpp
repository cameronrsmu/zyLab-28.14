#include "ItemToPurchase.h"
#include <string>
#include <iostream>
using namespace std;

//constructors

ItemToPurchase::ItemToPurchase(){
  itemName = "";
  itemDescription = "";
  itemPrice = 0;
  itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
  itemName = name;
  itemDescription = description;
  itemPrice = price;
  itemQuantity = quantity;
}

//setters

void ItemToPurchase::SetName(string name){
  itemName = name;
}
void ItemToPurchase::SetDescription(string description){
  itemDescription = description;
} 
void ItemToPurchase::SetPrice(int price){
  itemPrice = price;
}
void ItemToPurchase::SetQuantity(int quantity){
  itemQuantity = quantity;
}

//getters

string ItemToPurchase::GetName() const{
  return itemName;
}
string ItemToPurchase::GetDescription() const{
  return itemDescription;
}
int ItemToPurchase::GetPrice() const{
  return itemPrice;
}
int ItemToPurchase::GetQuantity() const{
  return itemQuantity;
}

//other functions

void ItemToPurchase::PrintItemCost(){
  cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}
void ItemToPurchase::PrintItemDescription(){
  cout << itemName << ": " << itemDescription << endl;
}
