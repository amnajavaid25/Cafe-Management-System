#pragma once
#include "menutype.h"
#include<iostream>
#include"filemanager.h"
class Inventory {
private:
    Menutype menu;

public:
    // Constructor
    Inventory();

    // Functions to manage menu items
    void addsnackMenuItem();
    void adddessertMenuItem();
    void addbevMenuItem();
    void addmainMenuItem();
    void addMenuItem();
    void removesnackItem();
    void removebevItem();
    void removedessertItem();
    void removemainItem();
    void removeMenuItem();
    void changeprice();
    void updatestocklevels();
    void saveMenuItemsToFile(const string& fileName, const string& itemData);
    void removeItemFromFile(const string& fileName, int itemId);
    //file handling for price update
     void updateStockLevelsinfile(int sectionChoice, int itemId, int newStock);
     void changeItemPriceinfile(int sectionChoice, int itemId, int newPrice);
     void saveItemsToStudentMenuFile();
     void saveItemsToFacultyMenuFile();
     void saveItemsToNonFacMenuFile();

};


