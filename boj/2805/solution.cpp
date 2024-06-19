#include <iostream>
#include <vector>
using namespace std;

long long calc(vector<int> &arr, int size) {
  long long sum = 0;
  for (auto num : arr) {
    int val = num - size;
    if (val > 0)
      sum += val;
  }
  return sum;
}

int main() {
  vector<int> arr;
  int n, m;
  int longest = -1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
    if (val > longest) {
      longest = val;
    }
  }

  int left = 0;
  int right = longest;
  int ans = -1;

  while (left <= right) {
    int mid = (left + right) / 2;
    long long val = calc(arr, mid);
    if (val < m) {
      right = mid - 1;
    } else if (val > m) {
      ans = mid;
      left = mid + 1;
    } else {
      ans = mid;
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}