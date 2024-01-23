#include "Rating.h"

int Rating::RatingIDCounter = 0;

Rating::Rating() {}

void Rating::Rate(int menuItemID, filemanager& manager) {
    RatingID = ++RatingIDCounter;
    MenuItemID = menuItemID;

    cout << "\t\t\t\tCustomer ID# : ";
    cin >> CustomerID;
    cout << "\t\t\t\tHow much score would you give to the food item out of 10: ";
    cin >> Score;
    cout << "\t\t\t\tAny comments: ";
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, comments); // Read the entire line of comments

    // Prepare the rating data to be saved
    string ratingData = "Rating ID: " + to_string(RatingID) +
        ", Menu Item ID: " + to_string(MenuItemID) +
        ", Customer ID: " + to_string(CustomerID) +
        ", Score: " + to_string(Score) +
        ", Comments: " + comments;

    // Save the rating data to the file using the filemanager's saveratingtofile method
    manager.saveratingtofile(ratingData);
}