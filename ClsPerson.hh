#pragma once
#include <iostream>


using namespace std;

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
ClsPerson(string FirstName, string LastName, string Email, string Phone);
ClsPerson(string FirstName, string LastName,string Phone);

string getFullName();
void print();
void sendEmail(string Subject, string Body);
void sendSMS(string TXTMessage);











};