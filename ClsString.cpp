
#include "ClsString.hh"

ClsString::ClsString(){
    _value="";
}
ClsString::ClsString(string S){
    _value=S;
}
void ClsString::setValue(string S){
    _value = S;
}
