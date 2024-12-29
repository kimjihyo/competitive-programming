#include <iostream>
using namespace std;
int main() {
  long long n, a = 6, i = 1, ans = 1;
  cin >> n;
  while (n > 1) {
    ans++;
    n -= a * i++;
  }
  cout << ans << '\n';
  return 0;
}
