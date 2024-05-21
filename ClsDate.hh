
#include "ClsString.hh"

class ClsDate{

private:

short _day;
short _month;
short _year;




public:

    ClsDate();
    ClsDate(short Day,short Month,short Year);
    ClsDate(string Date);


    short getDay();
    short getMonth();
    short getYear();
    void setDate(short Day,short Month,short Year);
    void setDate(ClsDate Date);
    
    static string dateToString(ClsDate Date);
    string dateToString();
    static ClsDate stringToDate(string S);
    void stringToThisDate(string S);



    static bool isLeapYear(short Year);
    bool isLeapYear();
    static short numberOfDaysInYear(short Year);
    short numberOfDaysInYear();
    static short numberOfHoursInYear(short Year);
    short numberOfHoursInYear();
    static int numberOfMinutsInYear(short Year);
    int numberOfMinutsInYear();
    static int numebrOfSecundsInYear(short Year);
    int numebrOfSecundsInYear();
    static short numberOfDaysInMonth(short Month,short Year);
    short numberOfDaysInMonth();
 
    static short dayOfWeekOrder(ClsDate Date);
    static short dayOfWeekOrder(short Day,short Month,short Year);
    short dayOfWeekOrder();
    static string dayShortName(short DayOfWeekOrder);
    string dayShortName();
    static string MonthShortName(short Month);
    string MonthShortName();

    static void printDataOfYear(short Year);
    void printDataOfYear();
    static void printMonthCalender(short Month,short Year);
    void printMonthCalender();
    static void printYearCalender(short Year);
    void printYearCalender();












};