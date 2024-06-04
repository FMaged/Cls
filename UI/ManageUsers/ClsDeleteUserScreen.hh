#pragma once 
#include "ClsUser.hh"
#include "../ClsScreen.hh"
#include "../../ClsValidate.hh"


class ClsDeleteUserScreen:protected ClsScreen{
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

static void showDeleteUserScreen(){
    _drawScreenHeader("\t   Delete User Screen");
    cout<<"\nPls enter UserName: ";
    string userName=ClsValidate::readString();
    while(!ClsUser::isUserExist(userName)){
         cout<<"\nAccount number is not found, chose another one!";
         userName=ClsValidate::readString();
    }
    ClsUser User=ClsUser::find(userName);
    _printUser(User);
    char answer='N';
    cout<<"\nAre you sure you want to DÉLETE this Client [y-n]? ";
    answer=ClsValidate::readY_OR_N();
    if(answer=='Y'){
        if(User.deleteUser()){
            cout<<"\nDelete Successfuly :-)\n";
            _printUser(User);
        }else{
            cout<<"\nError Client was not deleted\n";
        }    
    
    }





}




















};