#include <cmath>
#include <iostream>
using namespace std;

int power(int a, int b) {
  if (b == 0)
    return 1;
  if (b % 2 != 0) {
    return (power(a, b - 1) * a) % 1000000007;
  }
  int num = power(a, b / 2) % 1000000007;
  return num * num % 1000000007;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 5 << '\n';
    } else {
      cout << (20 * power(5, n - 2)) % 1000000007 << '\n';
    }
  }

  return 0;
}
