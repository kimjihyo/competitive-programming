#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 400 == 0) {
    cout << 1 << '\n';
  } else if (n % 100 == 0) {
    cout << 0 << '\n';
  } else if (n % 4 == 0) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }

  return 0;
}
