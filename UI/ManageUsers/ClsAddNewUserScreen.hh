#pragma once 
#include "../ClsScreen.hh"
#include "ClsUser.hh"
#include "../../ClsValidate.hh"


class ClsAddNewUserScreen:protected ClsScreen{

private:
    static void _readUserInfo(ClsUser& User){
        cout<<"\nEnter FirstName: ";
        User.setFirstName(ClsValidate::readString());
        cout<<"\nEnter LastName: ";
        User.setLastName(ClsValidate::readString());
        cout<<"\nEnter Email: ";
        User.setEmail(ClsValidate::readString());
        cout<<"\nEnter Phone: ";
        User.setPhone(ClsValidate::readString());
        cout<<"\nEnter Password: ";
        User.setPassword(ClsValidate::readString());
        cout<<"\nEnter Permission: ";
        User.setPermission(_readPermissionToSet());

    }

    static int _readPermissionToSet(){
        int permission=0;
    
        cout<<"\nDo you want to give full access? Y/N?";
        char answer=ClsValidate::readY_OR_N();
        if(answer=='Y')return -1;
        cout<<"\nDo you want to give access to : \n";
        cout<<"\nShow Users List? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pListUser;
        }
        cout<<"\nAdd new User? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pAddnewUser;
        }
        cout<<"\nDelete User? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pDeleteUser;
        }
        cout<<"\nUpdate User? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pUpdateUser;
        }
        cout<<"\nFind User? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pFindUser;
        }
        cout<<"\nTransaction? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pTransactios;
        }
        cout<<"\nManage Users? Y/N? ";
        answer=ClsValidate::readY_OR_N();
        if(answer=='Y'){
            permission+=ClsUser::enPermission::pManageUser;
        }
        return permission;
    }

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
    static void showAddNewUserScreen(){
        _drawScreenHeader("\t  Add New USer Screen");
        cout<<"\nPls enter UserName: ";
        string userName=ClsValidate::readString();
        while (ClsUser::isUserExist(userName)){
            cout<<"\nAccount number is Exist, chose another one!";
            userName=ClsValidate::readString();

        }
        ClsUser newUser=ClsUser::getAddNewUserObj(userName);
        _readUserInfo(newUser);
        ClsUser::enSaveResult saveResult;
        saveResult=newUser.save();
        switch (saveResult){
        case ClsUser::enSaveResult::svFaildEmptyObj:
            cout << "\nError account was not saved because it's Empty";
            break;
        case ClsUser::enSaveResult::svSucceeded:
            cout << "\nAccount Addeded Successfully :-)\n";
            _printUser(newUser);
            break;
        case ClsUser::enSaveResult::svFaildUserExists:
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }

        
    }




















};