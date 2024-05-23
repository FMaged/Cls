#pragma once
#include <fstream>
#include "ClsPerson.hh"
#include "ClsString.hh"


 
static string FileName="Client.txt";

class ClsClient:public ClsPerson{
private:

    
    enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=2,DeleteMode=3 };
    enMode _Mode;

    string _accountNumber;
    std::string _pinCode;
    double _balance;
    bool _markForDelete=false;

    static ClsClient _convertLineToClient(string Line,string Seperator="#//#");
    static string _converClientToLine( ClsClient Client,string Seperator="#//#");
    static ClsClient _getEmptyClientObj();
    static vector<ClsClient>_loadClientsFromFile();
    static void _saveClientsDataToFile(vector<ClsClient>vClients);
    void _update();
    void _addNew();


    void _addDataLineToFile(string Line);

        

public:
    ClsClient(enMode Mode,string FirstName, string LastName, string Email, string Phone,string AccountNumber,string PinCode,double Balance)
    :ClsPerson( FirstName,  LastName,  Email,  Phone){
        _Mode=Mode;
        _accountNumber=AccountNumber;
        _pinCode=PinCode;
        _balance=Balance;
    }

    bool isEmpty()const;
    string getAccountNumber()const;
    double getBalance()const;
    string getPinCode()const;

    void setBalance(double Balance);
    void setPinCode(string PinCode);
    void print();
    static ClsClient find(string AccountNumber);
    static bool isClientExist(string AccountNumber);
    static ClsClient addNewClient(string AccountNumber);
    bool deleteClient();    
    static vector<ClsClient> getClientsList();  
    static double getTotalBalances();


    enum enSaveResult{svFaildEmptyObj=0,svSucceeded=1,svFaildAccNumberExists=2};
    enSaveResult save();
    
};  