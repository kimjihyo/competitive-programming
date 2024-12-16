#include <iostream>
using namespace std;
int main() {
  int h, m;
  cin >> h >> m;

  h--;
  m += 15;
  if (m >= 60) {
    m -= 60;
    h++;
  }

  if (h == -1) {
    h = 23;
  }

  cout << h << ' ' << m << '\n';

  return 0;
}
