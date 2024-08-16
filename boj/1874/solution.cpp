#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<int> s;
  vector<char> v;
  bool failed = false;

  int current = 1;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;

    if (input > current) {
      while (input != current) {
        s.push(current++);
        v.push_back('+');
      }
      v.push_back('+');
      v.push_back('-');
      current++;
    } else if (input < current) {
      while (!s.empty() && s.top() != input) {
        s.pop();
        v.push_back('-');
      }
      if (s.empty()) {
        failed = true;
      } else {
        s.pop();
        v.push_back('-');
      }
    } else if (input == current) {
      v.push_back('+');
      v.push_back('-');
      current++;
    }
  }
  if (failed) {
    cout << "NO\n";
  } else {
    for (auto it : v) {
      cout << it << '\n';
    }
  }

  return 0;
}