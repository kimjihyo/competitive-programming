#include <iostream>
#include <string>
using namespace std;

bool is_number(const string &str) {
  for (char c : str) {
    int num = c - '0';
    if (num < 0 || num > 9) {
      return false;
    }
  }
  return true;
}

int main() {
  int idx = 0;
  for (int i = 0; i < 3; i++) {
    string input;
    cin >> input;
    if (is_number(input)) {
      idx = stoi(input) - i;
    }
  }
  idx += 3;

  if (idx % 3 == 0 && idx % 5 == 0) {
    cout << "FizzBuzz\n";
  } else if (idx % 3 == 0) {
    cout << "Fizz\n";
  } else if (idx % 5 == 0) {
    cout << "Buzz\n";
  } else {
    cout << idx << '\n';
  }

  return 0;
}
