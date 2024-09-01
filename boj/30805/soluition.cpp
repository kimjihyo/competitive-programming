#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second < b.second;
  }
};

int main() {
  int n;
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  vector<int> arr1(n);
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
    pq.push({i, arr1[i]});
  }
  cin >> n;
  vector<int> arr2(n);
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }
  vector<int> sub;
  int prevIndex = 0;
  int nextIndex = 0;
  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    if (p.first < prevIndex) {
      continue;
    }
    for (int i = nextIndex; i < arr2.size(); i++) {
      if (arr2[i] == p.second) {
        sub.push_back(arr2[i]);
        prevIndex = p.first;
        nextIndex = i + 1;
        break;
      }
    }
  }
  cout << sub.size() << '\n';
  for (auto val : sub) {
    cout << val << ' ';
  }
  cout << '\n';
  return 0;
}