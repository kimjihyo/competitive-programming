#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare {
  bool operator()(int a, int b) {
    return a < b;
  }
};

int main() {
  int n;
  cin >> n;
  int me;
  cin >> me;
if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  priority_queue<int, vector<int>, compare> pq;
  for (int i = 0; i < n - 1; i++) {
    int val;
    cin >> val;
    pq.push(val);
  }
  int ans = 0;
  int cur = pq.top();
  while (cur >= me) {
    pq.pop();
    pq.push(cur - 1);
    ans++;
    me++;
    cur = pq.top();
  }
  cout << ans << '\n';
  return 0;
}
