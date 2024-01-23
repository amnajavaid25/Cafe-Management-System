#include <iostream>
#include "Inventory.h"
#include"Administrator.h"
#include"User.h"
#include"Cafe_staff.h"
#include"Customer.h"
#include"Facultymenu.h"
#include"filemanager.h"
#include"menuattributes.h"
#include"Menutype.h"
#include"nonfacmenu.h"
#include"table_reservation.h"
#include"studentmenu.h"
#include"Rating.h"
#include"payment.h"
#include"order.h"
#include<ctime>
#include<cstdlib>
#include <cmath>
#include <string>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

//22i-2025 Amna Javaid, 22i-2060 Tasmiya Asad, 22i-1998 Ziyan Murtaza

void loadingBar()
{

    system("Color 06");

    char x = 177, y = 219;

    cout << "\n\t\t\t\t\t\t\t\t\t\t" << "Loading...\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t";


    for (int i = 0; i < 26; i++)
    {
        cout << x;
    }

    cout << "\r";

    cout << "\t\t\t\t\t\t\t\t\t\t";


    for (int i = 0; i < 26; i++)
    {
        cout << y;


        Sleep(100);
    }

    cout << endl;
    cout << endl;
}


using namespace std;
int main() {
    cout << "\t\t\t\t   ***********************************************************************************************************" << endl;
    cout << "\t\t\t\t   *              ----------------       -------     -------------    -------------                          *" << endl;
    cout << "\t\t\t\t   *              |   _______   |       /       \\    |   ________|    |   ________|                          *" << endl;
    cout << "\t\t\t\t   *              |   |     |___|      /    /\\   \\   |   |            |   |                                  *" << endl;
    cout << "\t\t\t\t   *              |   |               /    /  \\   \\  |   |________    |   |________                          *" << endl;
    cout << "\t\t\t\t   *              |   |              |    /____\\   | |    ________|   |    ________|                         *" << endl;
    cout << "\t\t\t\t   *              |   |              |    ______   | |   |            |   |                                  *" << endl;
    cout << "\t\t\t\t   *              |   |              |    |     |  | |   |            |   |________                          *" << endl;
    cout << "\t\t\t\t   *              |   |__________    |    |     |  | |   |            |            |                         *" << endl;
    cout << "\t\t\t\t   *              |______________|   |____|     |__| |___|            |____________|                         *" << endl;
    cout << "\t\t\t\t   ***********************************************************************************************************" << endl;
    cout << "\t\t\t\t   *-------------------------------------------WELCOME TO FAST CAFE------------------------------------------*" << endl;
    cout << "\t\t\t\t   ***********************************************************************************************************" << endl;
    char c;

    cout << "\t\t\t\tKindly enter if you are administrator / cafe staff / customer " << endl;
    cout << "\t\t\t\tEnter a for administrator, b for cafe staff , c for customer:  ";
    cin >> c;

    loadingBar();

    if (c == 'a')
    {
        Administrator admin;
        int choice;
        do {
            cout << "\t\t\t\tAdministrator Menu:" << endl;
            cout << "\t\t\t\t1. View Menu" << endl;
            cout << "\t\t\t\t2. Add to Menu" << endl;
            cout << "\t\t\t\t3. Remove from Menu" << endl;
            cout << "\t\t\t\t4. Manage Inventory" << endl;
            cout << "\t\t\t\t5. Manage Discount" << endl;
            cout << "\t\t\t\t6. View Order History" << endl;
            cout << "\t\t\t\t7. Add Notification" << endl;
            cout << "\t\t\t\t8. Remove Notification" << endl;
            cout << "\t\t\t\t9. Display from File" << endl;
            cout << "\t\t\t\t10. View Users from File" << endl;
            cout << "\t\t\t\t11. View Menu Items from File" << endl;
            cout << "\t\t\t\t12. View Ratings from File" << endl;
            cout << "\t\t\t\t13. View Payments from File" << endl;
            cout << "\t\t\t\t14. Calculate Monthly Earnings" << endl;
            cout << "\t\t\t\t15. Logout" << endl;
            cout << "\t\t\t\tEnter your choice (1-15): ";
            cin >> choice;

            switch (choice) {
            case 1:
                admin.view_menu();
                break;
            case 2:
                admin.add_menu_items();
                break;
            case 3:
                admin.remove_menu_item();
                break;
            case 4:
                admin.manage_inventory();
                break;
            case 5:
                admin.manage_discount();
                break;
            case 6:
                admin.view_order_history();
                break;
            case 7:
                admin.add_notification();
                break;
            case 8:
                admin.remove_notification();
                break;
            case 9:
                //admin.display_from_file();
                break;
            case 10:
                admin.view_users_from_file();
                break;
            case 11:
                admin.view_menu_items_from_file();
                break;
            case 12:
                admin.view_ratings_from_file();
                break;
            case 13:
                admin.view_payments_from_file();
                break;
            case 14:
                admin.calculate_monthly_earnings();
                break;
            case 15:
                admin.logout();
                break;
            default:
                cout << "\t\t\t\tInvalid choice. Please enter a number between 1 and 15." << endl;
            }

        } while (choice != 15);
    }
    else if (c == 'b')
    {
        Cafe_staff b;
        int choice;
        do {
            cout << "\t\t\t\tCafe Staff Menu:" << endl;
            cout << "\t\t\t\t1. View Menu" << endl;
            cout << "\t\t\t\t2. Process Order" << endl;
            cout << "\t\t\t\t3. Add to Menu" << endl;
            cout << "\t\t\t\t4. Remove from Menu" << endl;
            cout << "\t\t\t\t5. Logout" << endl;
            cout << "\t\t\t\tEnter your choice (1-5): ";
            cin >> choice;

            switch (choice) {
            case 1:
                b.view_menu();
                break;
            case 2:
                b.process_order();
                break;
            case 3:
                b.add_menu_items();
                break;
            case 4:
                b.remove_menu_item();
                break;
            case 5:
                b.logout();
                break;
            default:
                cout << "\t\t\t\tInvalid choice. Please enter a number between 1 and 5." << endl;
            }

        } while (choice != 5);
    }
    else if (c == 'c')
    {
        Customer c;
        int choice;
        do {
            cout << "\t\t\t\tCustomer Menu:" << endl;
            cout << "\t\t\t\t1. View Menu" << endl;
            cout << "\t\t\t\t2. Place Order" << endl;
            cout << "\t\t\t\t3. View Order History" << endl;
            cout << "\t\t\t\t4. Rate Items" << endl;
            cout << "\t\t\t\t5. Logout" << endl;
            cout << "\t\t\t\tEnter your choice (1-5): ";
            cin >> choice;

            switch (choice) {
            case 1:
                c.view_menu();
                break;
            case 2:
                c.place_order();
                break;
            case 3:
                c.view_order_history();
                break;
            case 4:
                c.rate_items();
                break;
            case 5:
                c.logout();
                break;
            default:
                cout << "\t\t\t\tInvalid choice. Please enter a number between 1 and 5." << endl;
            }

        } while (choice != 5);
    }
    return 0;
}