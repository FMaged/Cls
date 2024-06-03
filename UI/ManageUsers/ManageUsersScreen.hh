#pragma once 

#include "../ClsScreen.hh"
#include "../../ClsValidate.hh"
#include "ClsListUsersScreen.hh"
#include "ClsAddNewUserScreen.hh"
#include "ClsDeleteUserScreen.hh"
#include "ClsUpdateUserScreen.hh"
#include "ClsFindUserScreen.hh"
class ClsManageUsersScreen:protected ClsScreen{
private:
    enum enManageUsersMenueOption{
        eListUsers=1,eAddNewUser=2,eDeleteUser=3,
        eUpdateUser=4,eFindUser=5,eMainMenue=6
    };

    static short _readManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = ClsValidate::readIntNumberBetween(1,6,"Enter Number between 1 to 6?");
        return Choice;
    }
    static void _goBackToManageUsersScreen(){
        system("read -p 'Press any key to continue...' var");
        showManageUserScreen();
    }
    static void _showListUsersScreen(){
        ClsListUsersScreen::showListUsersScrenn();
    }
    static void _showAddNewUserScreen(){
        ClsAddNewUserScreen::showAddNewUserScreen();
    }
    static void _showDeleteUserScreen(){
        ClsDeleteUserScreen::showDeleteUserScreen();
    }
    static void _showUpdateUserScreen(){
        ClsUpdateUserScreen::showUpdateUserScreen();
    }
    static void _showFindUserScreen(){
        ClsFindUserScreen::showFindUserScreen();
    }
    static  void _showMainMenueScreen(){
        //dont need to do anything it will go back to the main menue. 
    }










    static void _prefomManageUserScreen(enManageUsersMenueOption ManageUsersMenueOption ){
        switch (ManageUsersMenueOption){
        case enManageUsersMenueOption::eListUsers:
            system("clear");
            _showListUsersScreen();
            _goBackToManageUsersScreen();
            break;
        case enManageUsersMenueOption::eAddNewUser:
            system("clear");
            _showAddNewUserScreen();
            _goBackToManageUsersScreen();
            break;
        case enManageUsersMenueOption::eDeleteUser:
            system("clear");
            _showDeleteUserScreen();
            _goBackToManageUsersScreen();
            break;
        case enManageUsersMenueOption::eUpdateUser:
            system("clear");
            _showUpdateUserScreen();
            _goBackToManageUsersScreen();
            break;
        case enManageUsersMenueOption::eFindUser:
            system("clear");
            _showFindUserScreen();
            _goBackToManageUsersScreen();
            break;
        case enManageUsersMenueOption::eMainMenue:
            system("clear");
            _showMainMenueScreen();
            break;

        }
    }




public:
    static void showManageUserScreen(){
        system("clear");
        _drawScreenHeader("\tManage User Screen");
            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\tManage User Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n"; 
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Delete User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User.\n";
            cout << setw(37) << left << "" << "\t[5] Find User.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
        _prefomManageUserScreen((enManageUsersMenueOption)_readManageUsersMenueOption());

    }














};