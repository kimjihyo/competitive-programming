#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  vector<int> arr;
  vector<int> cnt(10, 0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    arr.push_back(value);
  }

  int left = 0, right = 0, ntypes = 0, ans = 0;

  while (right < n) {
    if (cnt[arr[right]]++ == 0) {
      ntypes++;
    }
    while (ntypes > 2) {
      if (--cnt[arr[left]] == 0) {
        ntypes--;
      }
      left++;
    }
    // cout << left << ' ' << right << '\n';
    ans = max(ans, right - left + 1);
    right++;
  }
  cout << ans << '\n';
  return 0;
}
