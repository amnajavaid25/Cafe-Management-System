#include "order.h"
using namespace std;
#include <fstream>
#include <sstream>
#include<iostream>
// Default constructor
Order::Order() : order_id(0), customer_id(0), total_price(0) {}

// Parameterized constructor
Order::Order(int order_id, int customer_id, const string& items_ordered, int total_price, const string& order_status)
    : order_id(order_id), customer_id(customer_id), items_ordered(items_ordered), total_price(total_price), order_status(order_status) 
{}

ostream& operator<<(std::ostream& os, const Order& order) {
    // Implement how an Order object should be formatted when written to a file
    os << order.order_id << ' ' << order.customer_id << ' ' << order.items_ordered << ' ' << order.total_price << ' ' << order.order_status << endl;
    return os;
}

// Member function implementations
void Order::add_items(const string& new_item, int item_price)
{
    items_ordered += " " + new_item;
    total_price += item_price;
}

void Order::remove_items(const string& item_to_remove, int item_price) {
    ifstream inFile("orders.txt");
    ofstream outFile("temp_orders.txt");

    if (inFile.is_open() && outFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            size_t found = line.find(item_to_remove);
            if (found != string::npos && line.find("Items Ordered: ") != string::npos) {
                cout << "\t\t\t\tItem '" << item_to_remove << "' removed from order." << endl;
            }
            else {
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();

        remove("orders.txt");  // Remove the original file
        int result = rename("temp_orders.txt", "orders.txt");  // Rename the temp file to original
        if (result != 0) {
            cout << "\t\t\t\tError renaming file." << endl;
        }
    }
    else {
        cout << "\t\t\t\tError opening files." << endl;
    }
}



int Order::calculate_total() const
{
    return total_price;
}


bool Order::confirm_order()
{
    if (order_status == "Pending")
    {
        order_status = "Confirmed";
        return true;
    }

    else
    {
        cout << "\t\t\t\tOrder cannot be confirmed. Status: " << order_status << endl;
        return false;
    }
}


void Order::cancel_order()
{
    if (order_status == "Pending")
    {
        order_status = "Cancelled";
        cout << "\t\t\t\tOrder has been cancelled." << endl;
    }

    else
    {
        cout << "\t\t\t\tOrder cannot be cancelled. Status: " << order_status << endl;
    }
}


string Order::getItemsOrdered() const
{
    return items_ordered;
}

void Order::saveOrderToFile() const 
{
    string orderData = "Order ID: " + to_string(this->order_id) +
        ", Customer ID: " + to_string(this->customer_id) +
        ", Items Ordered: " + this->items_ordered +
        ", Total Price: " + to_string(this->total_price) +
        ", Order Status: " + this->order_status;

    filemanager manager;
    manager.saveordertofile(orderData);
}

