#pragma once

#include <iostream>
#include <string>
#include"menuattributes.h"
#include"filemanager.h"
using namespace std;


class Order {
private:

    int order_id;
    int customer_id;
    string items_ordered;
    int total_price;
    string order_status;

public:
    // Default constructor
    Order();

    // Parameterized constructor
    Order(int order_id, int customer_id, const string& items_ordered, int total_price, const string& order_status);

    // << overloading to access data to file
    friend ostream& operator<<(ostream& os, const Order& order);

    // Function to add items to the order
    void add_items(const string& new_item, int item_price);

    // Function to remove items from the order
    void remove_items(const string& item_to_remove, int item_price);

    // Function to calculate the total price
    int calculate_total() const;

    // Function to confirm the order
    bool confirm_order();

    // Function to cancel the order
    void cancel_order();

    // Getter for items_ordered
    string getItemsOrdered() const;
    //filehandling function
    void saveOrderToFile() const;
   
};

