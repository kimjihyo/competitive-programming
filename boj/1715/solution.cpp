#include <iostream>
#include <queue>
using namespace std;

struct compare {
  bool operator()(long long a, long long b) { return a > b; }
};

int main() {
  int n;
  cin >> n;

  priority_queue<long long, vector<long long>, compare> q;
  for (int i = 0; i < n; i++) {
    long long val;
    cin >> val;
    q.push(val);
  }
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  long long ans = 0;
  while (!q.empty()) {
    long long a = 0, b = 0;
    a = q.top();
    q.pop();
    if (!q.empty()) {
      b = q.top();
      q.pop();
    }
    ans += a + b;
    if (!q.empty()) {
      q.push(a + b);
    }
  }
  cout << ans << '\n';
  return 0;
}