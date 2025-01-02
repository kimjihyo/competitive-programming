#include <iostream>
using namespace std;
int main() {
  long long a, b, v, ans = 1;
  cin >> a >> b >> v;
  v -= a;
  a -= b;
  ans += v / a + (v % a == 0 ? 0 : 1);
  cout << ans << '\n';

  return 0;
}
