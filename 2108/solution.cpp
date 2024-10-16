#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<pair<int, int>> occrs;
  unordered_map<int, int> dict;
  long double sum = 0;
  int max_value = INT_MIN;
  int min_value = INT_MAX;
  pair<int, int> ocr = {0, 0};

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    sum += val;
    arr[i] = val;
    auto it = dict.find(val);
    if (it == dict.end()) {
      dict.insert({val, 1});
      if (occrs.size() == 0) {
        occrs.push_back({val, 1});
      } else if (occrs.back().second == 1) {
        occrs.push_back({val, 1});
      }
    } else {
      it->second++;
      if (it->second > occrs.back().second) {
        occrs.clear();
        occrs.push_back({it->first, it->second});
      } else if (it->second == occrs.back().second) {
        occrs.push_back({it->first, it->second});
      }
    }
  }

  sort(arr.begin(), arr.end());
  sort(occrs.begin(), occrs.end(), comp);

  int mean = round(sum / n);
  cout << (mean == 0.0 ? abs(mean) : mean) << '\n';
  cout << arr[arr.size() / 2] << '\n';
  if (occrs.size() == 1) {
    cout << occrs.back().first << '\n';
  } else {
    cout << occrs[1].first << '\n';
  }
  cout << arr[arr.size() - 1] - arr[0] << '\n';
  return 0;
}