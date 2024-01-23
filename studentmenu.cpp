#include "studentmenu.h"
#include "facultymenu.h"
studentmenu::studentmenu() :Menutype() {
    snsize = 0;
    bsize = 0;
    dsize = 0;
    msize = 0;

    // Initializing arrays for each menu type: snacks, beverages, dessert, main
    snacks = new menuattributes[snsize];
    bev = new menuattributes[bsize];
    dessert = new menuattributes[dsize];
    main = new menuattributes[msize];


}
//ovveriding viewmnwu
void studentmenu::viewMenu() {
    cout << "\t\t\t\t______________STUDENT MENU__________________" << endl;
    Menutype::viewMenu();
}
studentmenu::~studentmenu() {
    delete[] snacks;
    delete[] bev;
    delete[] dessert;
    delete[] main;
}
void studentmenu::savestudentmenutofile(const string& menuItemData) {
    filemanager fileManager; // Create an instance of FileManager

    // Save menu items to file using FileManager's function
    fileManager.savemenuitemtofile(menuItemData);
}