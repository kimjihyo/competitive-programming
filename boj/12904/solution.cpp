#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  while (a.size() != b.size()) {
    if (b.back() == 'A') {
      b.pop_back();
    } else {
      b.pop_back();
      reverse(b.begin(), b.end());
    }
  }
  if (a == b) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}