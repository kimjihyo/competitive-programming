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
  vector<string> arr(n + 1);

  arr[0] = "0";
  arr[1] = "1";

  for (int i = 2; i < n + 1; i++) {
    arr[i] = add(arr[i - 1], arr[i - 2]);
  }

  string ans = arr[n];
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';

  return 0;
}
