#pragma once
#include "../ClsScreen.hh"
#include "../../Global.hh"
#include "../../ClsValidate.hh"
#include "../ClsMainScreen.hh"

class ClsLoginScreen:protected ClsScreen{
private:
    static void _login(){
        bool loginFalid=false;
        string userName, password;
        do
        {
            if(loginFalid){
                cout<<"\nInvaled UserName/Password\n";
            }
            cout<<"Enter UserName? ";
            userName=ClsValidate::readString();
            cout<<"Eneter Password? ";
            password=ClsValidate::readString();
            CurrentUser=ClsUser::find(userName,password);
            loginFalid=CurrentUser.isEmpty();

        } while (loginFalid);
        ClsMainScreen::showMainMenue();
    }

public:
    static void showLoginScreen(){
        system("clear");
        _drawScreenHeader("\t      Login Screen");
        _login();
    }










};