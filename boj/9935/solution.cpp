#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  string str;
  string estr;

  stack<int> idx;

  cin >> str >> estr;

  string res = "";
  for (auto c : str) {
    if (c == estr[0]) {
      idx.push(0);
    } else if (!idx.empty() && c == estr[idx.top() + 1]) {
      if (c == estr[estr.size() - 1]) {
        for (int i = 0; i < estr.size() - 1; i++) {
          idx.pop();
        }
      } else {
        idx.push(idx.top() + 1);
      }
    } else {
      string temp;
      while (!idx.empty()) {
        temp = estr[idx.top()] + temp;
        idx.pop();
      }
      res += temp + c;
    }
  }
  if (res.size() == 0) {
    res = "FRULA";
  }
  cout << res << '\n';
  return 0;
}