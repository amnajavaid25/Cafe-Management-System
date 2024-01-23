#pragma once
#include "User.h"
#include"FacultyMenu.h"
#include"nonfacmenu.h"
#include"studentmenu.h"
#include"order.h"
#include"Rating.h"
#include"Menutype.h"
#include"payment.h"
#include"table_reservation.h"
class Customer :public User
{
public:
    void view_menu();

    void place_order();

    void booktable();

    void view_order_history();

    void rate_items();

    void logout();
};

