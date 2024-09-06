#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  vector<int> arr;
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end(), greater<int>());
  int ans = arr[0];
  for (int i = 1; i < n; i++) {
    ans = max(ans, arr[i] * (i + 1));
  }
  cout << ans << '\n';
  return 0;
}