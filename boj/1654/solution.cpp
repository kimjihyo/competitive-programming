#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, n, ans;
  vector<int> arr;
  cin >> k >> n;
  arr.resize(k);
  for (int i = 0; i < k; i++)
    cin >> arr[i];
  ans = *max_element(arr.begin(), arr.end());

  long long left = 1, right = ans;
  while (left <= right) {
    long long mid = (left + right) / 2;
    int total = 0;
    for (auto e : arr) {
      total += e / mid;
    }
    if (total < n) {
      right = mid - 1;
    } else {
      ans = mid;
      left = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}