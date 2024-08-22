#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> arr;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    arr.push_back(value);
  }
  sort(arr.begin(), arr.end());
  ll ans1, ans2, ans3;
  ll sum = LONG_LONG_MAX;
  for (int i = 0; i < n - 2; i++) {
    ll n1 = arr[i];
    int left = i + 1;
    int right = n - 1;
    sum = min(sum, abs(arr[left] + arr[right] + n1));
    if (abs(arr[left] + arr[right] + n1) == sum) {
      ans1 = n1;
      ans2 = arr[left];
      ans3 = arr[right];
    }
    while (left < right - 1) {
      ll l = arr[left + 1] + arr[right] + n1;
      ll r = arr[left] + arr[right - 1] + n1;
      sum = min(sum, min(abs(l), abs(r)));

      if (sum == abs(l)) {
        ans1 = n1;
        ans2 = arr[left + 1];
        ans3 = arr[right];
      } else if (sum == abs(r)) {
        ans1 = n1;
        ans2 = arr[left];
        ans3 = arr[right - 1];
      }

      if (abs(l) < abs(r)) {
        left++;
      } else {
        right--;
      }
    }
  }
  cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
  return 0;
}