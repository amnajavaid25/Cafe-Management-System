#include "Administrator.h"
#include<iostream>
using namespace std;

Administrator::Administrator() {}

void Administrator::view_menu()
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

void Administrator::add_menu_items()
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

void Administrator::remove_menu_item()
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

void Administrator::manage_inventory()
{
	int option;
	cout << "\t\t\t\tWould you like to " << endl;
	cout << "\t\t\t\t[1] Add menu item." << endl;
	cout << "\t\t\t\t[2] Remove menu item." << endl;
	cout << "\t\t\t\t[3] Change Price." << endl;
	cout << "\t\t\t\t[4] Update Stock." << endl;
	cout << "\t\t\t\tOption (choose 1, 2, or 3): ";
	cin >> option;

	if (option == 1)
	{
		inventory.addMenuItem();
		cout << endl;
	}

	else if (option == 2)
	{
		inventory.removeMenuItem();
		cout << endl;
	}

	else if (option == 3)
	{
		inventory.changeprice();
		cout << endl;
	}

	else if (option == 4)
	{
		inventory.updatestocklevels();
		cout << endl;
	}

	else
	{
		cout << "\t\t\t\tInvalid option." << endl;
	}

}

void Administrator::manage_discount()
{

}

void Administrator::view_order_history()
{
	filemanager orderfile;
	orderfile.displayorder_fromfile("orders.txt");
	cout << endl;
}

void Administrator::add_notification()
{
	string notification;
	cout << "\t\t\t\tEnter the notification you would like to send to the staff and customer: ";
	cin >> notification;
	cout << endl;
}

void Administrator::remove_notification()
{
	cout << "\t\t\t\tNotification removed." << endl;
	cout << endl;
}

void Administrator::view_users_from_file() 
{
	filemanager userfile;
	userfile.displayuser_fromfile("user_data.txt");
	cout << endl;
}

void Administrator::view_menu_items_from_file() 
{
	filemanager menufile;
	

	int choice = 0;
	cout << "\t\t\t\tEnter 1 for the student menu, 2 for the faculty menu, and 3 for the non-faculty menu: ";
	cin >> choice;
	cin.ignore();
	string fileName;

	switch (choice) 
	{
	case 1:
		fileName = "studentmenu_items.txt";
		menufile.displaymenuitem_fromfile("studentmenu_items.txt");
		break;
	case 2:
		fileName = "facultymenu_items.txt";
		menufile.displaymenuitem_fromfile("facultymenu_items.txt");
		break;
	case 3:
		fileName = "nonfacultymenu_items.txt";
		menufile.displaymenuitem_fromfile("nonfacultymenu_items.txt");
		break;
	default:
		cout << "Enter the right choice." << endl;
		return;
	}
	cout << endl;
}

void Administrator::view_ratings_from_file() 
{
	filemanager ratingfile;
	ratingfile.displayrating_fromfile("ratings.txt");
	cout << endl;

}

void Administrator::view_payments_from_file() 
{
	filemanager paymentfile;
	paymentfile.displaypayment_fromfile("payments.txt"); 
	cout << endl;
}

void Administrator::calculate_monthly_earnings() 
{
	//Payment payment;
	//ifstream infile("payments.txt");

	//if (!infile.is_open()) 
	//{
	//	cerr << "\t\t\t\tUnable to open payments.txt" << endl;
	//}

	//double totalAmount = 0.0;
	//string line;

	//cout << payment.amount;

	//while (getline(infile, line)) {
	//	istringstream iss(line);

	//	// Read payment_id, order_id, amount, payment_status
	//	if (iss >> payment.payment_id >> payment.order_id >> payment.amount >> payment.payment_status) {
	//		// Add only the amount to the total
	//		totalAmount += payment.amount;
	//	}
	//	else {
	//		cerr << "Error reading payment data from file" << endl;
	//		
	//	}
	//}

	//infile.close();
	//cout << endl;
}

void Administrator::logout() 
{
	cout << "\t\t\t\tAll the data has been saved. Thank you for using Fast cafe." << endl;
	cout << endl;
}
