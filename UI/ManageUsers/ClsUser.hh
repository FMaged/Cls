#pragma once
 #include <fstream>
 #include "../../ClsPerson.hh"
 #include "../../ClsString.hh"

static string UsersFileName="UI/ManageUsers/Users.txt";
class ClsUser:public ClsPerson{ 
private:
    enum enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
    enMode _mode;
    string _userName;
    string _password;
    int _permission;
    bool __markForDelete=false;

private:
    static ClsUser _convertLineToUser(string Line,string Seperator="#//#"){
        vector<string>vUsers=ClsString::splitString(Line,Seperator);
        return ClsUser(enMode::UpdateMode,vUsers[0],vUsers[1],vUsers[2],vUsers[3],vUsers[4],vUsers[5],stoi(vUsers[6]));
    }
    static string _convertUserToLine( ClsUser User,string Seperator="#//#"){
        string line="";
        line+=User.getFirstName()+Seperator;
        line+=User.getLastName()+Seperator;
        line+=User.getEmail()+Seperator;
        line+=User.getPhone()+Seperator;
        line+=User.getUserName()+Seperator;
        line+=User.getPassword()+Seperator;
        line+=to_string(User.getPermission());
        return line;
    }
    static  ClsUser _getEmptyUserObj(){
        return ClsUser(enMode::EmptyMode,"","","","","000","",0);
    }
    static vector<ClsUser>_loadUsersFromFile(){
    
        vector<ClsUser>vUsers;
        fstream myFile;
        myFile.open(UsersFileName,ios::in);  // Open the File in readOnly mode.
        if(myFile.is_open()){
            string line;
            while(getline(myFile,line)){
                ClsUser user=_convertLineToUser(line);
                vUsers.push_back(user);
            }
            myFile.close();
        }
        return vUsers;
    }
    static void _saveUsersDataToFile(vector<ClsUser>vUsers){
        fstream myFile;
        string line;
        myFile.open(UsersFileName,ios::out);  // overwrite.
        if(myFile.is_open()){
            for(ClsUser U:vUsers){
                if(U.markedForDelete()==false){     
                    line=_convertUserToLine(U);
                    myFile<<line<<endl;
                }
            }
            myFile.close();
        }
    }
    void _update(){
        vector<ClsUser>vUsers=_loadUsersFromFile();
        for(ClsUser& U:vUsers){
            if(U._userName==_userName){
                U=*this;
                break;
            }
        }
        _saveUsersDataToFile(vUsers);
    }
    void _addNew(){
        _addDataLineToFile(_convertUserToLine(*this));
    }
    void _addDataLineToFile(const string& Line){
        
        fstream myFile;
        myFile.open(UsersFileName,ios::app);
        if(myFile.is_open()){
            myFile<<Line<<endl;
            myFile.close();
        }
    

    }


public:
    ClsUser(enMode Mode, string FirstName, string LastName,
            string Email, string Phone, string UserName, string Password,
            int Permissions):ClsPerson(FirstName,LastName,Email,Phone){
        _mode=Mode;
        _userName=UserName;
        _password=Password;
        _permission=Permissions;
    }
    bool isEmpty(){
        return (_mode==enMode::EmptyMode);
    }
    void setMarkedForDelete(bool Mark=true){
        __markForDelete=Mark;
    }
    bool markedForDelete(){
        return __markForDelete;
    }
    string getUserName(){
        return _userName;
    }
    void setUserName(string UserName){
        _userName=UserName;
    }
    string getPassword(){
        return _password;
    }
    void setPassword(string Password){
        _password=Password;
    }
    int getPermission(){
        return _permission;
    }
    void setPermission(int Permission){
        _permission=Permission;
    }
    static ClsUser find(string UserName){
       fstream myFile;
       myFile.open(UsersFileName,ios::in);
       if(myFile.is_open()){
            string line;
            while(getline(myFile,line)){
                ClsUser User=_convertLineToUser(line);
                if(UserName==User._userName){
                    
                    return User;
                }   
                             
            }
            myFile.close();
            
       }
            
       return _getEmptyUserObj();
    }
    static ClsUser find(string UserName,string Password){
        fstream myFile;
        myFile.open(UsersFileName,ios::in);
        if(myFile.is_open()){
            string line;
            while (getline(myFile,line)){
                ClsUser User=_convertLineToUser(line);
                if(User._userName==UserName&&User._password==Password){
                    myFile.close();
                    return User;
                }
            }
            myFile.close();
        }
        return _getEmptyUserObj();
    }
    static bool isUserExist(string UserName){
        ClsUser user=ClsUser::find(UserName);
        return (!user.isEmpty());
    }


    enum enSaveResult{svFaildEmptyObj=0,svSucceeded=1,svFaildUserExists=2};
    enSaveResult save(){
        switch (_mode){
        case enMode::EmptyMode:
            return enSaveResult::svFaildEmptyObj;
            break;
        case enMode::UpdateMode:
            _update();
            return enSaveResult::svSucceeded;        
            break;
        case enMode::AddNewMode:
            if(isUserExist(_userName)){
                return enSaveResult::svFaildUserExists;
            }else{
                _addNew();
                 //We need to set the mode to update after add new
                _mode=enMode::UpdateMode;
                return enSaveResult::svSucceeded;
            }
        }
    }


    bool deleteUser(){
        vector<ClsUser>vUsers=_loadUsersFromFile();
        _saveUsersDataToFile(vUsers);
        for(ClsUser& U:vUsers){
            if(U._userName==_userName){
                U.setMarkedForDelete(true);
                break;
            }
        }
        *this=_getEmptyUserObj();
        return true;
    }

    static ClsUser getAddNewUserObj(string UserName){
        return ClsUser(enMode::AddNewMode,"","","","",UserName,"",0);
    }
    static vector<ClsUser> getUsersList(){
        return _loadUsersFromFile();
    }





























};
