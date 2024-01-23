#include "table_reservation.h"
#include<iostream>
using namespace std;
table_reservation::table_reservation()
{
    //set all the tables as available
    for (int i = 0; i < totalTables; i++)
    {
        tableStatus[i] = false;
    }
}

void table_reservation::displayAvailableTables()const
{
    //displays tables that are available, false
    cout << "\t\t\t\tAvailable Tables: ";
    for (int i = 0; i < totalTables; ++i)
    {
        if (!tableStatus[i])
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

void table_reservation::bookTable(int tableNumber)
{
    if (tableNumber < 1 || tableNumber > totalTables)
    {
        cout << "\t\t\t\tInvalid table number. Please choose a number between 1 and " << totalTables << "." << endl;
        return;
    }

    if (tableStatus[tableNumber - 1])
    {
        std::cout << "\t\t\t\tSorry, table " << tableNumber << " is already booked. Choose another table." << endl;
    }
    else
    {
        tableStatus[tableNumber - 1] = true;
        cout << "\t\t\t\tTable " << tableNumber << " booked successfully." << endl;
    }
}

void table_reservation::displayTableStatus()const
{
    for (int i = 0; i < totalTables; ++i)
    {
        cout << "\t\t\t\tTable " << i + 1 << ": " << (tableStatus[i] ? "Booked" : "Available") << endl;
    }
}