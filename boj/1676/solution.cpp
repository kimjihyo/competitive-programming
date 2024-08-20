#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = n / 5 + n / 25 + n / 125;
  cout << ans << '\n';
  return 0;
}