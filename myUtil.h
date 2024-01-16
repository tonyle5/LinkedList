/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #1
 * Date: Jan 13, 2024
 * Description: This is the header file for a utility file, which contains
 * common functions, constants, and libraries.
 */

#ifndef _MYUTIL_
#define _MYUTIL_

#include <cfloat>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const int ERROR = -1;

const int STR_SIZE = 101;

// This function reads an input from the user and validates if the number is
// an integer and within a range.
void getNumber(const char prompt[], const char errorMsg[], int from, int to,
               int& num);

// This function reads an input from the user and validates if the number is
// a double and within a range.
void getNumber(const char prompt[], const char errorMsg[], double from,
               double to, double& num);

#endif
