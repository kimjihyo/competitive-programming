#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string str;
  cin >> str;
  sort(str.begin(), str.end(), greater<char>());
  int sum = 0;
  bool hasZero = false;
  for (auto c : str) {
    int n = c - '0';
    if (n == 0) {
      hasZero = true;
    } else {
      sum+=n;
    }
  }
  if (!hasZero || sum % 3 != 0) {
    cout << -1 << '\n';
  } else {
    cout << str << '\n';
  }
}