#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int y = 1;
  int x = 1;

  int dy = -1;
  int dx = 1;

  for (int i = 1; i < n; i++) {
    y += dy;
    x += dx;

    if (y == 0) {
      y += 1;
      dy = 1;
      dx = -1;
    }

    if (x == 0) {
      x += 1;
      dy = -1;
      dx = 1;
    }
  }

  cout << y << '/' << x << '\n';
  return 0;
}