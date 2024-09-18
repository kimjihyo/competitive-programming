#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int ans = 0, left = 0, right = 1;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  while (left < right && right < n) {
    int len = arr[right] - arr[left];
    if (len + 1 > l) {
      ans++;
      left = right;
      right++;
      if (left == n - 1 && right == n) {
        ans++;
      }
    } else {
      right++;
      if (right == n) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}