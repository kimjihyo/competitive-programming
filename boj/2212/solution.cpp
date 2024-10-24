#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}

int main() {
  int n, k;
  cin >> n >> k;
  k = min(n, k);
  vector<int> arr(n);
  vector<int> gaps;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  for (int i = 1; i < n; i++) {
    gaps.push_back(arr[i] - arr[i - 1]);
  }

  sort(gaps.begin(), gaps.end());

  int total = arr[n - 1] - arr[0];
  for (int i = 0; i < k - 1; i++) {
    total -= gaps.back();
    gaps.pop_back();
  }
  cout << total << '\n';

  return 0;
}
