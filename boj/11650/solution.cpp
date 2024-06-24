#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  vector<pair<int, int>> arr;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
  }

  sort(arr.begin(), arr.end(), compare);

  for (auto e : arr) {
    cout << e.first << ' ' << e.second << '\n';
  }
  return 0;
}