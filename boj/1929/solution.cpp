#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  m += 1;
  vector<bool> memo(m, false);
  for (int i = 2; i < m; i++) {
    if (memo[i])
      continue;
    for (int num = i * 2, j = 3; num < m; j++) {
      if (num < m) {
        memo[num] = true;
      }
      num = i * j;
    }
  }
  for (int i = n; i < m; i++) {
    if (!memo[i] && i > 1) {
      cout << i << '\n';
    }
  }
  return 0;
}