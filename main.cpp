#include "ClsString.hh"
#include "ClsValidate.hh"
#include "ClsDate.hh"

int main(){
    ClsDate Date1("25.05.2024");
    ClsDate Date2("27.05.2024");

    cout<<Date2.compareDates(Date1)<<endl;

    return 0;
}