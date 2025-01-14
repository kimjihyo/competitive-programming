#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  int bound = round((double)n * 0.15);
  double ans = 0;
  for (int i = bound; i < n - bound; i++) {
    ans += arr[i];
  }
  cout << round(ans / (n - 2 * bound)) << '\n';
  return 0;
}
