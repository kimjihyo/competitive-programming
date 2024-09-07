#include <algorithm>
#include <iostream>
using namespace std;

bool comp1(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
      pair<int, int> e;
      cin >> e.first >> e.second;
      arr.push_back(e);
    }
    int cnt = 1;
    sort(arr.begin(), arr.end(), comp1);
    int maxOfSecond = arr[0].second;
    for (int i = 1; i < n; i++) {
      if (maxOfSecond > arr[i].second) {
        cnt++;
        maxOfSecond = arr[i].second;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}