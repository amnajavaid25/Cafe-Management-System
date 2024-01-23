#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class User
{
protected:
    string user_type;
public:
    //default constructor
    User();

    //getter for user 
    string getUser();

    //setter for user
    void setUser(string& user);

    // Overloaded input operator
    friend istream& operator>>(istream& in, User& user);

    // Pure virtual function to make User an abstract class
    virtual void view_menu() = 0;
};

