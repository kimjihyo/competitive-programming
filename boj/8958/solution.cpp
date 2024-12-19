#include <iostream>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int increment = 1;
    int ans = 0;
    for (auto c : str) {
      if (c == 'O') {
        ans += increment++;
      } else {
        increment = 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
