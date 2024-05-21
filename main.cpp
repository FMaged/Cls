#include "ClsString.hh"
#include "ClsValidate.hh"
#include "ClsDate.hh"

int main(){

ClsDate Date("25.05.1999");
ClsDate Date2=ClsDate::getSystemDate();

Date.print();
Date2.print();
    return 0;
}