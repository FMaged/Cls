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
    vector<string>vec=ClsString::splitString(Date,".");
    _day=stoi(vec[0]);
    _month=stoi(vec[1]);
    _year=stoi(vec[2]);
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

string ClsDate::dateToString(ClsDate Date){
    string str="";
    if(Date._day<10){
        str.push_back('0');
        str+=to_string(Date._day);
    }else{
        str+=to_string(Date._day);
    }
    str+='.';
    if(Date._month<10){
        str.push_back('0');
        str+=to_string(Date._month);
    }else{
        str+=to_string(Date._month);
    }
    str+='.';
    str+=to_string(Date._year);
    return str;
}
string ClsDate::dateToString(){
    return dateToString(*this);
}
ClsDate ClsDate::stringToDate(string S){
    ClsDate Date;
    vector<string>vec=ClsString::splitString(S,".");
    Date._day=stoi(vec[0]);
    Date._month=stoi(vec[1]);
    Date._year=stoi(vec[2]);
    return Date;
}
void ClsDate::stringToThisDate(string S){
    *this=stringToDate(S);
}






bool ClsDate::isLeapYear(short Year){
    return (Year%4==0&&Year%100!=0)||(Year%400==0);
}
bool ClsDate::isLeapYear(){
    return isLeapYear(_year);
}
short ClsDate::numberOfDaysInYear(short Year){
    return isLeapYear(Year)?366:365;
}
short ClsDate::numberOfDaysInYear(){
    return numberOfDaysInYear(_year);
}
short ClsDate::numberOfHoursInYear(short Year){
    return numberOfDaysInYear(Year)*24;
}
short ClsDate::numberOfHoursInYear(){
    return numberOfHoursInYear(_year);
}
int ClsDate::numberOfMinutsInYear(short Year){
    return (numberOfHoursInYear(Year)*60);
}
int  ClsDate::numberOfMinutsInYear() {
    return numberOfMinutsInYear(_year);
}
int ClsDate::numebrOfSecundsInYear(short Year){
    return numberOfMinutsInYear(Year)*60;
}
int ClsDate::numebrOfSecundsInYear(){
    return numebrOfSecundsInYear(_year);
}
short ClsDate::numberOfDaysInMonth(short Month,short Year){
    if(Month<1||Month>12) return 0;
    int numberOfDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(Month==2){
        return isLeapYear(Year)?29:28; 
    }else{
        return numberOfDays[Month-1];
    }
}
short ClsDate::numberOfDaysInMonth(){
    return numberOfDaysInMonth(_month,_year);
}
void ClsDate::printDataOfYear(short Year){
    cout<<"\n-----------------------------";
    cout<<"\nDays   : "<<numberOfDaysInYear(Year);
    cout<<"\nHours  : "<<numberOfHoursInYear(Year);
    cout<<"\nMinuts : "<<numberOfMinutsInYear(Year);
    cout<<"\nSecunds: "<<numebrOfSecundsInYear(Year);
    cout<<"\n-----------------------------";
}
void ClsDate::printDataOfYear(){
    printDataOfYear(_year);
}
short ClsDate::dayOfWeekOrder(short Day,short Month,short Year){
    short a=(14-Month)/12;
    short y= Year-a;
    short m=Month+(12*a)-2;
    return (Day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;
}
short ClsDate::dayOfWeekOrder(ClsDate Date){
    short a=(14-Date._month)/12;
    short y=Date._year-a;
    short m=Date._month+(12*a)-2;
    return (Date._day+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;
}
short ClsDate::dayOfWeekOrder(){
    return dayOfWeekOrder(_day,_month,_year);
}
string ClsDate::dayShortName(short DayOfWeekOrder){
    string DayName[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    return DayName[DayOfWeekOrder];

}
string ClsDate::dayShortName(){
    return dayShortName(dayOfWeekOrder(*this));
}
string ClsDate::MonthShortName(short Month){
    string monthName[]={"jan","Feb","Mar","Apr","Mai","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return monthName[Month-1];
}
string ClsDate::MonthShortName(){
    return MonthShortName(_month);
}
void ClsDate::printMonthCalender(short Month,short Year){
    int numberOfDays=numberOfDaysInMonth(Month,Year);
    int current=dayOfWeekOrder(1,Month,Year);
    printf("\n---------------%s-----------------\n",MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i;
    for ( i = 0; i < current; i++)
        printf("     ");
    for(int j=1;j<numberOfDays;j++){
        printf("%5d",j);
        if(++i==7){
            i=0,
            printf("\n");
        }
    }

    printf("\n-----------------------------------\n");
    

}
void ClsDate::printMonthCalender(){
    printMonthCalender(_month,_year);
}
void ClsDate::printYearCalender(short Year){
     printf("\n____________________________________\n\n");
     printf("         Calender - %d\n",Year);
     printf("______________________________________\n");
     for (size_t i = 1; i < 12; i++){
        printMonthCalender(i,Year);
     }
     
}
void ClsDate::printYearCalender(){
    printYearCalender(_year);
}




















