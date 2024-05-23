#pragma once

#include <iostream>
#include <vector>

using namespace std;

class ClsUtil{
public:

enum enCharType{SmallLetter=1,CapitalLetter=2,Digital=3,SpecialCharacter=4,MixLetter=5,MixKey=6};
static void Srand();
static int randomNumber();
static int randomNumber(int From,int To);
static char randomCharacter(enCharType CharType=enCharType::SmallLetter);
static string randomstring(enCharType CharType, short Length);
static string randomKey(enCharType CharType);
static vector<string> randomKeys(enCharType CharType,short NumberOfKeys);



























};

