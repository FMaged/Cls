#pragma once

#include "ClsScreen.hh"
#include "../ClsValidate.hh"
#include "../ClsClient.hh"

#include <iomanip>


class ClsAddNewClientScreen:protected ClsScreen{
private:
    static void _readClientInfo(ClsClient& NewClient){
        cout<<"\nEnter FirstName: ";
        NewClient.setFirstName(ClsValidate::readString());
        cout<<"\nEnter LastName: ";
        NewClient.setLastName(ClsValidate::readString());
        cout<<"\nEnter Email: ";
        NewClient.setEmail(ClsValidate::readString());
        cout<<"\nEnter Phone: ";
        NewClient.setPhone(ClsValidate::readString());
        cout<<"\nEnter PinCode: ";
        NewClient.setPinCode(ClsValidate::readString());
        cout<<"\nEnter Balance: ";
        NewClient.setBalance(ClsValidate::readDblNumber());



    }
    static void _printClientCard(ClsClient Client){
        cout<<"\n       Client";
        cout<<"\n____________________________";
        cout<<"\nFirstName  :"<<Client.getFirstName();
        cout<<"\nLastName   :"<<Client.getLastName();
        cout<<"\nFullName   :"<<Client.getFullName();
        cout<<"\nEmail      :"<<Client.getEmail();
        cout<<"\nPhone      :"<<Client.getPhone();
        cout<<"\nAcc. Number:"<<Client.getAccountNumber();
        cout<<"\nPassWord   :"<<Client.getPinCode();
        cout<<"\nBalance    :"<<Client.getBalance();
        cout<<"\n____________________________\n";
    }






public:
    static void showAddNewClientScreen(){
        _drawScreenHeader("\t Add new Client screen");
        string accountNumber;

    cout<<"\nPls enter account number: ";
    accountNumber=ClsValidate::readString();
    while (ClsClient::isClientExist(accountNumber)){
        cout<<"\nAccount number is Exist, chose another one!";
        accountNumber=ClsValidate::readString();
    }
    ClsClient newClient=ClsClient::addNewClient(accountNumber);
    _readClientInfo(newClient);
    ClsClient::enSaveResult SaveResult=newClient.save();
    switch (SaveResult){
    case ClsClient::enSaveResult::svSucceeded:
        cout << "\nAccount Addeded Successfully :-)\n";
        _printClientCard(newClient);
        break;
    case ClsClient::enSaveResult::svFaildEmptyObj:
        cout << "\nError account was not saved because it's Empty";
        break;
    case ClsClient::enSaveResult::svFaildAccNumberExists:
        cout << "\nError account was not saved because account number is used!\n";
        break;
    default:
        break;
    }


    }










};