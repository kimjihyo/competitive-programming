#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, t = 0;
  int dp[100][10'001]{};
  int bytes[100]{};
  int costs[100]{};
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> bytes[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
    t += costs[i];
  }
  int c = costs[0], b = bytes[0];
  for (int j = 0; j < t + 1; j++) {
    if (j < c) {
      dp[0][j] = 0;
    } else {
      dp[0][j] = b;
    }
  }

  int ans = t;
  for (int i = 1; i < n; i++) {
    c = costs[i], b = bytes[i];
    for (int j = 0; j < t + 1; j++) {
      if (j >= c) {
        int tmp = dp[i - 1][j - c] + b;
        if (tmp > dp[i - 1][j]) {
          dp[i][j] = tmp;
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      } else {
        dp[i][j] = dp[i - 1][j];
      }
      if (dp[i][j] >= m && j < ans) {
        ans = j;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}