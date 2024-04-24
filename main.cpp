// https://github.com/cameronrsmu/zyLab-28.14 
// Cameron Riley, Ava Everett

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu(ShoppingCart& theCart) {
   /* Type your code here */
   char option = 'x';
   while (option != 'q'){
      cout << "MENU" << endl;
      cout << "a - Add item to cart" << endl;
      cout << "d - Remove item from cart" << endl;
      cout << "c - Change item quantity" << endl;
      cout << "i - Output items' descriptions" << endl;
      cout << "o - Output shopping cart" << endl;
      cout << "q - Quit" << endl;
      cin >> option;
      ExecuteMenu(option, theCart);
   }
   
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   /* Type your code here */
   if (option == a){
      string newName, newDesc;
      int newPrice, newQuantity;
      ItemToPurchase newItem();
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, newName);
      cout << "Enter the item description:" << endl;
      getline(cin, newDesc);
      cout << "Enter the item price:" << endl;
      cin >> newPrice;
      cout << "Enter the item quantity:" << endl;
      cin >> newQuantity;
      newItem.SetPrice(newPrice);
      newItem.SetQuantity(newQuantity);
      newItem.SetDescription(newDesc);
      newItem.SetName(newName);
      theCart.AddItem(newItem);
   }
   if (option == d){
      string oldItem;
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      cin >> oldItem;
      theCart.RemoveItem(oldItem);
   }
   if (option == c){
      string oldName;
      int newQuan;
      ItemToPurchase modItem;
      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, oldName);
      cout << "Enter the new quantity:" << endl;
      cin >> newQuan;
      modItem.SetName(oldName);
      modItem.SetQuantity(newQuan);
      theCart.ModifyItem(modItem);
   }
   if (option == i){
      theCart.PrintDescriptions();
   }
   if (option == o){
      theCart.PrintTotal();
   }
}

int main() {
   /* Type your code here */
   string name;
   string date;
   cout << "Enter customer's name" << endl;
   getline(cin, name);
   cout << "Enter today's date:" << endl;
   getline(cin, date);
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << date << endl;
   ShoppingCart customerCart(name, date);
   PrintMenu();
   return 0;
}
