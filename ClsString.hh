#pragma once
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








};