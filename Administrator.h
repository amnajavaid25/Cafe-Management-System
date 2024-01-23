#pragma once
#include "User.h"
#include"Inventory.h"
#include"FacultyMenu.h"
#include"nonfacmenu.h"
#include"Menutype.h"
#include"studentmenu.h"
#include"filemanager.h"
#include"payment.h"
#include <fstream>
#include <sstream>

class Administrator :public User
{
protected:
    Inventory inventory;

public:
    Administrator();

    void view_menu();

    void add_menu_items();

    void remove_menu_item();

    void manage_inventory();

    void manage_discount();

    void view_order_history();

    void add_notification();

    void remove_notification();

    //file handling

    void view_users_from_file();

    void view_menu_items_from_file();

    void view_ratings_from_file();

    void view_payments_from_file();

    void calculate_monthly_earnings();

    void logout();
};

