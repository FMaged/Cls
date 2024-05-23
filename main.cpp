#include "ClsClient.hh"
#include "ClsValidate.hh"
#include "ClsString.hh"


void readClientInfo(ClsClient& Client){
    cout<<"\nEnter FirstName: ";
    Client.setFirstName(ClsValidate::readString());
    cout<<"\nEnter LastName: ";
    Client.setLastName(ClsValidate::readString());
    cout<<"\nEnter Email: ";
    Client.setEmail(ClsValidate::readString());
    cout<<"\nEnter Phone: ";
    Client.setPhone(ClsValidate::readString());
    cout<<"\nEnter PinCode: ";
    Client.setPinCode(ClsValidate::readString());
    cout<<"\nEnter Balance: ";
    Client.setBalance(ClsValidate::readDblNumber());



}
void updateClient(){

    string accountNumber;
    cout<<"\nPls enter account number: ";
    accountNumber=ClsValidate::readString();
    while (!ClsClient::isClientExist(accountNumber)){
        cout<<"\nAccount number is not found, chose another one!";
        accountNumber=ClsValidate::readString();
    }
    ClsClient Client=ClsClient::find(accountNumber);
    Client.print();
    cout<<"\n\nUpdate Client Info:";
    cout<<"\n--------------------\n";
    readClientInfo(Client);
    
    ClsClient::enSaveResult SaveResult;
    SaveResult=Client.save();
    switch (SaveResult){
        case ClsClient::enSaveResult::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            Client.print();
            break;
        case ClsClient::enSaveResult::svFaildEmptyObj:
            cout << "\nError account was not saved because it's Empty";
            break;
    }


}
void addNewClient(){
    string accountNumber;

    cout<<"\nPls enter account number: ";
    accountNumber=ClsValidate::readString();
    while (ClsClient::isClientExist(accountNumber)){
        cout<<"\nAccount number is Exist, chose another one!";
        accountNumber=ClsValidate::readString();
    }
    ClsClient newClient=ClsClient::addNewClient(accountNumber);
    readClientInfo(newClient);
    ClsClient::enSaveResult SaveResult=newClient.save();
    switch (SaveResult){
    case ClsClient::enSaveResult::svSucceeded:
        cout << "\nAccount Addeded Successfully :-)\n";
        newClient.print();
        break;
    case ClsClient::enSaveResult::svFaildEmptyObj:
        cout << "\nError account was not saved because it's Empty";
        break;
    case ClsClient::enSaveResult::svFaildAccNumberExists:
        cout << "\nError account was not saved because account number is used!\n";
        break;
    default:
        break;
    }

}
void deleteClient(){
    string accountNumber;

    cout<<"\nPls enter account number: ";
    accountNumber=ClsValidate::readString();
    while(!ClsClient::isClientExist(accountNumber)){
         cout<<"\nAccount number is not found, chose another one!";
        accountNumber=ClsValidate::readString();   
    }
    ClsClient Client=ClsClient::find(accountNumber);
    Client.print();
    char answer='n';
    cout<<"\nAre you sure you want to DÉLETE this Client [y-n]? ";
    cin>>answer;
    if(answer=='y'||answer=='Y'){
        if(Client.deleteClient()){
           cout<<"\nDelete Successfuly :-)\n";
           Client.print(); 
        }else{
            cout<<"\nError Client was not deleted\n";
        }
    }





}

void printClientRecordLine(ClsClient Client){

    cout << "| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(20) << left << Client.getFullName();
    cout << "| " << setw(12) << left << Client.getPhone();
    cout << "| " << setw(20) << left << Client.getEmail();
    cout << "| " << setw(10) << left << Client.getPinCode();
    cout << "| " << setw(12) << left << Client.getBalance();

}
void printClientsBalanceLine(ClsClient Client){
    cout <<"| "<<setw(15)<<left<<Client.getAccountNumber();
    cout <<"| "<<setw(40)<<left<<Client.getFullName();
    cout <<"| "<<setw(12)<<left<<Client.getBalance();

}
void showClients(){
    vector<ClsClient>vClients=ClsClient::getClientsList();
    cout<<"\n\t\t\t\t\tClients List: ("<<vClients.size()<<") Client(s).";
    cout<<"\n-------------------------------------------------------";
    cout << "-----------------------------------------\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout<<"\n-------------------------------------------------------";
    cout << "-----------------------------------------\n" << endl;

    if(vClients.size()==0){
        cout << "\t\t\t\tNo Clients Available In the System!";
    }else{
        for(ClsClient& C:vClients){
            printClientRecordLine(C);
            cout << endl;
        }
    }
    cout<<"\n-------------------------------------------------------";
    cout << "-----------------------------------------\n" << endl;
}
void showTotalBalance(){
vector<ClsClient>vClients=ClsClient::getClientsList();
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    double totalBalances=ClsClient::getTotalBalances();
        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            for(ClsClient C:vClients){
                printClientsBalanceLine(C);
                cout<<endl;
            }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << totalBalances << endl;
    cout << "\t\t\t\t\t   ( " << ClsString::numberToText(totalBalances) << ")\n";


}



int main(){
    showClients();
    showTotalBalance();

    return 0;
}