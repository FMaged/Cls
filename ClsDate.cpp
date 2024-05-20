#include "ClsDate.hh"


ClsDate::ClsDate(){
    time_t t=time(0);
    tm* now=localtime(&t);
    _day=now->tm_mday;
    _month=now->tm_mon;
    _year=now->tm_year;
}
ClsDate::ClsDate(short Day,short Month,short Year){
    _day=Day;
    _month=Month;
    _year=Year;
}
ClsDate::ClsDate(string Date){



}
ClsDate::ClsDate(short dateOrderInYear, short Year){



}


short ClsDate::getDay(){

    return _day;
}
short ClsDate::getMonth(){
    return _month;
}
short ClsDate::getYear(){
    return _year;
}
void ClsDate::setDate(short Day,short Month,short Year){
    _day=Day;
    _month=Month;
    _year=Year;
}
void ClsDate::setDate(ClsDate Date){
    _day=Date._day;
    _month=Date._month;
    _year=Date._year;
}






































