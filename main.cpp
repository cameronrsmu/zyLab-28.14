// https://github.com/cameronrsmu/zyLab-28.14 
// Cameron Riley, Ava Everett

// Changed if statement to switch statement, i'm honestly not sure if it's better. But with it i've gotten it to 29/31 points... I think those last two points are because it's a switch statement and I'm not sure how to fix it :C

#include <iostream>
#include "ShoppingCart.h"

using namespace std;
void PrintMenu();
void ExecuteMenu(char option, ShoppingCart& theCart);

int main() {
    string customerName;
    string date;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, date);

    ShoppingCart shoppingCart(customerName, date);

    cout << endl << "Customer name: " << customerName << endl;
    cout << "Today's date: " << date << endl;
    cout << endl;

    PrintMenu();
    cout << endl;
    char menuOption;
    while (true) {
        cout << "Choose an option:" << endl;
        cin >> menuOption;
        cin.ignore(); 

        if (menuOption == 'q') {
            break; // Quit the program
        }
        ExecuteMenu(menuOption, shoppingCart);
        cout << endl;
        PrintMenu();
        cout << endl;
    }

    return 0;
}

void PrintMenu() {
    cout << "MENU" << endl; // the endl's here causes a test to fail. When removed that test will pass, but also breaks everythin elseg in the process
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl; // endls also causes a test to fail, breaks everything when removed
  
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    switch (option) {
    case 'a': {
        string itemName, itemDesc;
        int itemPrice, itemQty;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, itemName);
        cout << "Enter the item description:" << endl;
        getline(cin, itemDesc);
        cout << "Enter the item price:" << endl;
        cin >> itemPrice;
        cout << "Enter the item quantity:" << endl;
        cin >> itemQty;
        cin.ignore();

        ItemToPurchase newItem(itemName, itemDesc, itemPrice, itemQty);
        theCart.AddItem(newItem);
        break;
    }
    case 'd': {
        string itemName;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        getline(cin, itemName);
        theCart.RemoveItem(itemName);
        break;
    }
    case 'c': {
        string itemName;
        int newQty;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, itemName);
        cout << "Enter the new quantity:" << endl;
        cin >> newQty;
        cin.ignore();

        ItemToPurchase item;
        item.SetName(itemName);
        item.SetQuantity(newQty);
        theCart.ModifyItem(item);
        break;
    }
    case 'i':
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        theCart.PrintDescriptions();
        break;
    case 'o':
        cout << "OUTPUT SHOPPING CART" << endl;
        theCart.PrintTotal();
         // Causes a test to fail, but when removed breaks everything else
        break;
    default:
      break;
    }
}
