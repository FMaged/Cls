#pragma once
#include "ClsScreen.hh"
#include "../ClsValidate.hh"
#include "../ClsClient.hh"


class ClsDeleteClientScreen:protected ClsScreen{
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
static void showDeleteClientScreen(){
    _drawScreenHeader("\tDelete Client Screen");
        string accountNumber;

    cout<<"\nPls enter account number: ";
    accountNumber=ClsValidate::readString();
    while(!ClsClient::isClientExist(accountNumber)){
         cout<<"\nAccount number is not found, chose another one!";
        accountNumber=ClsValidate::readString();   
    }
    ClsClient Client=ClsClient::find(accountNumber);
    _printClientCard(Client);
    char answer='N';
    cout<<"\nAre you sure you want to DÉLETE this Client [y-n]? ";
    answer=ClsValidate::readY_OR_N('Y','N');
    if(answer=='Y'){
        if(Client.deleteClient()){
           cout<<"\nDelete Successfuly :-)\n";
           _printClientCard(Client); 
        }else{
            cout<<"\nError Client was not deleted\n";
        }
    }



}











};