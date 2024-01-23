#pragma once
#include"menutype.h"
#include"filemanager.h"
class nonfacmenu :public Menutype
{
public:
	//default constructor
	nonfacmenu();
	//override view menu function
	void viewMenu();
	~nonfacmenu();
	void savenonfacmenutofile(const string& menuItemData);
};



