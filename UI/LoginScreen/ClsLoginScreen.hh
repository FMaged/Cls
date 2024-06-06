#pragma once
#include "../ClsScreen.hh"
#include "../../Global.hh"
#include "../../ClsValidate.hh"
#include "../ClsMainScreen.hh"

class ClsLoginScreen:protected ClsScreen{
private:
    static bool _login(){
        bool loginFalid=false;
        short faildLoginCount=0;
        string userName, password;
        do
        {
            if(loginFalid){
                faildLoginCount++;
                cout<<"\nInvaled UserName/Password\n";
                cout<<"\nYou have "<<(3-faildLoginCount)<<" Trail(s) to login\n\n";
            }
            if(faildLoginCount==3){
                cout<<"You are locked after 3 faild trails \n\n ";
                return false;
            }
            cout<<"Enter UserName? ";
            userName=ClsValidate::readString();
            cout<<"Eneter Password? ";
            password=ClsValidate::readString();
            CurrentUser=ClsUser::find(userName,password);
            loginFalid=CurrentUser.isEmpty();

        } while (loginFalid);
        CurrentUser.registerLogin();
        ClsMainScreen::showMainMenue();
        return true;
    }

public:
    static bool showLoginScreen(){
        system("clear");
        _drawScreenHeader("\t      Login Screen");
        return _login();
    }










};