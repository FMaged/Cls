#include "ClsClient.hh"


string ClsClient::getAccountNumber()const{
    return _accountNumber;
}
double ClsClient::getBalance()const{
    return _balance;
}
bool ClsClient::isEmpty()const{
    return (_Mode==enMode::EmptyMode);
}
string ClsClient::getPinCode()const{
    return _pinCode;
}
void ClsClient::setBalance(double Balance){
    _balance=Balance;
}
void ClsClient::setPinCode(string PinCode){
    _pinCode=PinCode;
}

// No UI inside object.
//  void ClsClient::print(){
//      cout<<"\n       Client";
//      cout<<"\n____________________________";
//      cout<<"\nFirstName  :"<<getFirstName();
//      cout<<"\nLastName   :"<<getLastName();
//      cout<<"\nFullName   :"<<getFullName();
//      cout<<"\nEmail      :"<<getEmail();
//      cout<<"\nPhone      :"<<getPhone();
//      cout<<"\nAcc. Number:"<<getAccountNumber();
//      cout<<"\nPassWord   :"<<getPinCode();
//      cout<<"\nBalance    :"<<getBalance();
//      cout<<"\n____________________________\n";
//  }
vector<ClsClient> ClsClient::_loadClientsFromFile(){
    vector<ClsClient>vClients;
    ifstream myFile;
    myFile.open(ClientsFileName,ios::in);  //read Mode
    if(myFile.is_open()){
        string line;
        while(getline(myFile,line)){
            ClsClient Client=_convertLineToClient(line);
            vClients.push_back(Client);
        }
        myFile.close();
    }
    return vClients;    
}
void ClsClient::_saveClientsDataToFile(vector<ClsClient>vClients){

    ofstream myFile;
    myFile.open(ClientsFileName,ios::out);
    string line;
    if(myFile.is_open()){
        for(ClsClient& C :vClients){
            if(C._markForDelete==false){
                line=_converClientToLine(C);
                myFile<<line<<endl; 
            }
        }
        myFile.close();
    }
 

}
void ClsClient::_update(){
    vector<ClsClient>vClients=_loadClientsFromFile();
    for(ClsClient& C : vClients){
        if(C._accountNumber==_accountNumber){
            C=*this;
            break;
        }  
         
    }
    _saveClientsDataToFile(vClients);

}
void ClsClient::_addDataLineToFile(string Line){
    fstream myFile;
    myFile.open(ClientsFileName,ios::out|ios::app);
    if(myFile.is_open()){
        myFile<<Line<<endl;
        myFile.close();
    }
}
void ClsClient::_addNew(){
    _addDataLineToFile(_converClientToLine(*this));
}
ClsClient ClsClient::_convertLineToClient(string Line,string Seperator){
    vector<string>vClientData=ClsString::splitString(Line,Seperator);
    return ClsClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
        vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
}
string ClsClient::_converClientToLine( ClsClient Client,string Seperator){
    string clientRecord="";
    clientRecord+=Client.getFirstName()+Seperator;
    clientRecord+=Client.getLastName()+Seperator;
    clientRecord+=Client.getEmail()+Seperator;
    clientRecord+=Client.getPhone()+Seperator;
    clientRecord+=Client.getAccountNumber()+Seperator;
    clientRecord+=Client.getPinCode()+Seperator;
    clientRecord+=to_string(Client.getBalance());
    return clientRecord;
}
ClsClient ClsClient::_getEmptyClientObj(){
    return ClsClient(enMode::EmptyMode,"","","","","","",0);
}
ClsClient ClsClient::find(string AccountNumber){
    fstream myFile;
    myFile.open(ClientsFileName,ios::in);
    if(myFile.is_open()){
        string line;
        while (getline(myFile,line)){
            ClsClient Client=_convertLineToClient(line);
            if(AccountNumber==Client._accountNumber){
                return Client;
            }
            
        }
        myFile.close();
        
    }
    return _getEmptyClientObj();

}
ClsClient ClsClient::addNewClient(string AccountNumber){
    return ClsClient(enMode::AddNewMode,"","","","",AccountNumber,"",0);
}
bool ClsClient::isClientExist(string AccountNumber){
    ClsClient Client=find(AccountNumber);
    return (!Client.isEmpty());
}
void ClsClient::deposit(double Amount){
    _balance+=Amount;
    save();
}
bool ClsClient::withdraw(double Amount){
    if(Amount>_balance){
        return false;
    }else{
        _balance-=Amount;
        save();
        return true;
    }
}

bool ClsClient::deleteClient(){
vector<ClsClient>vClients=_loadClientsFromFile();
for(ClsClient& C:vClients){
    if(C._accountNumber==_accountNumber){
        C._markForDelete=true;
        break;
    }
}
_saveClientsDataToFile(vClients);
*this =_getEmptyClientObj();
return true;


}
vector<ClsClient> ClsClient::getClientsList(){
    return _loadClientsFromFile();
}
double ClsClient::getTotalBalances(){
    vector<ClsClient>vClients=_loadClientsFromFile();
    double totalBalances=0;
    for(ClsClient C:vClients){
        totalBalances+=C._balance;
    }
    return totalBalances;

}

ClsClient::enSaveResult ClsClient::save(){
    switch (_Mode){
    case enMode::EmptyMode:
        return enSaveResult::svFaildEmptyObj;
    case enMode::UpdateMode:
        _update();
        return enSaveResult::svSucceeded;   
       break;
    case enMode::AddNewMode:
        
        if(ClsClient::isClientExist(_accountNumber)){
            return enSaveResult::svFaildAccNumberExists;
        }else{
            _addNew();
            _Mode=enMode::UpdateMode;
            return enSaveResult::svSucceeded;

        }
        break;
    
    default:
    return enSaveResult::svFaildEmptyObj;
}

}







