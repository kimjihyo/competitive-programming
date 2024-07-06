#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    q.push(i + 1);
  }
  int i = 1;
  cout << '<';
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (i % k != 0) {
      q.push(cur);
    } else {
      cout << cur;
      if (!q.empty()) {
        cout << ", ";
      }
    }
    i++;
  }
  cout << ">\n";
  return 0;
}