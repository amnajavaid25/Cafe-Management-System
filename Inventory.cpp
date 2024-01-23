#include "Inventory.h"
#include"menutype.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include <set>
using namespace std;

// Constructor
Inventory::Inventory() {}


// Functions to manage menu items
void  Inventory::saveMenuItemsToFile(const string& fileName, const string& itemData) {
    std::ofstream outputFile(fileName, ios::app); // Open file in append mode

    if (outputFile.is_open()) {
        outputFile << itemData << "\n"; // Write the item data to the file
        outputFile.close();
        std::cout << "\t\t\t\tMenu items saved to file: " << fileName << std::endl;
    }
    else {
        std::cerr << "\t\t\t\tUnable to open file: " << fileName << std::endl;
    }
}

void Inventory::addsnackMenuItem()
{
    int newSize = menu.getsnacksize() + 1;
    menuattributes* temp = new menuattributes[newSize];

    //  item details from user input
    string itemname, desc;
    int p, id, qtty;
    cout << "\t\t\t\tFor snack item" << endl;
    cout << "\t\t\t\tEnter the id of item,it should be between 1-100: ";
    cin >> id;
    cout << "\t\t\t\tEnter name of item: ";
    cin >> itemname;
    cin.ignore();
    cout << "\t\t\t\tEnter description of item: ";
    getline(cin, desc);
    cout << "\t\t\t\tEnter price of item: ";
    cin >> p;
    cout << "\t\t\t\tEnter the quantity of item: ";
    cin >> qtty;

    // Creating a new menuattributes object with collected details
  
        menuattributes newItem(itemname, desc, p, qtty, id);
    
   
    // Copying existing items to temp array
    for (int i = 0; i < newSize - 1; ++i)
    {
        temp[i] = menu.getSnacks()[i];
    }

    // Adding the new item to the end of the temporary array
    temp[newSize - 1] = newItem;

    // Updating the menu's snack array with the temporary array
    menu.setsnack(temp, newSize);
    menu.setsnacksize(newSize);

    cout << "\t\t\t\tItem is successfully added to Snacks Menu Section" << endl;
    string snackItemData = "ID :"+to_string(id) + ","+"Item Name:" + itemname + ","+"Description:" + desc + ","+"Price:" + to_string(p) + "," + "Quantity" + to_string(qtty);

    // Call the saveMenuItemsToFile function to save this data to a file
    saveMenuItemsToFile("snack_menu_items.txt", snackItemData);
    cout << "\t\t\t\tItem added to snack section." << endl;
}

//add beverages menu item
void Inventory::addbevMenuItem()
{
    int newSize = menu.getbevsize() + 1;
    menuattributes* temp = new menuattributes[newSize];

    // Collecting new item details from user input
    string itemname, desc;
    int p, id, qtty;
    cout << "\t\t\t\tFor beverage item" << endl;
    cout << "\t\t\t\tEnter the id of item,it should be a number between 101-200: ";
    cin >> id;
    cout << "\t\t\t\tEnter name of item: ";
    cin >> itemname;
    cin.ignore();
    cout << "\t\t\t\tEnter description of item: ";
    getline(cin, desc);
    cout << "\t\t\t\tEnter price of item: ";
    cin >> p;
    cout << "\t\t\t\tEnter the quantity of item: ";
    cin >> qtty;

    // Creating a new menuattributes object with collected details
    menuattributes newItem(itemname, desc, p, qtty, id);

    // Copying existing items to temp array
    for (int i = 0; i < newSize - 1; ++i) 
    {
        temp[i] = menu.getBevs()[i];
    }

    // Adding the new item to the end of the temporary array
    temp[newSize - 1] = newItem;

    // Updating the menu's snack array with the temporary array
    menu.setbev(temp, newSize);
    menu.setbevsize(newSize);
    cout << "\t\t\t\tItem is successfully added to Beverages Menu Section" << endl;
    string bevItemData = "ID :" + to_string(id) + "," + "Item Name:" + itemname + "," + "Description:" + desc + "," + "Price:" + to_string(p) + "," + "Quantity" + to_string(qtty);

    saveMenuItemsToFile("bev_items.txt", bevItemData);
    cout << "\t\t\t\tItem added to beverages section" << endl;
}


