#include "ClsString.hh"
#include "ClsValidate.hh"
#include "ClsDate.hh"

int main(){


ClsDate Date2=ClsDate::getSystemDate();
cout<<endl<<Date2.daysUntilTheEndOfMonth()<<endl;

Date2.print();
    return 0;
}