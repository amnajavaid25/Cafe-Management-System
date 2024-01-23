#pragma once

#include <iostream>
#include <string>
#include"filemanager.h"
class Payment {
public:
    int payment_id;
    int order_id;
    int amount;
    std::string payment_status;

public:
    // Default constructor
    Payment();

    // Parameterized constructor
    Payment(int payment_id, int order_id, int amount, const std::string& payment_status);

    // Function to process the payment
    void process_payment();
    //file handling function
    void  save_payment_details() const;
};