void Inventory::adddessertMenuItem()
{
    int newSize = menu.getdesssize() + 1;
    menuattributes* temp = new menuattributes[newSize];

    // Collecting new item details from user input
    string itemname, desc;
    int p, id, qtty;
    cout << "\t\t\t\tFor dessert item" << endl;
    cout << "\t\t\t\tEnter the id of item,it should be a number between 201-300: ";
    cin >> id;
    cout << "\t\t\t\tEnter name of item: ";
    cin >> itemname;
    cin.ignore();
    cout << "\t\t\t\tEnter description of item: ";
    getline(cin, desc);
    cout << "\t\t\t\tEnter price of item: ";
    cin >> p;
    cout << "\t\t\t\tEnter the quantity of item: ";
    cin >> qtty;

    // Creating a new menuattributes object with collected details
    menuattributes newItem(itemname, desc, p, qtty, id);

    // Copying existing items to temp array
    for (int i = 0; i < newSize - 1; ++i) {
        temp[i] = menu.getDess()[i];
    }

    // Adding the new item to the end of the temporary array
    temp[newSize - 1] = newItem;

    // Updating the menu's snack array with the temporary array
    menu.setdess(temp, newSize);
    menu.setdesssize(newSize);

    cout << "\t\t\t\tItem is successfully added to Dessert Menu Section" << endl;
    string dessItemData = "ID :" + to_string(id) + "," + "Item Name:" + itemname + "," + "Description:" + desc + "," + "Price:" + to_string(p) + "," + "Quantity" + to_string(qtty);

    saveMenuItemsToFile("dess_items.txt", dessItemData);
}


void Inventory::addmainMenuItem()
{
    int newSize = menu.getmainsize() + 1;
    menuattributes* temp = new menuattributes[newSize];

    // Collecting new item details from user input
    string itemname, desc;
    int p, id, qtty;
    cout << "\t\t\t\tFor main course item" << endl;
    cout << "\t\t\t\tEnter the id of item,it should be a number between 301-400: ";
    cin >> id;
    cout << "\t\t\t\tEnter name of item: ";
    getline(cin, itemname);
    cin.ignore();
    cout << "\t\t\t\tEnter description of item: ";
    getline(cin, desc);
    cin.ignore();
    cout << "\t\t\t\tEnter price of item: ";
    cin >> p;
    cout << "\t\t\t\tEnter the quantity of item: ";
    cin >> qtty;

    // Creating a new menuattributes object with collected details
    menuattributes newItem(itemname, desc, p, qtty, id);

    // Copying existing items to temp array
    for (int i = 0; i < newSize - 1; ++i) {
        temp[i] = menu.getMain()[i];
    }

    // Adding the new item to the end of the temporary array
    temp[newSize - 1] = newItem;

    // Updating the menu's snack array with the temporary array
    menu.setmain(temp, newSize);
    menu.setmainsize(newSize);
    cout << "\t\t\t\tItem is successfully added to main menu section" << endl;
    string mainItemData = "ID :" + to_string(id) + "," + "Item Name:" + itemname + "," + "Description:" + desc + "," + "Price:" + to_string(p) + "," + "Quantity" + to_string(qtty);

    saveMenuItemsToFile("main_items.txt", mainItemData);
}


