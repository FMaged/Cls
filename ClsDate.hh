#pragma onec
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
    ClsDate(short dateOrderInYear, short Year);

    short getDay();
    short getMonth();
    short getYear();
    void setDate(short Day,short Month,short Year);
    void setDate(ClsDate Date);
    


};