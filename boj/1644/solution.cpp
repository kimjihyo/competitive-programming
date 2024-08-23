#include <iostream>
#include <vector>
using namespace std;

int n;
bool memo[4'000'001]{};
vector<int> primes;
vector<int> sums;

int main() {
  cin >> n;
  memo[0] = false;
  memo[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!memo[i]) {
      for (int j = i * 2; j <= n; j += i) {
        memo[j] = true;
      }
      primes.push_back(i);
    }
  }

  sums.resize(primes.size() + 1);

  sums[0] = 0;
  for (int i = 0; i < primes.size(); i++) {
    sums[i + 1] = primes[i] + sums[i];
  }
  // for (auto p : primes) {
  //   cout << p << ' ';
  // }
  // cout << '\n';
  // for (auto s : sums) {
  //   cout << s << ' ';
  // }
  // cout << '\n';
  int ans = 0;
  int left = 0, right = 1;
  while (left < right && right < sums.size()) {
    int sum = sums[right] - sums[left];
    // cout << right << ' ' << left << ' ' << sum << '\n';
    if (sum == n) {
      ans++;
      right++;
    } else if (sum > n) {
      left++;
    } else {
      right++;
    }
  }
  cout << ans << '\n';

  // cout << '\n';
  // int ans = 0;
  // for (int i = sums.size() - 1; i > 0; i--) {
  //   if (sums[i] == n) {
  //     ans++;
  //   } else {
  //     for (int j = i - 1; j > -1; j--) {
  //       if (sums[i] - sums[j] == n) {
  //         ans++;
  //         break;
  //       }
  //     }
  //   }
  // }
  // cout << ans << '\n';
  return 0;
}