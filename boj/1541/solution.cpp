#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;

  int num = 0;
  int ans = 0;
  int op = 1;
  for (auto ch : str) {
    int digit = ch - '0';
    if (digit < 10 && digit > -1) {
      num = num * 10 + digit;
    } else {
      ans = ans + num * op;
      if (ch == '+') {
        //
      } else if (ch == '-') {
        op = -1;
      }
      num = 0;
    }
  }

  ans = ans + num * op;

  cout << ans << '\n';
  return 0;
}