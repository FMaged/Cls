#pragma once 
#include "../ClsScreen.hh"
#include "../../ClsValidate.hh"
#include "../../ClsClient.hh"



class ClsDepositScreen:ClsScreen{

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


    static void showDepositScreen(){
        _drawScreenHeader("Deposit Screen");
        cout<<"\nPls enter account number: ";
        string accountNumber=ClsValidate::readString();
        while (!ClsClient::isClientExist(accountNumber)){
            cout<<"\nAccount number is not found, chose another one!";
            accountNumber=ClsValidate::readString(); 
        }
        ClsClient Client=ClsClient::find(accountNumber);
        _printClientCard(Client);
        cout<<"\nEnter the amount you want to Deposit: ";
        float amount=ClsValidate::readDblNumber();
        printf("Are you sure you want to Deposit %.2f to the %s Account [Y - N]",
           amount,
           Client.getAccountNumber().c_str());
        char answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            Client.deposit(amount);
            cout << "\nAmount Deposited Successfully.\n";
            Client=ClsClient::find(accountNumber);
            cout << "\nNew Balance Is: " << Client.getBalance()<<endl;        
        }else{
             cout << "\nOperation was cancelled.\n";
        }
    }

    






};