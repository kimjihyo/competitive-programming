#include <iostream>
using namespace std;
int main() {
  int n, m, j;
  cin >> n >> m >> j;

  int pos = m;
  int ans = 0;
  for (int i = 0; i < j; i++) {
    int drop;
    cin >> drop;
    int left = pos - m + 1;
    if (drop < left) {
      ans += left - drop;
      pos = drop + m - 1;
    } else if (drop > pos) {
      ans += drop - pos;
      pos = drop;
    }
  }
  cout << ans << '\n';

  return 0;
}
