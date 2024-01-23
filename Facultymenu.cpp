#include "facultymenu.h"
#include"filemanager.h"
facultymenu::facultymenu() :Menutype() {
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
void facultymenu::viewMenu() {
    cout << "\t\t\t\t______________FACULTY MENU__________________" << endl;
    Menutype::viewMenu();
}
facultymenu::~facultymenu() {
    delete[] snacks;
    delete[] bev;
    delete[] dessert;
    delete[] main;
}
void facultymenu::savefacmenutofile(const string& menuItemData) {
    filemanager fileManager; // Create an instance of FileManager

    // Save menu items to file using FileManager's function
    fileManager.savemenuitemtofile(menuItemData);
}
