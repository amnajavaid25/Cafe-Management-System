#include "filemanager.h"
#include <fstream>
#include <iostream>
#include <string>
#include"order.h"

using namespace std;

void filemanager::saveusertofile(const std::string& userData) {
    saveDataToFile("user_data.txt", userData);
}

void filemanager::savemenuitemtofile(const string& menuItemData) {
    int choice = 0;
    cout << "Enter 1 for the student menu, 2 for the faculty menu, and 3 for the non-faculty menu: ";
    cin >> choice;
    cin.ignore(); 
    string fileName;

    switch (choice) {
    case 1:
        fileName = "studentmenu_items.txt";
        break;
    case 2:
        fileName = "facultymenu_items.txt";
        break;
    case 3:
        fileName = "nonfacultymenu_items.txt";
        break;
    default:
        cout << "Enter the right choice." << endl;
        return;
    }

    // Saving menu items to different files based on the menu type
    saveDataToFile(fileName, menuItemData);
}

void filemanager::saveordertofile(const std::string& orderData)
{
    ofstream file("orders.txt", ios::app);

    if (file.is_open()) {
        file << orderData << endl;
        file.close();
        cout << "Rating data saved to ratings.txt successfully." << endl;
    }
    else {
        cout << "Unable to open ratings.txt" << endl;
    }
}

void filemanager::saveeditedordertofile(const std::string& orderData) {
    ofstream outFile("temp_orders.txt");

    if (outFile.is_open()) {
        outFile << orderData << endl;
        outFile.close();

        int result = remove("orders.txt");
        if (result != 0) {
            cout << "Error deleting original file." << endl;
        }

        result = rename("temp_orders.txt", "orders.txt");
        if (result != 0) {
            cout << "Error renaming file." << endl;
        }
    }
    else {
        cout << "Error opening file." << endl;
    }
}

void filemanager::saveratingtofile(const std::string& ratingData) {
    ofstream file("ratings.txt", ios::app);

    if (file.is_open()) {
        file << ratingData << endl;
        file.close();
        cout << "Rating data saved to ratings.txt successfully." << endl;
    }
    else {
        cout << "Unable to open ratings.txt" << endl;
    }
}
void filemanager::savepayementtofile(const std::string& paymentData) {
    
    
    // Save the formattedPaymentData to the payments.txt file
    saveDataToFile("payments.txt", paymentData);
}


void filemanager::saveDataToFile(const string& fileName, const string& data) {
    ofstream file(fileName, ios::app);

    if (file.is_open()) {
        file << data << endl;
        file.close();
        cout << "Data saved to " << fileName << " successfully." << endl;
    }
    else {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void filemanager::displayuser_fromfile(const string& fileName)
{
    ifstream infile(fileName, ios::app);

    if (infile.is_open()) 
    {
        string line;
        while (getline(infile, line)) 
        {
            cout << line << std::endl;
        }
        infile.close();
    }

    else 
    {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void filemanager::displaymenuitem_fromfile(const string& fileName)
{
    ifstream infile(fileName, ios::app);

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close();
    }

    else
    {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void filemanager::displayorder_fromfile(const string& fileName)
{
    ifstream infile(fileName, ios::app);

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close();
    }

    else
    {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void filemanager::displayrating_fromfile(const string& fileName)
{
    ifstream infile(fileName, ios::app);

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << std::endl;
        }
        infile.close();
    }

    else
    {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void filemanager::displaypayment_fromfile(const string& fileName)
{
    ifstream infile(fileName, ios::app);

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << std::endl;
        }
        infile.close();
    }

    else
    {
        cout << "Unable to open file: " << fileName << endl;
    }
}
