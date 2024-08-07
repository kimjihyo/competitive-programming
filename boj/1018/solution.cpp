#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

char board[50][50];
int n, m;

int count(int si, int sj) {
  int w = 0, b = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0) {
        if (board[i + si][j + sj] == 'B') {
          w++;
        } else {
          b++;
        }
      } else {
        if (board[i + si][j + sj] == 'W') {
          w++;
        } else {
          b++;
        }
      }
    }
  }
  return min(w, b);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      board[i][j] = str[j];
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < n - 7; i++) {
    for (int j = 0; j < m - 7; j++) {
      ans = min(ans, count(i, j));
    }
  }
  cout << ans << '\n';
  return 0;
}