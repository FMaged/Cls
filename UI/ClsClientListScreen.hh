#pragma once
#include "ClsScreen.hh"
#include "../ClsClient.hh"
#include <iomanip>
    

class ClsClientListScreen:protected ClsScreen{
private:
static void _printClientRecordLine(ClsClient Client){
    cout << "\t| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(20) << left << Client.getFullName();
    cout << "| " << setw(12) << left << Client.getPhone();
    cout << "| " << setw(20) << left << Client.getEmail();
    cout << "| " << setw(10) << left << Client.getPinCode();
    cout << "| " << setw(12) << left << Client.getBalance();
}



public:
    static void showClientsList(){
        vector<ClsClient> vClients=ClsClient::getClientsList();
        string title="\t  Client List Screen";
        string subTitle="\t    (" + to_string(vClients.size()) + ") Client(s).";
        _drawScreenHeader(title,subTitle);
        cout<<setw(8)<<left<<"\n\t------------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        cout << "\t| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout<<"\n\t------------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        if(vClients.size()==0){
            cout<<"\n\t\t\t\tNo Clients Available!\n";
        }else{
            for(ClsClient C:vClients){
                _printClientRecordLine(C);
                cout<<endl;

            }
        cout<<setw(8)<<left<<"\n\t------------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        }
    }


















};
