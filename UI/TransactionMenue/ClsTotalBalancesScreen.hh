#pragma once
#include <iomanip>
#include "../ClsScreen.hh"
#include "../../ClsClient.hh"




class ClsTotalBalancesScreen:protected ClsScreen{
private:




static void _printClientsBalanceLine(ClsClient Client){
    cout <<"| "<<setw(15)<<left<<Client.getAccountNumber();
    cout <<"| "<<setw(40)<<left<<Client.getFullName();
    cout <<"| "<<setw(12)<<left<<Client.getBalance();

}

static void _printClientBalanceHead(){
    cout << "\n\t-------------------------------------------------------";
    cout << "-----------------------------------------\n" << endl; 
    cout <<"\t| "<<setw(15)<<left<<"Account Number";
    cout <<"| "<<setw(40)<<left<<"Client Name";
    cout <<"| "<<setw(12)<<left<<"Balance";
    cout << "\n\t-------------------------------------------------------";
    cout << "-----------------------------------------\n" << endl;

}









public:
    static void showTotalBalancesScreen(){
        vector<ClsClient>vClients=ClsClient::getClientsList();
        string Title="\tTotal Balances Screen";
        string supTitle="\t    (" + to_string(vClients.size()) + ") Client(s).";
        _drawScreenHeader(Title,supTitle);
        cout << "\n\t=======================================================";
        cout << "=========================================\n" << endl;
        _printClientBalanceHead();
        for(ClsClient C:vClients){
            cout<<"\t";
            _printClientsBalanceLine(C);
            cout<<endl;
        }
        double totalBalances=ClsClient::getTotalBalances();
        cout << "\n\t-------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        cout << "\t\t\t\t\t\t    Total Balances = " << totalBalances << endl;
        cout << "\t\t\t\t\t\t   ( " << ClsString::numberToText(totalBalances) << ")\n";
    }










};