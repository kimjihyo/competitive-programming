#include <iostream>
#define R 1'000'000'007
using namespace std;

int main() {
  int n;
  cin >> n;

  int p1 = 0;
  int p2 = 1;

  for (int i = 2; i < n + 1; i++) {
    int temp = p2;
    p2 = (p1 + p2) % R;
    p1 = temp;
  }

  cout << p2 << '\n';

  return 0;
}