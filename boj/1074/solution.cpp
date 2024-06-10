#include <cmath>
#include <iostream>
using namespace std;

int r, c;
long long ans = 0;

void func(int n, int i, int offsetY, int offsetX) {
  if (n == 1) {
    // cout << offsetY << ' ' << offsetX << ' ' << ans << '\n';
    // cout << offsetY << ' ' << offsetX + 1 << ' ' << ans + 1 << '\n';
    // cout << offsetY + 1 << ' ' << offsetX << ' ' << ans + 2 << '\n';
    // cout << offsetY + 1 << ' ' << offsetX + 1 << ' ' << ans + 3 << '\n';

    if (r == offsetY && c == offsetX) {
      cout << ans << '\n';
    }
    if (r == offsetY && c == offsetX + 1) {
      cout << ans + 1 << '\n';
    }
    if (r == offsetY + 1 && c == offsetX) {
      cout << ans + 2 << '\n';
    }
    if (r == offsetY + 1 && c == offsetX + 1) {
      cout << ans + 3 << '\n';
    }
    ans += 4;
    return;
  }

  func(n - 1, i + pow(2, n) * 0, offsetY, offsetX);
  func(n - 1, i + pow(2, n) * 1, offsetY, offsetX + pow(2, n - 1));
  func(n - 1, i + pow(2, n) * 2, offsetY + pow(2, n - 1), offsetX);
  func(n - 1, i + pow(2, n) * 3, offsetY + pow(2, n - 1),
       offsetX + pow(2, n - 1));
}

int main() {
  int n;
  cin >> n >> r >> c;
  func(n, 0, 0, 0);

  return 0;
}
