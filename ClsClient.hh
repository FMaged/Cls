#pragma once
#include <fstream>
#include "ClsPerson.hh"
#include "ClsString.hh"


 
static string FileName="Client.txt";

class ClsClient:public ClsPerson{
private:

    
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _accountNumber;
    std::string _pinCode;
    double _balance;

    static ClsClient _convertLineToClient(string Line,string Seperator="#//#");
    static string _converClientToLine(ClsClient Client,string Seperator="#//#");
    static ClsClient _getEmptyClientObj();
    static vector<ClsClient>_loadClientsFromFile();
    static void _saveClientsDataToFile(vector<ClsClient>vClients);
    void _update();
    void _addDataLineToFile(string Line);



public:
    ClsClient(enMode Mode,string FirstName, string LastName, string Email, string Phone,string AccountNumber,string PinCode,double Balance)
    :ClsPerson( FirstName,  LastName,  Email,  Phone){
        _Mode=Mode;
        _accountNumber=AccountNumber;
        _pinCode=PinCode;
        _balance=Balance;
    }

    bool isEmpty();
    string getAccountNumber();
    double getBalance();
    string getPinCode();

    void setBalance(double Balance);
    void setPinCode(string PinCode);
    void print();
    static ClsClient find(string AccountNumber);
    static bool isClientExist(string AccountNumber);

    enum enSaveResult{svFaild=0,svSucceeded=1};
    enSaveResult save();
    
};  