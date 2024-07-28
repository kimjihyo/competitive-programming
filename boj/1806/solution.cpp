#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> arr;
  int n, s;
  cin >> n >> s;
  arr.resize(n + 1);
  arr[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  int left = 0, right = 1;
  int ans = 0;
  while (left < n + 1 && right < n + 1) {
    int sum = arr[right] - arr[left];
    if (sum < s) {
      right++;
    } else if (sum > s) {
      int tmp = right - left;
      if (ans == 0 || ans > tmp) {
        ans = tmp;
      }
      left++;
    } else {
      int tmp = right - left;
      if (ans == 0 || ans > tmp) {
        ans = tmp;
      }
      left++;
      right++;
    }
  }

  cout << ans << '\n';

  return 0;
}