#pragma once
#include "ClsString.hh"

class ClsPerson{

private:
string _firstName;
string _lastName;
string _email;
string _phone; 

protected:
    //Set Property
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmail(string Email);
    void setPhone(string Phone);

    //Get Property
    string getFirstName();
    string getLastName();
    string getEmail();
    string getPhone();



public:













};