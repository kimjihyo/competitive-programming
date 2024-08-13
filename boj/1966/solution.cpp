#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
  bool operator()(int &a, int &b) { return b > a; }
};

struct PrinterQueue {
  int n;
  queue<pair<int, int>> q;
  priority_queue<int, vector<int>, compare> pq;
  PrinterQueue(int size) { n = size; }

  void enqueue(int id, int priority) {
    q.push({id, priority});
    pq.push(priority);
  }

  int dequeue() {
    auto pqVal = pq.top();
    auto qVal = q.front();
    q.pop();
    pq.pop();

    if (pqVal == qVal.second) {
      return qVal.first;
    } else {
      while (pqVal != qVal.second) {
        q.push(qVal);
        qVal = q.front();
        q.pop();
      }
      return qVal.first;
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, target;
    cin >> n >> target;
    PrinterQueue q = PrinterQueue(n);
    for (int i = 0; i < n; i++) {
      int priority;
      cin >> priority;
      q.enqueue(i, priority);
    }

    int i = 1;
    while (target != q.dequeue()) {
      i++;
    }
    cout << i << '\n';
  }
  return 0;
}