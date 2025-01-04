#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

int main() {
  int a, b;
  cin >> a >> b;
  int g = gcd(a, b), l = a * b / g;
  cout << g << '\n' << l << '\n';
  return 0;
}
