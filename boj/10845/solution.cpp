#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (str == "push") {
      int val;
      cin >> val;
      q.push(val);
    }
    if (str == "pop") {
      if (!q.empty()) {
        cout << q.front() << '\n';
        q.pop();
      } else {
        cout << -1 << '\n';
      }
    }
    if (str == "empty") {
      cout << q.empty() << '\n';
    }
    if (str == "size") {
      cout << q.size() << '\n';
    }
    if (str == "front") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
      }
    }
    if (str == "back") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.back() << '\n';
      }
    }
  }
  return 0;
}
