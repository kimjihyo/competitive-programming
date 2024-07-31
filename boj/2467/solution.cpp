#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int arr[100'000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int left = 0, right = n - 1;
  int sum = abs(arr[left] + arr[right]);
  int ans1 = arr[left], ans2 = arr[right];
  while (right - left > 1) {
    int tmp1 = abs(arr[left] + arr[right - 1]);
    int tmp2 = abs(arr[left + 1] + arr[right]);
    sum = min(sum, min(tmp1, tmp2));
    if (sum == tmp1) {
      ans1 = arr[left];
      ans2 = arr[right - 1];
    }
    if (sum == tmp2) {
      ans1 = arr[left + 1];
      ans2 = arr[right];
    }
    if (abs(tmp1) < abs(tmp2)) {
      right--;
    } else {
      left++;
    }
  }
  cout << ans1 << ' ' << ans2 << '\n';
  return 0;
}
