#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long p1, p2;
  p1 = 0;
  p2 = 1;
  for (int i = 2; i < n + 1; i++) {
    long long temp = p2;
    p2 = p1 + p2;
    p1 = temp;
  }
  cout << p2 << '\n';
  return 0;
}