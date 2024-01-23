#pragma once
#include"menutype.h"
class studentmenu :public Menutype
{
public:
	//default constructor
	studentmenu();
	//override view menu function
	void viewMenu();
	~studentmenu();
	void savestudentmenutofile(const string& menuItemData);
};