void Inventory::addMenuItem()
{
    int choice;

    cout << "\t\t\t\t1. Add item to Snack Menu Section" << endl;
    cout << "\t\t\t\t2. Add item to Beverages Menu Section" << endl;
    cout << "\t\t\t\t3. Add item to Dessert Menu Section" << endl;
    cout << "\t\t\t\t4. Add item to Main Menu Section" << endl;
    cout << "\t\t\t\tEnter your choice:" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        addsnackMenuItem();
        break;
    case 2:
        addbevMenuItem();
        break;
    case 3:
        adddessertMenuItem();
        break;
    case 4:
        addmainMenuItem();
        break;
    default:
        cout << "\t\t\t\tInvalid choice!" << endl;
        break;
    }
}


void Inventory::removesnackItem()
{
    int id;
    cout << "\t\t\t\tEnter the ID of the item you want to remove from Snack Menu Section: ";
    cin >> id;

    int currentSize = menu.getsnacksize();
    // Allocating memory for the same size as the current Snack Menu
    menuattributes* temp = new menuattributes[currentSize];

    int tempIndex = 0;

    for (int i = 0; i < currentSize; ++i) {
        if (menu.getSnacks()[i].getitemid() != id) {
            temp[tempIndex] = menu.getSnacks()[i];
            tempIndex++;
        }
    }

    // Updatinng the Snack Menu only if there were items removed
    if (tempIndex != currentSize) {
        menu.setsnack(temp, tempIndex);
        menu.setsnacksize(tempIndex);
        cout << "\t\t\t\tItem is successfully removed from Snacks Menu Section " << endl;
    }
    else {
        cout << "\t\t\t\tItem with ID " << id << " not found in Snacks Menu Section " << endl;
    }


    delete[] temp;
}


void Inventory::removemainItem()
{
    int id;
    cout << "\t\t\t\tEnter the ID of the item you want to remove from Main Menu: ";
    cin >> id;

    int currentSize = menu.getmainsize();
    // Allocating memory for the same size as the current Snack Menu
    menuattributes* temp = new menuattributes[currentSize];

    int tempIndex = 0;

    for (int i = 0; i < currentSize; ++i) {
        if (menu.getMain()[i].getitemid() != id) {
            temp[tempIndex] = menu.getMain()[i];
            tempIndex++;
        }
    }

    // Updatinng the Snack Menu only if there were items removed
    if (tempIndex != currentSize) {
        menu.setmain(temp, tempIndex);
        menu.setmainsize(tempIndex);
        cout << "\t\t\t\tItem is successfully removed from Main Menu Section" << endl;
    }
    else {
        cout << "\t\t\t\tItem with ID " << id << " not found in Main Menu Section" << endl;
    }


    delete[] temp;
}


void Inventory::removedessertItem()
{
    int id;
    cout << "\t\t\t\tEnter the ID of the item you want to remove from Dessert Menu Section: ";
    cin >> id;

    int currentSize = menu.getdesssize();
    // Allocating memory for the same size as the current Snack Menu
    menuattributes* temp = new menuattributes[currentSize];

    int tempIndex = 0;

    for (int i = 0; i < currentSize; ++i) {
        if (menu.getDess()[i].getitemid() != id) {
            temp[tempIndex] = menu.getDess()[i];
            tempIndex++;
        }
    }

    // Updatinng the Snack Menu only if there were items removed
    if (tempIndex != currentSize) {
        menu.setdess(temp, tempIndex);
        menu.setdesssize(tempIndex);
        cout << "\t\t\t\tItem is successfully removed from Dessert Menu Section" << endl;
    }
    else {
        cout << "\t\t\t\tItem with ID " << id << " not found in Dessert Menu Section" << endl;
    }


    delete[] temp;
}

void Inventory::removebevItem()
{
    int id;
    cout << "\t\t\t\tEnter the ID of the item you want to remove from Beverages Menu Section: ";
    cin >> id;

    int currentSize = menu.getbevsize();
    // Allocating memory for the same size as the current Snack Menu
    menuattributes* temp = new menuattributes[currentSize];

    int tempIndex = 0;

    for (int i = 0; i < currentSize; ++i) {
        if (menu.getBevs()[i].getitemid() != id) {
            temp[tempIndex] = menu.getBevs()[i];
            tempIndex++;
        }
    }

    // Updatinng the Snack Menu only if there were items removed
    if (tempIndex != currentSize) {
        menu.setbev(temp, tempIndex);
        menu.setbevsize(tempIndex);
        cout << "\t\t\t\tItem is successfully removed from Beverages Menu Section" << endl;

    }
    else {
        cout << "\t\t\t\tItem with ID " << id << " not found in Beverages Menu Section" << endl;
    }

    delete[] temp;
}


