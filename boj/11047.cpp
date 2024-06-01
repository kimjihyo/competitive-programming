#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  sort(arr.begin(), arr.end(), greater<int>());

  int i = 0;
  int ans = 0;
  while (k != 0) {
    int a = arr[i];
    ans += k / a;
    k = k % a;
    i++;
  }
  cout << ans << '\n';
  return 0;
}