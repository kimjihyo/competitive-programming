#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = n % 5;
  if (a % 2 == 0) {
    int ans = n / 5;
    n %= 5;
    ans += n / 2;
    cout << ans << '\n';
  } else if (n > 4) {
    int ans = n / 5;
    ans--;
    n %= 5;
    n += 5;
    if (n % 2 != 0) {
      cout << -1 << '\n';
    } else {
      ans += n / 2;
      cout << ans << '\n';
    }
  } else {
    if (n % 2 == 0) {
      cout << n / 2 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}