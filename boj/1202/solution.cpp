#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool compareJewerlies(pair<int, int> &a, pair<int, int> &b) {
  return a.first < b.first;
}

struct compare {
  bool operator()(int a, int b) { return a < b; }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> jewerlies(n);
  vector<int> bags(k);
  for (int i = 0; i < n; i++) {
    cin >> jewerlies[i].first >> jewerlies[i].second;
  }
  for (int i = 0; i < k; i++) {
    cin >> bags[i];
  }
  sort(jewerlies.begin(), jewerlies.end(), compareJewerlies);
  sort(bags.begin(), bags.end());
  int i = 0;
  long long ans = 0;
  priority_queue<int, vector<int>, compare> pq;
  for (auto bag : bags) {
    int price = -1;
    for (; i < jewerlies.size(); i++) {
      if (jewerlies[i].first <= bag) {
        pq.push(jewerlies[i].second);
      } else {
        break;
      }
    }
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << '\n';
  return 0;
}