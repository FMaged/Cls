#pragma once
#include "iomanip"
#include "../ClsScreen.hh"
#include "ClsUser.hh"


class ClsListUsersScreen:protected ClsScreen{

private:
    static void _printClientRecordLine(ClsUser User){   
        cout << "\t| " << setw(15) << left << User.getUserName();
        cout << "| " << setw(20) << left << User.getFullName();
        cout << "| " << setw(12) << left << User.getPhone();
        cout << "| " << setw(20) << left << User.getEmail();
        cout << "| " << setw(10) << left << User.getPassword();
        cout << "| " << setw(12) << left << User.getPermission();
    }










public:
    static void showListUsersScrenn(){
        vector<ClsUser>vUsers=ClsUser::getUsersList();
        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";
        _drawScreenHeader(Title,SubTitle);
        cout<<setw(8)<<left<<"\n\t------------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        cout << "\t| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permission";
        cout<<"\n\t------------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        if(vUsers.size()==0){
            cout<<"\t\t\tNo User Available!";

        }else{
            for(ClsUser U:vUsers){
                _printClientRecordLine(U);
                cout<<endl;
            }
        cout<<"\n\t------------------------------------------------------------";
        cout << "-----------------------------------------\n" << endl;
        }
    }















};