#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long memo[101];
  memo[1] = 1;
  memo[2] = 1;
  memo[3] = 1;
  memo[4] = 2;
  memo[5] = 2;

  for (int i = 6; i < 101; i++) {
    memo[i] = memo[i - 1] + memo[i - 5];
  }

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    cout << memo[n] << '\n';
  }

  return 0;
}