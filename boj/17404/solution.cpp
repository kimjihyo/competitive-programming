#include <iostream>
using namespace std;

const int MAX = 1000 * 1000;

int min(int a, int b, int c) { return min(a, min(b, c)); }
int min(int a, int b, int c, int d) { return min(a, min(b, c, d)); }

int main() {
  int n;
  int cost[1000][3];
  int ans = MAX;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }

  for (int i = 0; i < 3; i++) {
    int dp[1000][3];
    for (int j = 0; j < 3; j++) {
      if (j == i)
        dp[0][j] = cost[0][j];
      else
        dp[0][j] = MAX;
    }

    for (int j = 1; j < n; j++) {
      dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
      dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
      dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
    }

    for (int j = 0; j < 3; j++) {
      if (i == j)
        dp[n - 1][j] = MAX;
    }

    ans = min(ans, dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
  }
  cout << ans << '\n';
  return 0;
}