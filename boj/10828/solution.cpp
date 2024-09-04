#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<int> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (str == "push") {
      int value;
      cin >> value;
      s.push(value);
    } else if (str == "pop") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else if (str == "size") {
      cout << s.size() << '\n';
    } else if (str == "empty") {
      cout << s.empty() << '\n';
    } else if (str == "top") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
      }
    }
  }
  return 0;
}