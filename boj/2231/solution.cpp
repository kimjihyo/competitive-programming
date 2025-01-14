#include <climits>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int j = i;
    int sum = j;
    while (j > 0) {
      sum += j % 10;
      j /= 10;
    }
    if (sum == n) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
  return 0;
}