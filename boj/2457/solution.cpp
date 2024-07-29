#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long long ans = 0;
  for (int i = 0; i < 5; i++) {
    int val;
    cin >> val;
    ans += (long long)pow(val, 2);
    ans %= 10;
  }
  cout << ans << '\n';
  return 0;
}