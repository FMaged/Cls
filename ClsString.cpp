
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
string ClsString::getValue(){
    return _value;
}
string ClsString::upperAllString(string S){
    for (size_t i = 0; i < S.length(); i++){
        S[i]=toupper(S[i]);
    }
    return S;
}
void ClsString::upperAllString(){
    _value=upperAllString(_value);
}
string ClsString::lowerAllString(string S){
    for (size_t i = 0; i < S.length(); i++){
        S[i]=tolower(S[i]);
    }
    return S;
}
void ClsString::lowerAllString(){
    _value=lowerAllString(_value);
}
char ClsString::invertLetterCase(char C){
    if(islower(C)){
        return toupper(C);
    }else{
        return tolower(C);
    }

}
string ClsString::invertAllLetterCase(string S){
    for (size_t i = 0; i < S.length(); i++){
        S[i]=invertLetterCase(S[i]);
    }

    return S;
    
}
void ClsString::invertAllLetterCase(){
    _value=invertAllLetterCase(_value);
}
short ClsString::countCapitalLetter(string S){
    short count=0;
    for (size_t i = 0; i <S.length(); i++){
        if(isupper(S[i])) count++;
    }
    return count;
    
}
short ClsString::countCapitalLetter(){
    return countCapitalLetter(_value);
}
short ClsString::countSmallLetter(string S){
    short count=0;
    for (size_t i = 0; i < S.length(); i++){
        if(islower(S[i])) count++;
    }
    return count;
}
short ClsString::countSmallLetter(){
    return countSmallLetter(_value);
}
short ClsString::countLetterInString(string S,char C){
    short count=0;
    for (size_t i = 0; i < S.length(); i++){
        if(S[i]==C) count++;
    }
    return count;
}



















