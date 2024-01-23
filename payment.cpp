#include "payment.h"
#include"filemanager.h"
using namespace std;

// Default constructor
Payment::Payment() : payment_id(0), order_id(0), amount(0), payment_status("Pending") {}

// Parameterized constructor
Payment::Payment(int payment_id, int order_id, int amount, const string& payment_status)
    : payment_id(payment_id), order_id(order_id), amount(amount), payment_status(payment_status) {}

// Function to process the payment
void Payment::process_payment() 
{
    if (payment_status == "pending") {
        // Simulate payment processing logic
        cout << "\t\t\t\tProcessing payment for Order ID: " << order_id << "\n";
        cout << "\t\t\t\tAmount: $" << amount << "\n";
    }
    else {
        payment_status = "Paid"; // Updated payment status
        cout << "\t\t\t\tPayment processed successfully.\n";
    }
}

void Payment::save_payment_details() const 
{
    // Constructing a string containing payment data
    string paymentData ="Payment ID:" + to_string(this->payment_id) + "," +" Order ID:"+
        to_string(this->order_id) + "," +"Amount:"+
        to_string(this->amount) + "," +" Payment Status:"+
        this->payment_status;

    
    // Create an instance of filemanager to save payment data
    filemanager manager;
    manager.savepayementtofile(paymentData);
}