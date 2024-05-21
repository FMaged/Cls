
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
    short dayOfWeekOrder()const;
    static string dayShortName(short DayOfWeekOrder);
    string dayShortName()const;
    static string MonthShortName(short Month);
    string MonthShortName()const;

    static void printDataOfYear(short Year);
    void printDataOfYear()const;
    static void printMonthCalender(short Month,short Year);
    void printMonthCalender()const;
    static void printYearCalender(short Year);
    void printYearCalender()const;
    
    static short daysFromBeginnOfTheYear(short Day,short Month,short Year);
    short daysFromBeginnOfTheYear()const;


    static bool isDate1BeforeDate2(const ClsDate& Date1, const ClsDate& Date2);
    bool isBeforeDate2(const ClsDate& Date2)const;
    static bool isDate1AfterDate2(const ClsDate& Date1,const ClsDate& Date2);
    bool isAfterDate2(const ClsDate& Date2)const;
    static bool isDate1EqualToDate2(const ClsDate& Date1, const ClsDate& Date2);
    bool isEqualToDate2(const ClsDate& Date2)const;
    static bool isLastDayInMonth(const ClsDate& Date);
    bool isLastDayInMonth()const;
    static bool isLastMonthInYear(const ClsDate& Date);
    bool isLastMonthInYear()const;
    static bool isEndOfWeek(const ClsDate& Date);
    bool isEndOfWeek()const;
    static bool isWeekEnd(const ClsDate& Date);
    bool isWeekEnd()const;
    static bool isBusinessDay(const ClsDate& Date);            //dose not include official holidays
    bool isBusinessDay()const;
    static bool isValidDate(const ClsDate& Date);
    bool isValidDate()const;









};