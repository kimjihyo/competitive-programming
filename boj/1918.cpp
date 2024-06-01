#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;
  stack<char> s;
  map<char, int> m;
  m.insert({'+', 1});
  m.insert({'-', 1});
  m.insert({'*', 2});
  m.insert({'/', 2});
  m.insert({'(', 0});

  for (char c : input) {
    if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (!s.empty()) {
        if (s.top() == '(') {
          s.pop();
          break;
        } else {
          cout << s.top();
          s.pop();
        }
      }
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      while (!s.empty() && m.find(c)->second <= m.find(s.top())->second) {
        cout << s.top();
        s.pop();
      }
      s.push(c);
    } else {
      cout << c;
    }
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << '\n';
  return 0;
}