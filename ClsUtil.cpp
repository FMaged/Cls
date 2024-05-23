#include "ClsUtil.hh"


void ClsUtil::Srand(){
    //The Seed generator in c++ only called once 
    srand((unsigned)time(0));

}
int ClsUtil::randomNumber(){
    return rand(); 
}
int ClsUtil::randomNumber(int From, int To){
    return rand()%(To-From+1)+From;

}
char ClsUtil::randomCharacter(enCharType CharType) {
    switch (CharType) {
        case enCharType::SmallLetter:
            return char(randomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(randomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(randomNumber(33, 47));
        case enCharType::Digital:
            return char(randomNumber(48, 57)); // Adjusted to include digits '0' to '9'
        case enCharType::MixLetter: {
            // Generate a random number from 1 to 4 to choose from the other character types
            int i = randomNumber(1, 2);
            
            enCharType mixType;
            // Convert the integer back to enCharType
            mixType = static_cast<enCharType>(i);
            // Recursively call randomCharacter with the randomly selected type
            return randomCharacter(mixType);
        }
        case enCharType::MixKey:{
            short j=randomNumber(1,3);
            enCharType mixKey;
            mixKey=static_cast<enCharType>(j);
            return randomCharacter(mixKey);
        }
        default:    
            return char(randomNumber(65, 90)); // Default to capital letters if an invalid CharType is provided
    }
}
string ClsUtil::randomstring(enCharType CharType, short Length){
    string str="";
    for (short i = 0; i < Length; i++){
        str=str+randomCharacter(CharType);
    }
    return str; 
}
    string ClsUtil::randomKey(enCharType CharType){
        string str="";
        str+=randomstring(CharType,4)+"-";
        str+=randomstring(CharType,4)+"-";
        str+=randomstring(CharType,4)+"-";
        str+=randomstring(CharType,4);
        return str;
    }
vector<string> ClsUtil::randomKeys(enCharType CharType,short NumberOfKey){
    vector<string>vKeys;
    for (short i = 0; i < NumberOfKey; i++){
        vKeys.push_back(randomKey(CharType));
    }
    return vKeys;
}







































