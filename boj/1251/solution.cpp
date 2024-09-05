#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;
  string sub1 = input.substr(0, 1);
  int size1 = 1;
  for (int i = 1; i < input.size() - 1; i++) {
    string s = input.substr(0, i);
    reverse(s.begin(), s.end());
    if (sub1 > s) {
      sub1 = s;
      size1 = i;
    }
  }

  string sub2 = input.substr(size1, 1);
  int size2 = 1;

  for (int i = 1; i < input.size() - size1; i++) {
    string s = input.substr(size1, i);
    reverse(s.begin(), s.end());
    if (sub2 > s) {
      sub2 = s;
      size2 = i;
    }
  }

  string sub3 = input.substr(size1 + size2, input.size() - size1 - size2);
  reverse(sub3.begin(), sub3.end());

  // cout << sub1 << '\n';
  // cout << sub2 << '\n';
  // cout << sub3 << '\n';
  cout << sub1 + sub2 + sub3 << '\n';
  return 0;
}