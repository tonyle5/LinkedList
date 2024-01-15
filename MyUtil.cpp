#include "MyUtil.h"

void getNumber(const char prompt[], const char errorMsg[], int& num) {
  cout << prompt;
  cin >> num;
  while (cin.fail()) {
    cout << errorMsg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> num;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void getNumber(const char prompt[], const char errorMsg[], double& num) {
  cout << prompt;
  cin >> num;
  while (cin.fail()) {
    cout << errorMsg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> num;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
