#include "User.h"
#include"Administrator.h"
#include"Cafe_staff.h"
#include"Customer.h"
#include<iostream>
#include<cstring>
using namespace std;


//USER TYPE 
//default constructor
User::User()
{
    user_type = " ";
}


//getter for user
string User::getUser()
{
    return user_type;
}

//setter for user
void User::setUser(string& user)
{
    user_type = user;
}

// Overloaded input operator
istream& operator>>(istream& in, User& user)
{
    cout << "Kindly enter if you are administrator / cafe staff / customer: ";
    in >> user.user_type;
    return in;
}