void Inventory::removeMenuItem()
{
    int choice;

    cout << "\t\t\t\t1. Remove item from Snack Menu Section" << endl;
    cout << "\t\t\t\t2. Remove item from Beverages Menu Section" << endl;
    cout << "\t\t\t\t3. Remove item from Dessert Menu Section" << endl;
    cout << "\t\t\t\t4. Remove item from Main Menu Section" << endl;
    cout << "\t\t\t\tEnter your choice:" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        removesnackItem();
        break;
    case 2:
        removebevItem();
        break;
    case 3:
        removedessertItem();
        break;
    case 4:
        removemainItem();
        break;
    default:
        cout << "\t\t\t\tInvalid choice!" << endl;
        break;
    }
}


void Inventory::changeprice()
{
    int choice;

    cout << "\t\t\t\t1. Snacks" << endl;
    cout << "\t\t\t\t2. Beverages" << endl;
    cout << "\t\t\t\t3. Desserts" << endl;
    cout << "\t\t\t\t4. Main" << endl;
    cout << "\t\t\t\tEnter the section of item you want to modify the price of:" << endl;
    cin >> choice;

    int id;
    cout << "\t\t\t\tEnter the ID of the item you want to modify: ";
    cin >> id;

    int newprice;
    cout << "\t\t\t\tEnter the new price for the item: ";
    cin >> newprice;

    switch (choice) {
    case 1: {
        menuattributes* snacks = menu.getSnacks();
        int snackSize = menu.getsnacksize();

        for (int i = 0; i < snackSize; ++i) {
            if (snacks[i].getitemid() == id) {
                snacks[i].setprice(newprice);
                cout << "\t\t\t\tPrice for item with ID " << id << " in Snacks menu updated to " << newprice << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Snacks menu" << endl;
        break;
    }
    case 2: {
        menuattributes* beverages = menu.getBevs();
        int bevSize = menu.getbevsize();

        for (int i = 0; i < bevSize; ++i) {
            if (beverages[i].getitemid() == id) {
                beverages[i].setprice(newprice);
                cout << "\t\t\t\tPrice for item with ID " << id << " in Beverages menu updated to " << newprice << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Beverages menu" << endl;
        break;
    }
    case 3: {
        menuattributes* desserts = menu.getDess();
        int dessertSize = menu.getdesssize();

        for (int i = 0; i < dessertSize; ++i) {
            if (desserts[i].getitemid() == id) {
                desserts[i].setprice(newprice);
                cout << "\t\t\t\tPrice for item with ID " << id << " in Desserts menu updated to " << newprice << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Desserts menu" << endl;
        break;
    }
    case 4: {
        menuattributes* mainMenu = menu.getMain();
        int mainSize = menu.getmainsize();

        for (int i = 0; i < mainSize; ++i) {
            if (mainMenu[i].getitemid() == id) {
                mainMenu[i].setprice(newprice);
                cout << "\t\t\t\tPrice for item with ID " << id << " in Main menu updated to " << newprice << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Main menu" << endl;
        break;
    }
    default:
        cout << "\t\t\t\tInvalid section choice!" << endl;
        break;
    }
}

void Inventory::updatestocklevels()
{
    int sectionChoice;
    cout << "\t\t\t\t1. Snacks" << endl;
    cout << "\t\t\t\t2. Beverages" << endl;
    cout << "\t\t\t\t3. Desserts" << endl;
    cout << "\t\t\t\t4. Main" << endl;
    cout << "\t\t\t\tEnter the section of the item you want to modify the stock level of: ";
    cin >> sectionChoice;

    int id;
    cout << "\t\t\t\tEnter the ID of the item you want to modify the stock levels of: ";
    cin >> id;

    int newStock;
    cout << "\t\t\t\tEnter the new stock level for the item: ";
    cin >> newStock;

    switch (sectionChoice) {
    case 1: {
        menuattributes* snacks = menu.getSnacks();
        int snackSize = menu.getsnacksize();

        for (int i = 0; i < snackSize; ++i) {
            if (snacks[i].getitemid() == id) {
                snacks[i].setqtty(newStock);
                cout << "\t\t\t\tStock level for item with ID " << id << " in Snacks menu updated to " << newStock << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Snacks menu" << endl;
        break;
    }
    case 2: {
        menuattributes* beverages = menu.getBevs();
        int bevSize = menu.getbevsize();

        for (int i = 0; i < bevSize; ++i) {
            if (beverages[i].getitemid() == id) {
                beverages[i].setqtty(newStock);
                cout << "\t\t\t\tStock level for item with ID " << id << " in Beverages menu updated to " << newStock << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Beverages menu" << endl;
        break;
    }
    case 3: {
        menuattributes* desserts = menu.getDess();
        int dessertSize = menu.getdesssize();

        for (int i = 0; i < dessertSize; ++i) {
            if (desserts[i].getitemid() == id) {
                desserts[i].setqtty(newStock);
                cout << "\t\t\t\tStock level for item with ID " << id << " in Desserts menu updated to " << newStock << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Desserts menu" << endl;
        break;
    }
    case 4: {
        menuattributes* mainMenu = menu.getMain();
        int mainSize = menu.getmainsize();

        for (int i = 0; i < mainSize; ++i) {
            if (mainMenu[i].getitemid() == id) {
                mainMenu[i].setqtty(newStock);
                cout << "\t\t\t\tStock level for item with ID " << id << " in Main menu updated to " << newStock << endl;
                return;
            }
        }
        cout << "\t\t\t\tItem with ID " << id << " not found in Main menu" << endl;
        break;
    }
    default:
        cout << "\t\t\t\tInvalid section choice!" << endl;
        break;
    }
}



void Inventory::removeItemFromFile(const string& fileName, int itemId) {
    ifstream inFile(fileName);
    ofstream outFile("temp_" + fileName);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "\t\t\t\tError opening files." << endl;
        return;
    }

    string line;
    bool itemRemoved = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string idString;

        if (getline(iss, idString, ',')) {
            idString.erase(0, idString.find_first_not_of(" \t\r\n"));
            idString.erase(idString.find_last_not_of(" \t\r\n") + 1);

            if (idString.find("ID") != string::npos) {
                size_t pos = idString.find(':');
                if (pos != string::npos && pos + 1 < idString.length()) {
                    string idSubstr = idString.substr(pos + 1);

                    int idInFile = stoi(idSubstr);

                    if (idInFile != itemId) {
                        outFile << line << endl;
                    }
                    else {
                        itemRemoved = true;
                    }
                }
            }
        }
    }

    inFile.close();
    outFile.close();

    if (itemRemoved) {
        remove(fileName.c_str());
        int result = rename(("temp_" + fileName).c_str(), fileName.c_str());
        if (result != 0) {
            cerr << "\t\t\t\tError renaming file." << endl;
        }
        else {
            cout << "\t\t\t\tItem with ID " << itemId << " removed from " << fileName << endl;
        }
    }
    else {
        remove(("temp_" + fileName).c_str());
        cout << "\t\t\t\tItem with ID " << itemId << " not found in " << fileName << endl;
    }
}

void Inventory::updateStockLevelsinfile(int sectionChoice, int itemId, int newStock) {
    using namespace std;

    string filename;

    switch (sectionChoice) {
    case 1:
        filename = "snack_menu_items.txt";
        break;
    case 2:
        filename = "bev_items.txt";
        break;
    case 3:
        filename = "dess_items.txt";
        break;
    case 4:
        filename = "main_items.txt";
        break;
    case 5:
        filename = "studentmenu_items.txt";
        break;
    case 6:
        filename = "facultymenu_items.txt";
        break;
    case 7:
        filename = "nonfacultymenu_items.txt";
        break;
    default:
        cout << "\t\t\t\tInvalid section choice!" << endl;
        return;
    }

    ifstream inFile(filename);
    ofstream outFile("temp_" + filename);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "\t\t\t\tError opening files." << endl;
        return;
    }

    string line;
    bool itemFound = false;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string idString;

        // Read the ID string until the delimiter (assuming ',' here)
        if (getline(iss, idString, ',')) {
            idString.erase(0, idString.find_first_not_of(" \t\r\n"));
            idString.erase(idString.find_last_not_of(" \t\r\n") + 1);

            // Check if the ID string starts with "ID"
            if (idString.find("ID") != string::npos) {
                size_t pos = idString.find(':');
                if (pos != string::npos && pos + 1 < idString.length()) {
                    string idSubstr = idString.substr(pos + 1);

                    int idInFile = 0;
                    bool isConvertible = true;
                    size_t conversionPos;
                    idInFile = stoi(idSubstr, &conversionPos);

                    if (conversionPos != idSubstr.size()) {
                        isConvertible = false;
                    }

                    if (isConvertible && idInFile == itemId) {
                        // Update the quantity in the line
                        size_t pos = line.find_last_of(',');
                        line.replace(pos + 1, line.size() - pos, to_string(newStock));
                        itemFound = true;
                    }
                    else if (!isConvertible) {
                        cout << "\t\t\t\tError processing line: Invalid ID format - " << idSubstr << endl;
                    }
                }
            }
        }
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();

    if (itemFound) {
        remove(filename.c_str());
        int result = rename(("temp_" + filename).c_str(), filename.c_str());
        if (result != 0) {
            cout << "\t\t\t\tError renaming file." << endl;
        }
        else {
            cout << "\t\t\t\tStock level for item with ID " << itemId << " updated to " << newStock << " in " << filename << endl;
        }
    }
    else {
        remove(("temp_" + filename).c_str());
        cout << "\t\t\t\tItem with ID " << itemId << " not found in " << filename << endl;
    }
}

void Inventory::changeItemPriceinfile(int sectionChoice, int itemId, int newPrice) {
    string filename;

    switch (sectionChoice) {
    case 1:
        filename = "snack_menu_items.txt";
        break;
    case 2:
        filename = "bev_items.txt";
        break;
    case 3:
        filename = "dess_items.txt";
        break;
    case 4:
        filename = "main_items.txt";
        break;
    case 5:
        filename = "studentmenu_items.txt";
        break;
    case 6:
        filename = "facultymenu_items.txt";
        break;
    case 7:
        filename = "nonfacultymenu_items.txt";
        break;
    default:
        cout << "\t\t\t\tInvalid section choice!" << endl;
        return;
    }

    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "\t\t\t\tError opening input file: " << filename << endl;
        return;
    }

    ofstream outFile("temp_" + filename);
    if (!outFile.is_open()) {
        cout << "\t\t\t\tError opening output file: " << "temp_" + filename << endl;
        inFile.close();
        return;
    }

    string line;
    bool itemFound = false;

    while (getline(inFile, line)) {
        size_t pricePos = line.find("Price:");
        if (pricePos != string::npos) {
            string priceSubstring = line.substr(pricePos + 6); // Extract substring after "Price:"
            try {
                int price = stoi(priceSubstring);
                int idInFile = stoi(line.substr(4, line.find(','))); // Extract ID from the line

                if (idInFile == itemId) {
                    line.replace(pricePos + 6, priceSubstring.length(), to_string(newPrice));
                    itemFound = true;
                }
            }
            catch (const invalid_argument& e) {
                cout << "\t\t\t\tError converting ID or Price to integer." << endl;
            }
        }
        outFile << line << endl; // Write line to the new file
    }

    inFile.close();
    outFile.close();

    if (itemFound) {
        if (remove(filename.c_str()) != 0) {
            cout << "\t\t\t\tError removing original file: " << filename << endl;
        }
        if (rename(("temp_" + filename).c_str(), filename.c_str()) != 0) {
            cout << "\t\t\t\tError renaming file." << endl;
        }
        else {
            cout << "\t\t\t\tPrice for item with ID " << itemId << " in " << filename << " updated to " << newPrice << endl;
        }
    }
    else {
        remove(("temp_" + filename).c_str());
        cout << "\t\t\t\tItem with ID " << itemId << " not found in " << filename << endl;
    }
}

void Inventory::saveItemsToStudentMenuFile() {
    ofstream outFile("studentmenu_items.txt", ios::app);

    if (!outFile.is_open()) {
        cerr << "\t\t\t\tError opening studentmenu_items.txt" << endl;
        return;
    }

    set<string> existingItems;

    auto appendUniqueItems = [&](const string& fileName) {
        ifstream inFile(fileName);

        if (!inFile.is_open()) {
            cerr << "\t\t\t\tError opening " << fileName << endl;
            return;
        }

        string line;
        while (std::getline(inFile, line)) {
            if (existingItems.insert(line).second) {
                outFile << line << endl;
            }
        }
        inFile.close();
        };

    appendUniqueItems("snack_menu_items.txt");
    appendUniqueItems("bev_items.txt");
    // Append items from other files as needed
    appendUniqueItems("dess_items.txt");
    appendUniqueItems("main_items.txt");
    outFile.close();
    cout << "\t\t\t\tItems added to student menu" << std::endl;
}

void Inventory::saveItemsToFacultyMenuFile() {
    ofstream outFile("facultymenu_items.txt", std::ios::app);

    if (!outFile.is_open()) {
        cerr << "\t\t\t\tError opening facultymenu_items.txt" << std::endl;
        return;
    }

    set<string> existingItems;

    auto appendUniqueItems = [&](const string& fileName) {
        ifstream inFile(fileName);

        if (!inFile.is_open()) {
            cerr << "\t\t\t\tError opening " << fileName << std::endl;
            return;
        }

        string line;
        while (std::getline(inFile, line)) {
            if (existingItems.insert(line).second) {
                outFile << line << std::endl;
            }
        }
        inFile.close();
        };

    appendUniqueItems("snack_menu_items.txt");
    appendUniqueItems("bev_items.txt");
    // Append items from other files as needed
    appendUniqueItems("dess_items.txt");
    appendUniqueItems("main_items.txt");
    outFile.close();
    cout << "\t\t\t\tItems added to faculty menu" << endl;
}

void Inventory::saveItemsToNonFacMenuFile() {
    ofstream outFile("nonfacultymenu_items.txt", ios::app);

    if (!outFile.is_open()) {
        cerr << "\t\t\t\tError opening nonfacultymenu_items.txt" << endl;
        return;
    }

    set<string> existingItems;

    auto appendUniqueItems = [&](const string& fileName) {
        ifstream inFile(fileName);

        if (!inFile.is_open()) {
            cerr << "\t\t\t\tError opening " << fileName << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            if (existingItems.insert(line).second) {
                outFile << line << std::endl;
            }
        }
        inFile.close();
        };

    appendUniqueItems("snack_menu_items.txt");
    appendUniqueItems("bev_items.txt");
    // Append items from other files as needed
    appendUniqueItems("dess_items.txt");
    appendUniqueItems("main_items.txt");
    outFile.close();
    cout << "\t\t\t\tItems added to non fac menu" << std::endl;
}