#pragma once
#include "ClsPerson.hh"

class ClsClient:public ClsPerson{
private:
    string _accountNumber;
    std::string _pinCode;
    double _balance;

public:
    ClsClient(string FirstName, string LastName, string Email, string Phone,string AccountNumber,string PinCode,double Balance)
    :ClsPerson( FirstName,  LastName,  Email,  Phone){
        _accountNumber=AccountNumber;
        _pinCode=PinCode;
        _balance=Balance;
    }


    string getAccountNumber();
    double getBalance();

};