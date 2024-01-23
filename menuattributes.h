#pragma once
#include<iostream>
using namespace std;
class menuattributes
{
protected:
	string Itemname;
	string Itemdescription;
	int price;
	int Quantityinstock;
	int Itemid;


public:
	//paramterized constructor
	menuattributes(string itemname, string itemdescription, int price, int quantityinstock, int id);

	//default constructor
	menuattributes();

	//copy constructor
	menuattributes(const menuattributes& other);

	//destructor
	~menuattributes();

	//getters
	int getitemid()const;
	string getitemname()const;
	string getitemdescription()const;
	int getitemprice()const;
	int getqttyinstock()const;

	//setters
	void setitemid(int ID);
	void setitemname(string name);
	void setitemdesc(string desc);
	void setprice(int p);
	void setqtty(int qtty);

	//display info
	friend void displaymenuattributes(menuattributes& other);


};



