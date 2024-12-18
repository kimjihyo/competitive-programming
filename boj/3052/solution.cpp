#include <iostream>
using namespace std;
int main() {
  int cnt[41]{};
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    int val;
    cin >> val;
    cnt[val % 42]++;
    if (cnt[val % 42] == 1) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
