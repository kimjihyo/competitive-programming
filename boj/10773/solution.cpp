#include <iostream>
#include <stack>
using namespace std;
int main() {
  int n;
  cin >> n;
  stack<int> s;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    if (value == 0) {
      s.pop();
    } else {
      s.push(value);
    }
  }
  int sum = 0;
  while (!s.empty()) {
    sum += s.top();
    s.pop();
  }
  cout << sum << '\n';
  return 0;
}
