#include <cmath>
#include <iostream>
using namespace std;
int n, r, c;
long long ans = 0;

void func(int a, int b, int c) {
  if (a == 1) {
    if (b == 0 && c == 0) {
      cout << ans << '\n';
    } else if (b == 0 && c == 1) {
      cout << ans + 1 << '\n';
    } else if (b == 1 && c == 0) {
      cout << ans + 2 << '\n';
    } else {
      cout << ans + 3 << '\n';
    }
    return;
  }
  int size = pow(2, a);
  // 1
  if (b < size / 2 && c < size / 2) {
    func(a - 1, b, c);
  }
  // 2
  if (b < size / 2 && c >= size / 2) {
    ans += pow(4, a - 1);
    func(a - 1, b, c - pow(2, a - 1));
  }
  // 3
  if (b >= size / 2 && c < size / 2) {
    ans += pow(4, a - 1) * 2;
    func(a - 1, b - pow(2, a - 1), c);
  }
  // 4
  if (b >= size / 2 && c >= size / 2) {
    ans += pow(4, a - 1) * 3;
    func(a - 1, b - pow(2, a - 1), c - pow(2, a - 1));
  }
}

int main() {
  cin >> n >> r >> c;
  func(n, r, c);
  return 0;
}
