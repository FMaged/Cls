#include "ClsString.hh"
#include "ClsValidate.hh"
#include "ClsDate.hh"

int main(){

ClsDate Date;
ClsDate Date2("1.1.2023");

cout<<endl<<ClsDate::isValidDate(Date)<<endl;
    return 0;
}