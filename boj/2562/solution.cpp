#include <iostream>
using namespace std;

int main() {
  int ans1 = -1;
  int ans2;
  for (int i = 0; i < 9; i++) {
    int val;
    cin >> val;
    if (val > ans1) {
      ans1 = val;
      ans2 = i + 1;
    }
  }
  cout << ans1 << '\n' << ans2 << '\n';
  return 0;
}