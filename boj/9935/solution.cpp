#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  string estr;

  deque<int> idx;
  stack<char> res;

  cin >> str >> estr;

  for (auto c : str) {
    if (!idx.empty() && c == estr[idx.back() + 1]) {
      if (c == estr[estr.size() - 1]) {
        for (int i = 0; i < estr.size() - 1; i++) {
          idx.pop_back();
        }
      } else {
        idx.push_back(idx.back() + 1);
      }
    } else if (c == estr[0]) {
      if (estr.size() != 1) {
        idx.push_back(0);
      }
    } else {
      while (!idx.empty()) {
        res.push(estr[idx.front()]);
        idx.pop_front();
      }
      res.push(c);
    }
  }
  while (!idx.empty()) {
    res.push(estr[idx.front()]);
    idx.pop_front();
  }
  if (res.size() == 0) {
    cout << "FRULA\n";
  } else {
    string resstr = "";
    while (!res.empty()) {
      resstr.push_back(res.top());
      res.pop();
    }
    reverse(resstr.begin(), resstr.end());
    cout << resstr << '\n';
  }
  return 0;
}