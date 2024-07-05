#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    stack<char> s;
    string str;

    cin >> str;

    bool isVps = true;

    for (auto c : str) {
      if (c == '(') {
        s.push('c');
      } else if (!s.empty()) {
        s.pop();
      } else {
        isVps = false;
        break;
      }
    }

    if (isVps && s.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}