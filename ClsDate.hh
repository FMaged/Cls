#pragma onec
#include "ClsString.hh"

class ClsDate{
short _day;
short _month;
short _year;




public:

    ClsDate();
    ClsDate(short Day,short Month,short Year);
    ClsDate(string Date);
    ClsDate(short dateOrderInYear, short Year);




};