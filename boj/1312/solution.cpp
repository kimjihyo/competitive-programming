#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int a, b, n, q = 0;
  cin >> a >> b >> n;
  int i = 0;
  while (a % b != 0) {
    if (a < b) {
      i++;
      a *= 10;
    }
    q = a / b;
    a = a % b;
    if (i == n) {
      break;
    }
    if (a == 0) {
      q = 0;
      break;
    }
  }
  cout << q << '\n';
  return 0;
}
