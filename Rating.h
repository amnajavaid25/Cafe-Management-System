#ifndef RATING_H
#define RATING_H

#include<iostream>
#include<string>
#include "filemanager.h"
using namespace std;

class Rating {
private:
    static int RatingIDCounter;
    int RatingID;
    int MenuItemID;
    int CustomerID;
    int Score;
    string comments;

public:
    Rating();
    void Rate(int menuItemID, filemanager& manager);
};

#endif 