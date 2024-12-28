#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  bool prime[1001]{};
  fill(prime, prime + 1001, true);
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i < 1001; i++) {
    if (!prime[i]) {
      continue;
    }
    for (int j = 2; j * i < 1001; j++) {
      prime[j * i] = false;
    }
  }
  int t = 0, ans = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    if (prime[n]) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
