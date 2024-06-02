#pragma once 
#include "../ClsScreen.hh"
#include "../ClsMainScreen.hh"
#include "../../ClsValidate.hh"
#include "ClsDepositScreen.hh"
#include "ClsWithdrawScreen.hh"
#include "ClsTotalBalancesScreen.hh"
#include <iomanip>



class ClsTransactionMenueScreen:protected ClsScreen{
private:
    enum enTransactionScreenOption{Deposit=1,Withdraw=2,TotalBalances=3,MainMenue=4};

    static short _readTransactionScreenOption(){
        cout<<setw(37)<<left<<""<<"Chose what do you want [1 - 4]"<<endl;
        short choice=ClsValidate::readIntNumberBetween(1,4,"Enter Number between 1 to 4?");
        return choice;
    }
    static void _goBackToTransactionMenue(){
        system("read -p 'Press any key to continue...' var");
        showTransactionMenue();
    }
    static void _deposit(){
        ClsDepositScreen::showDepositScreen();
    }
    static void _withdraw(){
        ClsWithdrawScreen::showWithdrawScreen();
    }
    static void _totalBalances(){
        ClsTotalBalancesScreen::showTotalBalancesScreen();
    }
    static void _goBackToMainMenue(){
            //dont need to do anything it will go back to the main menue.          
    }













static void _prefomTransactionMenueOption(enTransactionScreenOption TransactionScreenOption){
    switch (TransactionScreenOption){
    case enTransactionScreenOption::Deposit:
        system("clear");
        _deposit();
        _goBackToTransactionMenue();
        break;
    case enTransactionScreenOption::Withdraw:
        system("clear");
        _withdraw();
        _goBackToTransactionMenue();
        break;
    case enTransactionScreenOption::TotalBalances:
        system("clear");
        _totalBalances();
        _goBackToTransactionMenue();
        break;
    case enTransactionScreenOption::MainMenue:
        system("clear");
        _goBackToMainMenue();
        break;
    }
}
public:

    static void showTransactionMenue(){
        system("clear");
        _drawScreenHeader("\t   Transaction Screen");
            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n"; 
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
            cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
        _prefomTransactionMenueOption((enTransactionScreenOption)_readTransactionScreenOption());
    }













};