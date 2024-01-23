#include "menutype.h"
#include <iostream>

Menutype::Menutype()
{
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



void Menutype::displaySnackMenu()
{
    cout << "\t\t\t\t__________SNACK MENU______________" << std::endl;
    for (int i = 0; i < snsize; i++)
    {
        displaymenuattributes(snacks[i]);
    }

    filemanager snackfile;
    snackfile.displaymenuitem_fromfile("snack_menu_items.txt");
}

void Menutype::displayBeveragesMenu()
{
    cout << "\t\t\t\t__________BEVERAGES MENU______________" << std::endl;
    for (int i = 0; i < bsize; i++)
    {
        displaymenuattributes(bev[i]);
    }

    filemanager bevfile;
    bevfile.displaymenuitem_fromfile("bev_items.txt");
}

void Menutype::displayDessertMenu() {
    cout << "\t\t\t\t__________DESSERT MENU______________" << std::endl;
    for (int i = 0; i < dsize; i++)
    {
        displaymenuattributes(dessert[i]);
    }

    filemanager desfile;
    desfile.displaymenuitem_fromfile("dess_items.txt");
}

void Menutype::displayMainMenu()
{
    cout << "\t\t\t\t__________MAIN MENU______________" << std::endl;
    for (int i = 0; i < msize; i++)
    {
        displaymenuattributes(main[i]);
    }

    filemanager mainfile;
    mainfile.displaymenuitem_fromfile("main_items.txt");
}

void Menutype::viewMenu()
{
    cout << "\t\t\t\t__________ALL MENUS______________" << std::endl;
    displaySnackMenu();
    displayBeveragesMenu();
    displayDessertMenu();
    displayMainMenu();
    
}

//getters for arrays
menuattributes* Menutype::getSnacks() const
{
    return snacks;
}

menuattributes* Menutype::getBevs() const
{
    return bev;
}

menuattributes* Menutype::getDess() const
{
    return dessert;
}

menuattributes* Menutype::getMain() const
{
    return main;
}


//setters for arrays
void Menutype::setsnack(menuattributes* newSnacks, int newSize)
{
    delete[] snacks; // Clear the existing array
    snacks = newSnacks;
    snsize = newSize;

}

void Menutype::setbev(menuattributes* newSnacks, int newSize)
{
    bev = newSnacks;
    bsize = newSize;
}

void Menutype::setdess(menuattributes* newSnacks, int newSize)
{
    dessert = newSnacks;
    dsize = newSize;
}

void Menutype::setmain(menuattributes* newSnacks, int newSize)
{
    main = newSnacks;
    msize = newSize;
}


//setters for sizes
void Menutype::setsnacksize(int s)
{
    snsize = s;
}

void Menutype::setbevsize(int b)
{
    bsize = b;
}

void Menutype::setdesssize(int d)
{
    dsize = d;
}

void Menutype::setmainsize(int m)
{
    msize = m;
}

//getters for sizes
int Menutype::getsnacksize()const
{
    return snsize;
}

int Menutype::getbevsize() const
{
    return bsize;
}

int Menutype::getdesssize() const
{
    return dsize;
}

int Menutype::getmainsize() const
{
    return msize;
}


Menutype::~Menutype() {
    delete[] snacks;
    delete[] bev;
    delete[] dessert;
    delete[] main;
}

