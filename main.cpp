#include "ClsString.hh"
#include "ClsValidate.hh"
#include "ClsDate.hh"

int main(){

ClsDate Date("21.05.2024");
Date.printDataOfYear();
cout<<endl<<Date.dayOfWeekOrder()<<endl;

Date.printYearCalender();

    return 0;
}