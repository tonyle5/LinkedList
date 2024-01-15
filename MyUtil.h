#ifndef _MYUTIL_
#define _MYUTIL_

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const int ERROR = -1;

const int STR_SIZE = 101;

// This function reads an input from the user and validates if the number is
// an integer.
void getNumber(const char prompt[], const char errorMsg[], int& num);

// This function reads an input from the user and validates if the number is
// a double.
void getNumber(const char prompt[], const char errorMsg[], double& num);

#endif
