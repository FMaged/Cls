#include "ClsClient.hh"
#include "ClsValidate.hh"


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
    string accountnum;

    cout<<"\nPls enter account number: ";
    accountnum=ClsValidate::readString();
    while (!ClsClient::isClientExist(accountnum)){
        cout<<"\nAccount number is not found, chose another one!";
        accountnum=ClsValidate::readString();
    }
    ClsClient Client=ClsClient::find(accountnum);
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
void AddNewClient(){
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
int main(){
    AddNewClient();

    return 0;
}