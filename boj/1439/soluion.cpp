#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  int zero = 0;
  int one = 0;
  char prevChar = str[0];
  for (int i = 1; i < str.size(); i++) {
    if (str[i] != prevChar && prevChar == '0') {
      one++;
    } else if (str[i] != prevChar && prevChar == '1') {
      zero++;
    }
    prevChar = str[i];
  }

  if (prevChar == '1' && one != 0) {
    zero++;
  } else if (prevChar == '0' && zero != 0) {
    one++;
  }

  // cout << one << ' ' << zero << '\n';
  cout << min(one, zero) << '\n';

  return 0;
}