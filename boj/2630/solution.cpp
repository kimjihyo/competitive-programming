#include <iostream>
using namespace std;

int arr[129][129];

int func(int y, int x, int size, int color) {
  if (size == 1) {
    if (arr[y][x] == color)
      return 1;
    else
      return 0;
  }

  bool check = true;
  for (int i = 0; i < size * size; i++) {
    int col = i / size;
    int row = i % size;
    if (arr[y + col][x + row] != color) {
      check = false;
      break;
    }
  }

  if (check)
    return 1;

  int c1 = func(y, x, size / 2, color);
  int c2 = func(y, x + size / 2, size / 2, color);
  int c3 = func(y + size / 2, x, size / 2, color);
  int c4 = func(y + size / 2, x + size / 2, size / 2, color);
  return c1 + c2 + c3 + c4;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  cout << func(0, 0, n, 0) << '\n';
  cout << func(0, 0, n, 1) << '\n';
  return 0;
}