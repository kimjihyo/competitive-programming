#include <algorithm>
#include <iostream>
using namespace std;

int n;
int original[10][10];
int board[10][10];
int ans;

bool isPlacable(int y, int x) {
  int originalY = y, originalX = x;

  // left up diagnol
  while (y > -1 && x > -1) {
    if (board[y][x] == 2)
      return false;
    y--;
    x--;
  }

  y = originalY;
  x = originalX;

  // right up diagnol
  while (y > -1 && x < n) {
    if (board[y][x] == 2)
      return false;
    y--;
    x++;
  }

  y = originalY;
  x = originalX;

  // left down diagnol
  while (y < n && x > -1) {
    if (board[y][x] == 2)
      return false;
    y++;
    x--;
  }

  y = originalY;
  x = originalX;

  // right down diagnol
  while (y < n && x < n) {
    if (board[y][x] == 2)
      return false;
    y++;
    x++;
  }
  return true;
}

void dfs(int cnt) {
  bool noMoreLeft = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 1 && isPlacable(i, j)) {
        noMoreLeft = false;
        int tmp = board[i][j];
        board[i][j] = 2;
        dfs(cnt + 1);
        board[i][j] = tmp;
      }
    }
  }

  if (noMoreLeft) {
    ans = max(ans, cnt);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      original[i][j] = board[i][j];
    }
  }

  dfs(0);

  cout << ans << '\n';
  return 0;
}