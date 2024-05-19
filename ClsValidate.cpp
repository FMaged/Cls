
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
int ClsValidate::readIntNumberBetween(short From, short To){
    int number =readIntNumber();
    while (!isNumberBetween(number,From,To)){
        cout<<"invalid int, pls enter again["<<From <<" - "<<To<<"]"<<endl;
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
double ClsValidate::readDblNumberBetween(double From,double To){
    double number =readDblNumber();
    while (!isNumberBetween(number,From,To)){
            printf("Invalid double, please enter again [%.2f - %.2f]\n", From, To);
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
string ClsValidate::readString(){
    string str;
    getline(cin >>ws, str);
    return str;

}






























