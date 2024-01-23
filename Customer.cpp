#include "Customer.h"
#include<iostream>
#include<string>
using namespace std;

void Customer::view_menu()
{
    int option = 0;

    do
    {
        cout << "\t\t\t\tAre you a " << endl;
        cout << "\t\t\t\t[1] Faculty member." << endl;
        cout << "\t\t\t\t[2] Non-faculty member." << endl;
        cout << "\t\t\t\t[3] Student." << endl;
        cout << "\t\t\t\t[0] Exit." << endl;
        cout << "\t\t\t\tEnter the option (1,2, or 3): ";
        cin >> option;

        if (option == 1)
        {
            facultymenu faculty_member;
            faculty_member.viewMenu();
            cout << endl;
        }

        else if (option == 2)
        {
            nonfacmenu nonFaculty_member;
            nonFaculty_member.viewMenu();
            cout << endl;
        }

        else if (option == 3)
        {
            studentmenu student;
            student.viewMenu();
            cout << endl;
        }

        else
        {
            cout << "\t\t\t\tEnter the option from the menu." << endl;
        }
    } while (option != 0);

    
}

void Customer::place_order()
{
    Menutype menu;

    int menusize = menu.getsnacksize() + menu.getbevsize() + menu.getdesssize() + menu.getmainsize();

    menuattributes* menu_array = new menuattributes[menusize];

    int category;
    int id;
    int customer_id;
    int price = 0;
    string items_ordered;
    string order_status;



    cout << "\t\t\t\tEnter your customer id to place an order: ";
    cin >> customer_id;


    cout << "\t\t\t\tEnter the category of the item (1: Snacks, 2: Beverages, 3: Dessert, 4: Main): ";
    cin >> category;


    // Input validation for category
    if (category < 1 || category > 4)
    {
        cout << "\t\t\t\tInvalid category. Please enter a number between 1 and 4." << endl;
        delete[] menu_array;
        return;
    }


    // Populate menu_array based on the selected category
    switch (category) {
    case 1:
        menu_array = menu.getSnacks();
        cout << endl;
        break;
    case 2:
        menu_array = menu.getBevs();
        cout << endl;
        break;
    case 3:
        menu_array = menu.getDess();
        cout << endl;
        break;
    case 4:
        menu_array = menu.getMain();
        cout << endl;
        break;
    default:
        cout << "\t\t\t\tInvalid category. Please enter a number between 1 and 4." << endl;
        delete[] menu_array;
        return;
    }

    cout << "\t\t\t\tEnter the menu item ID# you want to order: ";
    cin >> id;

    if (id < 1 || id > menusize)
    {
        cout << "\t\t\t\tInvalid menu option. Please enter a valid option." << endl;
        delete[] menu_array;
        return;
    }


    for (int i = 0; i < menusize; i++)
    {
        if (id == menu_array[i].getitemid())
        {
            price = menu_array[i].getitemprice();
            items_ordered = menu_array[i].getitemname();
            order_status = "Received";
            cout << endl;
            break;
        }

        else
        {
            cout << "\t\t\t\tThe food item is not available." << endl;
            cout << endl;
        }

    }

    Order order(id, customer_id, items_ordered, price, order_status);

    order.saveOrderToFile();

    cout << endl;

    int menu_add_or_remove;
    cout << "\t\t\t\tWould you like to " << endl;
    cout << "\t\t\t\t[1] Add more items to your order." << endl;
    cout << "\t\t\t\t[2] Remove items from your order." << endl;
    cout << "\t\t\t\t[3] Calculate total." << endl;
    cout << "\t\t\t\t[4] Confirm order." << endl;
    cout << "\t\t\t\t[5] Cancel order." << endl;
    cout << "\t\t\t\t[6] Display items ordered." << endl;
    cout << "\t\t\t\tChoice: ";
    cin >> menu_add_or_remove;

    if (menu_add_or_remove == 1)
    {
        cout << "\t\t\t\tEnter the menu item ID# you want to order: ";
        cin >> id;
        for (int i = 0; i < menusize; i++)
        {
            if (id == menu_array[i].getitemid())
            {
                price = menu_array[i].getitemprice();
                items_ordered = menu_array[i].getitemname();
                order_status = "Received";
                cout << endl;
                break;
            }

            else
            {
                cout << "\t\t\t\tThe food item is not available." << endl;
                cout << endl;
                break;
            }

        }

        order.add_items(items_ordered, price);
    }

    else if (menu_add_or_remove == 2)
    {
        cout << "\t\t\t\tEnter the menu item ID# you want to remove from your order: ";
        cin >> id;
        for (int i = 0; i < menusize; i++)
        {
            if (id == menu_array[i].getitemid())
            {
                price = menu_array[i].getitemprice();
                items_ordered = menu_array[i].getitemname();
                order_status = "Cancelled";
                cout << endl;
                break;
            }

            else
            {
                cout << "\t\t\t\tThe food item is not available." << endl;
                cout << endl;
                break;
            }

        }

        order.remove_items(items_ordered, price);
    }

    else if (menu_add_or_remove == 3)
    {
        cout << "\t\t\t\tTotal: " << order.calculate_total() << endl;
        cout << endl;
    }

    else if (menu_add_or_remove == 4)
    {
        cout << "\t\t\t\tOrder: " << order.confirm_order() << endl;

        Payment payment(customer_id, id, price, "pending");

        payment.process_payment();

        cout << endl;

        payment.save_payment_details();

        cout << endl;
       
    }

    else if (menu_add_or_remove == 5)
    {
        order.cancel_order();
        cout << endl;
    }

    else if (menu_add_or_remove == 6)
    {
        cout << "\t\t\t\tItems Ordered: " << order.getItemsOrdered() << endl;
        cout << endl;
    }
    else
    {
        cout << "\t\t\t\tInvalid option entered." << endl;
        cout << endl;
    }


    delete[] menu_array;
}

void Customer::booktable()
{
    table_reservation reserve_table;
    reserve_table.displayAvailableTables();

    int table_no;

    cout << "\t\t\t\tEnter table number you would like to book (1-16): ";
    cin >> table_no;

    reserve_table.bookTable(table_no);

    cout << endl;

    reserve_table.displayTableStatus();

    cout << endl;
}

void Customer::view_order_history()
{
    filemanager orderfile;
    orderfile.displayorder_fromfile("orders.txt");
    cout << endl;
}

void Customer::rate_items()
{
    int menuItemID;
    cout << "\t\t\t\tEnter the ID of the menu item you want to rate: ";
    cin >> menuItemID;

    Rating customerRating;
    filemanager manager;

    customerRating.Rate(menuItemID, manager);

}

void Customer::logout()
{
    cout << "\t\t\t\tAll the data has been saved. Thank you for using Fast cafe." << endl;
}