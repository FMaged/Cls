#pragma once 
#include "ClsUser.hh"
#include "../ClsScreen.hh"
#include "../../ClsValidate.hh"



class ClsFindUserScreen:protected ClsScreen{
private:
    static void _printUser(ClsUser User){
                cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.getFullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhone();
        cout << "\nUser Name   : " << User.getUserName();
        cout << "\nPassword    : " << User.getPassword();
        cout << "\nPermissions : " << User.getPermission();
        cout << "\n___________________\n";
    }









public:
    static void showFindUserScreen(){
        _drawScreenHeader("\t     Find User Screen");
        cout<<"\nPls enter UserName: ";
        string userName=ClsValidate::readString();
        while(!ClsUser::isUserExist(userName)){
            cout<<"\nAccount number is not found, chose another one!";
            userName=ClsValidate::readString();
        }
        ClsUser User=ClsUser::find(userName);
        _printUser(User);



    }









};