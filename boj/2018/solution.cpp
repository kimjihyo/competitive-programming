#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;

  long long l = 1;
  long long r = 1;
  long long sum = 1;
  int ans = 0;
  while (l <= r) {
    if (sum < n) {
      r++;
      sum += r;
    } else if (sum > n) {
      sum -= l;
      l++;
    } else {
      ans++;
      sum -= l;
      l++;
    }
  }
  cout << ans << '\n';
  return 0;
}
