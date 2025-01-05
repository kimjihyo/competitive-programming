#include <iostream>
using namespace std;

int factorial(int n) {
  int ret = 1;
  for (int i = 2; i < n + 1; i++) {
    ret *= i;
  }
  return ret;
}

int main() {
  int a, b;
  cin >> a >> b;
  int ans = factorial(a) / factorial(b) / factorial(a - b);
  cout << ans << '\n';
  return 0;
}
