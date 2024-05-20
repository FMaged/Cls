
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
short ClsString::countLetterInString(char C){
    return countLetterInString(_value,C);
}
short ClsString::countLetter(string S, char C, bool MatchCase){
    short count=0;
    for (size_t i = 0; i < S.length(); i++){
        if(MatchCase){
            if(S[i]==C) count++;
        }
        else {
            if(toupper(S[i]==toupper(C))) count++;
        }
    }
    return count;
}
short ClsString::countLetter( char C, bool MatchCase){
    return countLetter(_value,C,MatchCase);
}
string ClsString::upperFirstLetterOfEachWord(string S){
    bool isFirstLetter=1;
    for (size_t i = 0; i < S.length(); i++){
        if(isalpha(S[i])||S[i]==' '){
            if(isFirstLetter&&S[i]!=' '){
                S[i]=toupper(S[i]);
            }
            isFirstLetter=(S[i]==' '?1:0);
        }
        
    }
    return S;
    
}
void ClsString::upperFirstLetterOfEachWord(){
    _value=upperFirstLetterOfEachWord(_value);
}
string ClsString::lowerFirstLetterOfEachWord(string S){
    bool isFirstLetter=1;
    for (size_t i = 0; i < S.length(); i++){
        if(isalpha(S[i])||S[i]==' '){
            if(isFirstLetter&&S[i]!=' '){
                S[i]=tolower(S[i]);
            }
            isFirstLetter=(S[i]==' '?1:0);
        }
        
    }
    return S;
}
void ClsString::lowerFirstLetterOfEachWord(){
    _value=lowerFirstLetterOfEachWord(_value);
}
int ClsString::countWordsInString(string S,string Delimiter){
size_t pos=0;
int counter =0;
string sword="";
while ((pos=S.find(Delimiter))!=std::string::npos){
    sword =S.substr(0,pos);
    if(sword!="") {
        counter++;
    }
    S.erase(0,pos+Delimiter.length());
}
if(S!=""){ 
    counter++;
    }
return counter;

}
int ClsString::countWordsInString(string Delimiter){
return countWordsInString(_value,Delimiter);
}
bool ClsString::isVowel(char C){
C=tolower(C);
return ((C=='a')||(C=='e')||(C=='i')||(C=='o')||(C=='u'));
}
int ClsString::countVowel(string S){
    int count=0;
    for (size_t i = 0; i < S.length(); i++){
        if(isVowel(S[i])){
            count++;
        }
    }
    return count;

}
int ClsString::countVowel(){
    return countVowel(_value);
}
void ClsString::printEachWordInString(string S,string Delimiter){
    size_t pos=0;
    string sWord;
    while ((pos=S.find(Delimiter))!=std::string::npos){
        sWord=S.substr(0,pos);
        if(sWord!=""){
            cout<<sWord<<endl;
        }
        S.erase(0,pos+Delimiter.length());
    }
    if(S!=""){
        cout <<S<<endl;
    }

    
}
void ClsString::printEachWordInString(){
    printEachWordInString(_value);
}
vector<string> ClsString::splitString(string S,string Delimiter){
vector<string> vec;
size_t pos=0;
string sWord="";
while ((pos=S.find(Delimiter))!=std::string::npos){
    sWord=S.substr(0,pos);
    if(sWord!=""){
        vec.push_back(sWord);
    }
    S.erase(0,pos+Delimiter.length());
}
if(S!=""){
    vec.push_back(S);
}
return vec;

}
vector<string> ClsString::splitString(string Delimiter){
    return splitString(_value,Delimiter);
}
string ClsString::joinString(vector<string>vec,string Delimiter){
string str="";
for (size_t i = 0; i < vec.size(); i++){
    str=str+vec[i]+Delimiter;
}
return str.substr(0,str.length()-Delimiter.length());       //delete the last Delimiter

}
void ClsString::joinStringToValue(vector<string>vec,string Delimiter){
_value=joinString(vec,Delimiter);

}
string ClsString::joinString(string arr[],int size,string Delimiter){
    string str="";
   for (int i = 0; i < size; i++){
        str=str+arr[i]+Delimiter;
   }
   return str.substr(0,str.length()-Delimiter.length());
}
void ClsString::joinStringToValue(string arr[],int size,string Delimite){
    _value=joinString(arr,size,Delimite);

}
string ClsString::trimLeft(string S){
    for (size_t i = 0; i < S.length(); i++){
        if(S[i]!=' '){
            return S.substr(i,S.length()-1);
        }
    }
    return "";

}
void ClsString::trimLeft(){
    _value= trimLeft(_value);
}
string ClsString::trimRight(string S){
    size_t i=S.length();
    while (i>0){
        if(S[i-1]!=' '){
            return S.substr(0,i);
        }
        i--;
    }
    return "";    
}
void ClsString::trimRight(){
    _value= trimRight(_value);
}
string ClsString::trim(string S){
    return (trimLeft(trimRight(S)));
}
void ClsString::trim(){
    _value= trim(_value);
}
string ClsString::reverseWordInString(string S){
    vector<string>vec=splitString(S," ");
    vector<string>::iterator it=vec.end();
    string str="";
    while(it!=vec.begin()){
        it--;
        str+=*it+' ';
    }
    return str.substr(0,str.length()-1);
}
void ClsString::reverseWordInString(){
    _value= reverseWordInString(_value);
}
string ClsString::replaceWordInString(string S,string wordToReplace, string replaceTo,bool MatchCase){
    vector<string>vec=splitString(S," ");
    for(string& str:vec){
        if(MatchCase){
            if(str==wordToReplace){
                str=replaceTo;
            }
            
        }else{
            if(lowerAllString(str)==lowerAllString(wordToReplace)){
                str=replaceTo;
            }         
        }   
    }
    return joinString(vec ," ");
}
void ClsString::replaceWordInString(string wordToReplace, string replaceTo,bool MatchCase){
    _value=replaceWordInString(_value,wordToReplace,replaceTo,MatchCase);
}
string ClsString::removePunctuation(string S){
    string str="";
    for(char C:S){
        if(!ispunct(C)){
            str+=C;
        }
    }
    return str;
}
void ClsString::removePunctuation(){
    _value=removePunctuation(_value);
}














