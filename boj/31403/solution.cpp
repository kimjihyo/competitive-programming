#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c;
  // cout << pow(10, log10(b)) << '\n';
  cout << a + b - c << '\n';

  a *= pow(10, (int)log10(b) + 1);
  a += b;
  a -= c;
  cout << a << '\n';

  return 0;
}
