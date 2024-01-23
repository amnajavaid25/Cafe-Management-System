#pragma once
#include"menuattributes.h"
#include"filemanager.h"
class Menutype
{
protected:
    menuattributes* snacks;
    menuattributes* bev;
    menuattributes* dessert;
    menuattributes* main;
    int msize;
    int bsize;
    int dsize;
    int snsize;

public:
    // Default constructor
    Menutype();


    //getters for array sizes
    menuattributes* getSnacks() const;
    menuattributes* getMain() const;
    menuattributes* getDess() const;
    menuattributes* getBevs() const;

    int getsnacksize()const;
    int getbevsize()const;
    int getdesssize()const;
    int getmainsize()const;


    //setters
    void setsnack(menuattributes* newSnacks, int newSize);
    void setbev(menuattributes* newBevs, int newSize);
    void setdess(menuattributes* newDess, int newSize);
    void setmain(menuattributes* newMain, int newSize);

    void setsnacksize(int s);
    void setbevsize(int b);
    void setdesssize(int d);
    void setmainsize(int m);


    // Display function for snack menu
    void displaySnackMenu();


    // Display function fo beverages menu
    void displayBeveragesMenu();


    // Display function fodessert menu
    void displayDessertMenu();


    // Display function for main menu
    void displayMainMenu();


    // View menu function that has all menus
    virtual void viewMenu();

    //destructor
    ~Menutype();
};



