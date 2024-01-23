#include "Cafe_staff.h"
#include"Menutype.h"
#include<string>
#include<iostream>
using namespace std;


void Cafe_staff::view_menu()
{
	int choice;

	cout << "\t\t\t\tWhich menu do you want to view ? " << endl;
	cout << "\t\t\t\t[1] Faculty menu." << endl;
	cout << "\t\t\t\t[2] Non-faculty menu." << endl;
	cout << "\t\t\t\t[3] Student menu." << endl;
	cout << "\t\t\t\t[4] All the menus." << endl;
	cout << "\t\t\t\tChoice: ";
	cin >> choice;

	if (choice == 1)
	{
		facultymenu Faculty;
		Faculty.viewMenu();
		cout << endl;
	}

	else if (choice == 2)
	{
		nonfacmenu NonFaculty;
		NonFaculty.viewMenu();
		cout << endl;
	}

	else if (choice == 3)
	{
		studentmenu Student;
		Student.viewMenu();
		cout << endl;
	}

	else if (choice == 4)
	{
		Menutype all_menus;
		all_menus.displayBeveragesMenu();
		cout << endl;
		all_menus.displayDessertMenu();
		cout << endl;
		all_menus.displayMainMenu();
		cout << endl;
		all_menus.displaySnackMenu();
		cout << endl;
	}

	else
	{
		cout << "\t\t\t\tEnter the choice from the menu." << endl;
	}
}

void Cafe_staff::process_order()
{
	Order order;

	order.confirm_order();
	cout << endl;
}


void Cafe_staff::add_menu_items()
{
	int option;

	cout << "\t\t\t\tIn which section would you like to add new items: " << endl;
	cout << "\t\t\t\t[1] Snacks." << endl;
	cout << "\t\t\t\t[2] Beverages." << endl;
	cout << "\t\t\t\t[3] Desserts." << endl;
	cout << "\t\t\t\t[4] Main course." << endl;
	cout << "\t\t\t\tSelect an option (1,2,or 3): ";
	cin >> option;

	if (option == 1)
	{
		inventory.addsnackMenuItem();
		cout << endl;
	}

	else if (option == 2)
	{
		inventory.addbevMenuItem();
		cout << endl;
	}

	else if (option == 3)
	{
		inventory.adddessertMenuItem();
		cout << endl;
	}

	else if (option == 4)
	{
		inventory.addmainMenuItem();
		cout << endl;
	}

	else
	{
		cout << "\t\t\t\tChoose an option from the menu." << endl;
	}
}


void Cafe_staff::remove_menu_item()
{
	int option;

	cout << "\t\t\t\tFrom which section would you like to remove an item: " << endl;
	cout << "\t\t\t\t[1] Snacks." << endl;
	cout << "\t\t\t\t[2] Beverages." << endl;
	cout << "\t\t\t\t[3] Desserts." << endl;
	cout << "\t\t\t\t[4] Main course." << endl;
	cout << "\t\t\t\tSelect an option (1,2,or 3): ";
	cin >> option;

	if (option == 1)
	{
		inventory.removesnackItem();
		cout << endl;
	}

	else if (option == 2)
	{
		inventory.removebevItem();
		cout << endl;
	}

	else if (option == 3)
	{
		inventory.removedessertItem();
		cout << endl;
	}

	else if (option == 4)
	{
		inventory.removemainItem();
		cout << endl;
	}

	else
	{
		cout << "\t\t\t\tChoose an option from the menu." << endl;
	}
}

void Cafe_staff::logout() 
{
	cout << "\t\t\t\tAll the data has been saved. Thank you for using Fast cafe." << endl;
}