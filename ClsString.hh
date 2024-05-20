#pragma once
#include <vector>
#include "ClsValidate.hh"

class ClsString {
string _value;




public:
ClsString();
ClsString(string S);
void setValue(string S);
string getValue();

static string upperAllString(string S);
void upperAllString();
static string lowerAllString(string S);
void lowerAllString();
static char invertLetterCase(char C);
static string invertAllLetterCase(string S);
void invertAllLetterCase();
static short countCapitalLetter(string S);
short countCapitalLetter();
static short countSmallLetter(string S);
short countSmallLetter();
static short countLetterInString(string S,char C);
short countLetterInString(char C);
static short countLetter(string S, char C, bool MatchCase = 1);
short countLetter( char C, bool MatchCase = 1);
static string upperFirstLetterOfEachWord(string S);         //if ".ahmen kaled"==>".ahmed Khaled"!!!!
void upperFirstLetterOfEachWord();
static string lowerFirstLetterOfEachWord(string S);         //if ".John Week"==> ".John week"!!!!!
void lowerFirstLetterOfEachWord();
static bool isVowel(char C);
static int countVowel(string S);
int countVowel();
static void printEachWordInString(string S,string Delimiter=" ");
void printEachWordInString();
static int countWordsInString(string S,string Delimiter=" ");  //Always Add the Delimiter
int countWordsInString(string Delimiter=" ");
static vector<string> splitString(string S,string Delimiter=" ");
vector<string> splitString(string Delimiter=" ");
static string joinString(vector<string>vec,string Delimiter=" ");
void joinStringToValue(vector<string>vec,string Delimiter=" ");
static string joinString(string arr[],int size,string Delimiter=" ");
void joinStringToValue(string arr[],int size,string Delimiter=" ");
static string trimLeft(string S);
void trimLeft();
static string trimRight(string S);
void trimRight();
static string trim(string S);
void trim();
static string reverseWordInString(string S);
void  reverseWordInString();
static string replaceWordInString(string S,string wordToReplace, string replaceTo,bool MatchCase=1);
void replaceWordInString(string wordToReplace, string replaceTo,bool MatchCase=1);







};