//inventory management system
#include <iostream>
#include <cstring>
using namespace std;

struct Item{
    int itemID;
    char itemName[50];
    int quantity;
    float price;
};

Item items[100];

void addItem(Item items[], int &numItems){
    cout << "Enter item ID: ";
    cin >> items[numItems].itemID;
    cin.ignore();
    cout << "Enter item name: ";
    cin.getline(items[numItems].itemName, 50);
    cout << "Enter quantity: ";
    cin >> items[numItems].quantity;
    cout << "Enter price: ";
    cin >> items[numItems].price;
    numItems++;
}

void displayInventory(const Item items[], int numItems){
    cout << "Item ID | Item Name | Quantity | Price " << endl;

    if (numItems == 0){
        cout << "No items to display. Please input data first" << endl;
    }
    for (int i = 0; i < numItems; i++){
        cout << items[i].itemID << " | " << items[i].itemName << " | " << items[i].quantity << " | " << items[i].price << endl;
    }
}

void calculateTotalValue(const Item items[], int numItems){
    float totalValue = 0;
    for (int i = 0; i < numItems; i++){
        totalValue += items[i].quantity * items[i].price;
    }
    cout << "Total Value of Inventory: " << totalValue << endl;
}

void updateItemQuantity(Item items[], int numItems, int itemID, int newQuantity){
    bool found = false;
    for (int i = 0; i < numItems; i++){
        if (items[i].itemID == itemID){
            items[i].quantity = newQuantity;
            found = true;
        }
    }
    if (!found){
        cout << "Item not found" << endl;
    }
}

int main(){
int choice;
int numItems = 0;
    do {
        cout << "1. Add Item" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Calculate Total Value" << endl;
        cout << "4. Update Item Quantity" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            addItem(items, numItems);
            break;
        case 2:
            displayInventory(items, numItems);
            break;
        case 3:
            calculateTotalValue(items, numItems);
            break;
        case 4:
            int itemID, newQuantity;
            cout << "Enter item ID: ";
            cin >> itemID;
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            updateItemQuantity(items, numItems, itemID, newQuantity);
            break;
        case 5:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 5);

return 0;
}