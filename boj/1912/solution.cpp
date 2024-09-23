#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  long long ans;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> dp(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  dp[0] = arr[0];
  ans = arr[0];
  for (int i = 1; i < n; i++) {
    long long a = arr[i] + arr[i - 1];
    long long b = dp[i - 1] + arr[i];
    dp[i] = max(a, b);
    dp[i] = max(dp[i], arr[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}