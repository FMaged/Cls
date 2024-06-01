#pragma once
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;


class ClsValidate{
public:

static bool isNumberBetween(short Number,short From,short To);
static bool isNumberBetween(int Number,short From, short To);
static bool isNumberBetween(double Number,short From, short To);
static bool isNumberBetween(float Number,short From, short To);
static int readIntNumber();
static int readIntNumberBetween(short From,short To,string ErrorMessage="Number is not within range, Enter again:");
static double readDblNumber();
static double readDblNumberBetween(double From, double To,string ErrorMessage="Number is not within range, Enter again:");
static char readChar();
static char readY_OR_N(char Yes='Y',char No='N');
static string readString();




};