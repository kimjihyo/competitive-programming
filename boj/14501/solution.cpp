#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int t, p;
    cin >> t >> p;
    if (i + t < n + 1) {
      dp[i + t] = max(dp[i + t], dp[i] + p);
      for (int j = i + t + 1; j < n + 1; j++) {
        dp[j] = max(dp[j], dp[i + t]);
      }
    }
  }
  cout << dp[n] << '\n';
  return 0;
}