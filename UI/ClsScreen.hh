#pragma once
#include <iostream>
#include "../Global.hh"
#include "../ClsDate.hh"
#include "ManageUsers/ClsUser.hh"

using namespace std;

class ClsScreen{
protected:
    static void _drawScreenHeader(string Title,string SubTitle =""){
        cout << "\t\t\t\t\t--------------------------------------";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";
        cout<<"\t\t\t\t\t  User: "<<CurrentUser.getUserName()<<endl;
        cout<<"\t\t\t\t\t  Date: "<<ClsDate::dateToString(ClsDate())<<endl<<endl;
    }

    static bool checkAccessRight(ClsUser::enPermission Permission){
        if(!CurrentUser.checkAccessPermission(Permission)){
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }else{
            return true;
        }
    }








};

