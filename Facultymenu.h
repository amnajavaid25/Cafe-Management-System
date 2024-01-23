#pragma once
#include"menutype.h"
#include"filemanager.h"
class facultymenu :public Menutype
{
public:
	//default constructor
	facultymenu();

	//override view menu function
	void viewMenu();
	~facultymenu();
	void savefacmenutofile(const string& menuItemData);
};