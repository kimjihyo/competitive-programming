#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
  bool operator()(int a, int b) { return a > b; }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, compare> pq;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (val == 0) {
      if (pq.empty()) {
        cout << 0 << '\n';
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      pq.push(val);
    }
  }
  return 0;
}