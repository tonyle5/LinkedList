/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #1
 * Date: Jan 13, 2024
 * Description: This is the implementation file for a utility file.
 */

#include "myUtil.h"

void getNumber(const char prompt[], const char errorMsg[], int from, int to,
               int& num) {
  cout << prompt;
  cin >> num;
  while (cin.fail() || cin.peek() != '\n' || num < from || num > to) {
    cout << errorMsg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> num;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void getNumber(const char prompt[], const char errorMsg[], double from,
               double to, double& num) {
  cout << prompt;
  cin >> num;
  while (cin.fail() || num < from || num > to) {
    cout << errorMsg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> num;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
