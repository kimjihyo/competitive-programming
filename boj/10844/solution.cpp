#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
  for (int i = 1; i < 10; i++) {
    dp[1][i] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= 1000000000;
      } else if (j == 9) {
        dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j - 1] %= 1000000000;
      } else {
        dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j - 1] %= 1000000000;
        dp[i + 1][j + 1] %= 1000000000;
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j < 10; j++) {
    ans += dp[n][j];
    ans %= 1000000000;
  }
  cout << ans << '\n';
  return 0;
}