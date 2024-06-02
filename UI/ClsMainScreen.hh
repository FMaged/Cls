#pragma once 
#include "ClsScreen.hh"
#include "ClsClientListScreen.hh"
#include "ClsAddNewClientScreen.hh"
#include "ClsDeleteClientScreen.hh"
#include "ClsUpdateClientScreen.hh"
#include "ClsFindClientScreen.hh"
#include "TransactionMenue/ClsTransactionMenueScreen.hh"
#include "ManageUsers/ManageUsersScreen.hh"
#include "../ClsValidate.hh"
#include <iomanip>


class ClsMainScreen :protected ClsScreen{

private:

enum enMainScreenOptions{eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
                        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
                        eManageUsers = 7, eExit = 8};

static short _readMainMenueOption(){
    cout<<setw(37)<<left<<""<<"Chose what do you want [1 - 8]"<<endl;
    short choice=ClsValidate::readIntNumberBetween(1,8,"Enter Number between 1 to 8?");
    return choice;
}
static void _goBackToMainMenue(){
   // cout<<setw(37)<<left<<"Press any Key to go back to Main Menue...\n";
    system("read -p 'Press any key to continue...' var");
    showMainMenue();
}
static void _showAllClientScreen(){
    ClsClientListScreen::showClientsList();
}
static void _addNewClientnScreen(){
    ClsAddNewClientScreen::showAddNewClientScreen();
}
static void _deleteClientScreen(){
    ClsDeleteClientScreen::showDeleteClientScreen();
}
static void _updateClientScreen(){
    ClsUpdateClientScreen::showUpdateClientScreen();
}
static void _findClientScreen(){    
    ClsFindClientScreen::showFindClientScreen();
}
static void _transactionsMenueScreen(){
    ClsTransactionMenueScreen::showTransactionMenue();
}
static void _manageUsersScreen(){
    ClsManageUsersScreen::showManageUserScreen();
}
static void _endScreen(){
    cout<<"\nEnd Screen will be here...\n";
}







static void _preformMainMenueOption(enMainScreenOptions MainMenueOption){
    switch (MainMenueOption){
    case enMainScreenOptions::eListClients:
        system("clear");
        _showAllClientScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eAddNewClient:
        system("clear");
        _addNewClientnScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eDeleteClient:
        system("clear");
        _deleteClientScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eUpdateClient:
        system("clear");
        _updateClientScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eFindClient:
        system("clear");
        _findClientScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eShowTransactionsMenue:
        system("clear");
        _transactionsMenueScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eManageUsers:
        system("clear");
        _manageUsersScreen();
        _goBackToMainMenue();
        break;
    case enMainScreenOptions::eExit:
        system("clear");
        _endScreen();
        break;

    }
}
public:
    static void showMainMenue(){
        system("clear   ");
        _drawScreenHeader("\t     Main Screen");
            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _preformMainMenueOption((enMainScreenOptions)_readMainMenueOption());
    }





};