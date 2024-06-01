
#include "ClsValidate.hh"

bool ClsValidate::isNumberBetween(short Number,short From,short To){
    if(Number<=To&&Number>=From){
        return 1;
    }else{
        return 0;
    }
}
bool ClsValidate::isNumberBetween(int Number, short From, short To){
    if(Number<=To&&Number>=From){
        return 1;
    }else{
        return 0;
    }
}
bool ClsValidate::isNumberBetween(double Number, short From, short To){
    if(Number<=To&&Number>=From){
        return 1;
    }else{
        return 0;
    }
}
bool ClsValidate::isNumberBetween(float Number, short From, short To){
    if(Number<=To&&Number>=From){
        return 1;
    }else{
        return 0;
    }
}
int ClsValidate::readIntNumber(){
    int number;
    while(!(cin>>number)){
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Invalid int, pls enter again!\n";
    }
    return number;
}
int ClsValidate::readIntNumberBetween(short From, short To,string ErrorMessage){
    int number =readIntNumber();
    while (!isNumberBetween(number,From,To)){
        cout<<ErrorMessage<<endl;
        number=readIntNumber();
    }
    return number;
}
double ClsValidate::readDblNumber(){
        double number;
    while(!(cin>>number)){
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Invalid int, pls enter again!\n";
    }
    return number;
}
double ClsValidate::readDblNumberBetween(double From,double To,string ErrorMessage){
    double number =readDblNumber();
    while (!isNumberBetween(number,From,To)){   
        cout<<ErrorMessage<<endl;
        number=readIntNumber();
    }
    return number;
}
char ClsValidate::readChar(){
    char c;
    while (true){
        if(cin>>c&&isalpha(c)){
            return c;
        }else{
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Invalid input, pls enter again a singel alpabettic charachter.\n";

        }
    }
}
char ClsValidate::readY_OR_N(char Yes,char No){
    char answer=toupper(readChar());
    while (answer!=Yes&&answer!=No){
        cout<<"Invalid input, pls enter again a[ y - n ]: \n";
        answer=toupper(readChar());

    }
    return answer;

}
string ClsValidate::readString(){
    string str;
    getline(cin >>ws, str);
    return str;

}






























