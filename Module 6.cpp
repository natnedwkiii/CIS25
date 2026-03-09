#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// ========================
// 1️⃣ Shopping Cart Item Class
// ========================
class Item {
public:
    string name;
    double price;
    int quantity;

    // Constructor
    Item(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    Item() {
        name = "";
        price = 0.0;
        quantity = 0;
    }

    double getTotalPrice() const {
        return price * quantity;
    }
};

// ========================
// Function to add item
// ========================
void addItem() {
    string name;
    double price;
    int quantity;

    cin.ignore(); // clear input buffer
    cout << "Enter item name: ";
    getline(cin, name);

    cout << "Enter item price: ";
    cin >> price;

    cout << "Enter item quantity: ";
    cin >> quantity;

    // Append to file
    ofstream outFile("cart.txt", ios::app); // append mode
    if (outFile.is_open()) {
        outFile << name << " " << price << " " << quantity << endl;
        outFile.close();
        cout << "Item added to cart!\n";
    } else {
        cout << "Error: Unable to open file.\n";
    }
}

// ========================
// Function to view checkout
// ========================
void viewCheckout() {
    ifstream inFile("cart.txt");
    if (!inFile) {
        cout << "No items in cart.\n";
        return;
    }

    vector<Item> cart;
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        double price;
        int quantity;

        ss >> name >> price >> quantity;
        cart.push_back(Item(name, price, quantity));
    }
    inFile.close();

    double grandTotal = 0;
    cout << "\n===== CHECKOUT =====\n";
    for (const auto &item : cart) {
        double total = item.getTotalPrice();
        cout << item.name << " - $" << item.price
             << " x " << item.quantity
             << " = $" << total << endl;
        grandTotal += total;
    }
    cout << "Grand Total: $" << grandTotal << "\n";
}

// ========================
// Main Program
// ========================
int main() {
    int choice;

    do {
        cout << "\n===== SHOPPING CART MENU =====\n";
        cout << "1. Add item to cart\n";
        cout << "2. View checkout\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewCheckout();
                break;
            case 3:
                cout << "Thank you for using the program!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}