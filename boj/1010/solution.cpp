#include <iostream>
using namespace std;
typedef long long ll;

int dp[31][31]{};

int nCr(int n, int r) {
  if (n == r || r == 0)
    return 1;

  if (dp[n][r] != 0)
    return dp[n][r];

  dp[n - 1][r - 1] = nCr(n - 1, r - 1);
  dp[n - 1][r] = nCr(n - 1, r);

  return dp[n - 1][r - 1] + dp[n - 1][r];
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    cin >> n >> m;
    int ans = nCr(m, n);
    cout << ans << '\n';
  }
  return 0;
}