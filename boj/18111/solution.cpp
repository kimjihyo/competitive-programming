#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, b;
  cin >> n >> m >> b;
  vector<vector<int>> blocks(n, vector<int>(m, 0));
  int highest = -1;
  int lowest = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> blocks[i][j];
      highest = max(highest, blocks[i][j]);
      lowest = min(lowest, blocks[i][j]);
    }
  }
  int anst = INT_MAX;
  int ansl = -1;
  for (int l = lowest; l < highest + 1; l++) {
    int t = 0;
    int cb = b;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        int diff = blocks[y][x] - l;
        if (diff > 0) {
          t += diff * 2;
          cb += diff;
        } else if (diff < 0) {
          t -= diff;
          cb += diff;
        }
      }
    }
    if (cb > -1) {
      anst = min(t, anst);
      if (t == anst) {
        ansl = max(ansl, l);
      }
    }
  }
  cout << anst << ' ' << ansl << '\n';
  return 0;
}
