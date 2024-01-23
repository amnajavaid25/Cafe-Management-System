#pragma once
#include "User.h"
#include"FacultyMenu.h"
#include"nonfacmenu.h"
#include"studentmenu.h"
#include"Menutype.h"
#include"Inventory.h"
#include"order.h"
class Cafe_staff :public User
{
protected:
    Inventory inventory;


public:
    void view_menu();

    void process_order();

    void add_menu_items();

    void remove_menu_item();

    void logout();
};

