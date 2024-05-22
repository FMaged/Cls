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
        cout<<"\nAccount number is not founf, chose another one!";
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
        case ClsClient::enSaveResult::svFaild:
            cout << "\nError account was not saved because it's Empty";
            break;
    }


}

int main(){
updateClient();


    return 0;
}   