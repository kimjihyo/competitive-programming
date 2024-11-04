#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int memo[10]{};

  while (n != 0) {
    int num = n % 10;
    n /= 10;
    memo[num]++;

    if (num == 9 && memo[9] > memo[6]) {
      memo[9]--;
      memo[6]++;
    } else if (num == 6 && memo[6] > memo[9]) {
      memo[6]--;
      memo[9]++;
    }
  }

  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if (memo[i] > ans) {
      ans = memo[i];
    }
  }
  cout << ans << '\n';

  return 0;
}
