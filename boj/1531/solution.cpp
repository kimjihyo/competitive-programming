#include <iostream>
using namespace std;
int main() {
  int paint[101][101]{};
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    pair<int, int> p1, p2;
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;

    for (int x = p1.first; x <= p2.first; x++) {
      for (int y = p1.second; y <= p2.second; y++) {
        paint[x][y]++;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i < 101; i++) {
    for (int j = 1; j < 101; j++) {
      if (paint[i][j] > m) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
