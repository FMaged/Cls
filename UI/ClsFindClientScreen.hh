#pragma once 
#include "ClsScreen.hh"
#include "../ClsValidate.hh"
#include "../ClsClient.hh"



class ClsFindClientScreen:protected ClsScreen{
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






public:
    static void showFindClientScreen(){
        if(!checkAccessRight(ClsUser::enPermission::pFindUser)){
            return ;
        }
        _drawScreenHeader("\t     Find Client Screen");
        cout<<"\nPls enter account number: ";
        string accountNumber=ClsValidate::readString();
        while (!ClsClient::isClientExist(accountNumber)){
            cout<<"\nAccount number is not found, chose another one!";
            accountNumber=ClsValidate::readString();
        }
        ClsClient Client=ClsClient::find(accountNumber);
        _printClientCard(Client);
        
    }















};