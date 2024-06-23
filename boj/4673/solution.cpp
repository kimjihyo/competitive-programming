#include <iostream>
using namespace std;

int d(int n) {
  int res = n;
  while (n != 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  bool memo[11'000];
  int n = 1;
  while (n < 10'000) {
    memo[d(n)] = true;
    n++;
  }

  for (int i = 1; i < 10'000; i++) {
    if (!memo[i]) {
      cout << i << '\n';
    }
  }
  return 0;
}