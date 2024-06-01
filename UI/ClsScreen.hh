#pragma once
#include <iostream>


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
    
    }










};

