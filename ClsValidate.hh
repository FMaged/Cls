#pragma once
#include <iostream>
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
static int readIntNumberBetween(short From,short To);
static double readDblNumber();
static double readDblNumberBetween(double From, double To);
static char readChar();
static string readString();




};