#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    pair<int, int> time;
    cin >> time.first >> time.second;
    arr.push_back(time);
  }
  sort(arr.begin(), arr.end());
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  for (auto e : arr) {
    if (pq.empty()) {
      pq.push(e);
    } else {
      if (pq.top().second > e.first) {
        pq.push(e);
      } else {
        pq.pop();
        pq.push(e);
      }
    }
  }
  cout << pq.size() << '\n';

  return 0;
}