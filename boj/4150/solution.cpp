#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string add(string &a, string &b) {
  if (a.size() < b.size()) {
    a.append(b.size() - a.size(), '0');
  }

  int carry = 0;
  string res = "";
  for (int i = 0; i < a.size(); i++) {

    int n1 = a[i] - '0';
    int n2 = 0;
    if (i < b.size()) {
      n2 = b[i] - '0';
    }
    int s = n1 + n2 + carry;
    res.push_back((s % 10) + '0');
    carry = s / 10;
  }
  if (carry != 0) {
    res.push_back('1');
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  string a = "0";
  string b = "1";
  string c;

  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  for (int i = 2; i < n + 1; i++) {
    c = add(a, b);
    a = b;
    b = c;
  }

  reverse(c.begin(), c.end());
  cout << c << '\n';

  return 0;
}
