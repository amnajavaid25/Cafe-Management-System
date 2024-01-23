#include "menuattributes.h"


// Parameterized Constructor
menuattributes::menuattributes(string itemname, string itemdescription, int price, int quantityinstock, int id)
    : Itemname(itemname), Itemdescription(itemdescription), price(price), Quantityinstock(quantityinstock), Itemid(id) {}

// Default Constructor
menuattributes::menuattributes() : Itemname(""), Itemdescription(""), price(0), Quantityinstock(0), Itemid(0) {}

//copy constructor:
menuattributes::menuattributes(const menuattributes& other)
{
    Itemid = other.Itemid;
    Itemname = other.Itemname;
    Itemdescription = other.Itemdescription;
    Quantityinstock = other.Quantityinstock;
    price = other.price;
}

// Destructor
menuattributes::~menuattributes()
{

}

// Getter Functions
int menuattributes::getitemid() const
{
    return Itemid;
}

string menuattributes::getitemname() const
{
    return Itemname;
}

string menuattributes::getitemdescription() const
{
    return Itemdescription;
}

int menuattributes::getitemprice() const
{
    return price;
}

int menuattributes::getqttyinstock() const
{
    return Quantityinstock;
}

// Setter Functions
void menuattributes::setitemid(int id)
{
    Itemid = id;
}

void menuattributes::setitemname(string name)
{
    Itemname = name;
}

void menuattributes::setitemdesc(string desc)
{
    Itemdescription = desc;
}

void menuattributes::setprice(int p)
{
    price = p;
}

void menuattributes::setqtty(int qtty)
{
    Quantityinstock = qtty;
}



//function to display menu attributes
void displaymenuattributes(menuattributes& other)
{
    cout << "\t\t\t\tITEM ID:" << other.Itemid << " " << " ITEM NAME:" << other.Itemname << " " << "ITEM DESCRIPTION:" << other.Itemdescription << " " << "ITEM PRICE:" << other.price << " " << " QUANTITY:" << other.Quantityinstock << endl;
}
