#pragma once 
#include "ClsScreen.hh"
#include "../ClsValidate.hh"
#include "../ClsClient.hh"



class ClsUpdateClientScreen:protected ClsScreen{

private:
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













public:
    static void showUpdateClientScreen(){
        if(!checkAccessRight(ClsUser::enPermission::pUpdateUser)){
            return ;
        }
        _drawScreenHeader("\tUpdate Client screen");
        cout<<"\nPls enter account number: ";
        string accountNumber=ClsValidate::readString();
        while(!ClsClient::isClientExist(accountNumber)){
            cout<<"\nAccount number is not found, chose another one!";
             accountNumber=ClsValidate::readString();
        }
        
        ClsClient Client=ClsClient::find(accountNumber);
        _printClientCard(Client);
        cout<<"\n\nUpdate Client Info:";
        cout<<"\n--------------------\n";
        _readClientInfo(Client);
        ClsClient::enSaveResult saveResult;
        saveResult=Client.save();
        switch (saveResult){
            case ClsClient::enSaveResult::svSucceeded:
                cout<<"\nAccount Updated Successfully :-)\n";
                _printClientCard(Client);
                break;
            case ClsClient::enSaveResult::svFaildEmptyObj:
                cout<<"\nError account was not saved because it's Empty";
                break;
        }



    }
























};