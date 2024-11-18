#include <iostream>
using namespace std;
int main() {
  int a = 1, b = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int prev_a = a;
    int prev_b = b;
    a = b;
    b = prev_a + prev_b;
  }
  cout << a << ' ' << b << '\n';
  return 0;
}
