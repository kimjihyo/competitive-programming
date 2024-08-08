#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool test(string str) {
  stack<char> s;
  for (auto c : str) {
    if (c == '(' || c == '[') {
      s.push(c);
    } else if (c == ')') {
      if (s.empty())
        return false;
      auto opening = s.top();
      s.pop();
      if (opening != '(') {
        return false;
      }
    } else if (c == ']') {
      if (s.empty())
        return false;
      auto opening = s.top();
      s.pop();
      if (opening != '[') {
        return false;
      }
    }
  }
  return s.empty();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    string str;
    getline(cin, str);
    if (str == ".") {
      break;
    }
    auto result = test(str);
    if (result)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}