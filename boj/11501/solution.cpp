#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int, int>> pairs;
    queue<pair<int, int>> q;
    long long num = 0;
    long long profit = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      pairs.push_back({i, arr[i]});
    }
    sort(pairs.begin(), pairs.end(), compare);
    q.push(pairs[0]);

    for (int i = 1; i < n; i++) {
      if (q.back().first < pairs[i].first) {
        q.push(pairs[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == q.front().first) {
        profit += num * arr[i];
        q.pop();
        num = 0;
      } else {
        profit -= arr[i];
        num++;
      }
    }
    cout << profit << '\n';
  }
  return 0;
}