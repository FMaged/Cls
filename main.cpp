#include "ClsClient.hh"
#include "ClsDate.hh"

int main(){


ClsDate Date("31.03.2024");
ClsDate Date2=ClsDate::getSystemDate();

Date.decreaseDateByXDecacdes(2);

Date.print();
Date2.print();
    return 0;
}