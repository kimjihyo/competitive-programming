#include <iostream>
using namespace std;

int main() {
  int a, b;
  int cnt = 0;
  cin >> a >> b;
  while (a < b) {
    if ((b - 1) % 10 == 0) {
      b = (b - 1) / 10;
      cnt++;
    } else if (b % 2 == 0) {
      b = b / 2;
      cnt++;
    } else {
      break;
    }
  }
  if (a == b) {
    cout << cnt + 1 << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}