#include "nonfacmenu.h"

nonfacmenu::nonfacmenu() :Menutype() {
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
void nonfacmenu::viewMenu() {
    cout << "\t\t\t\t______________NON FACULTY MENU__________________" << endl;
    Menutype::viewMenu();
}
nonfacmenu::~nonfacmenu() {
    delete[] snacks;
    delete[] bev;
    delete[] dessert;
    delete[] main;
}
void nonfacmenu::savenonfacmenutofile(const string& menuItemData) {
    filemanager fileManager; // Create an instance of FileManager

    // Save menu items to file using FileManager's function
    fileManager.savemenuitemtofile(menuItemData);
}