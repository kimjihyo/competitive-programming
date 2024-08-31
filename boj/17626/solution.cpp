#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int dp[50'001]{};
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    for (int j = 1; j <= sqrt(i); j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}