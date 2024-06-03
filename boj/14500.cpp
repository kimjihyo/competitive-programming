#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[500][500];
int tetrominoes[7][4][4] = {{
                                {0, 0, 0, 0},
                                {1, 1, 1, 1},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                            },
                            {
                                {1, 1, 0, 0},
                                {1, 1, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                            },
                            {
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 0, 0, 0},
                            },
                            {
                                {0, 1, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {0, 0, 0, 0},
                            },
                            {
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {0, 0, 0, 0},
                            },
                            {
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0},
                                {0, 0, 0, 0},
                            },
                            {
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0},
                                {0, 0, 0, 0},
                            }};

void rotate(int t) {
  int temp[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      temp[i][j] = tetrominoes[t][i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      tetrominoes[t][i][j] = temp[j][3 - i];
    }
  }
}

int sum(int y, int x, int t) {
  int total = 0;
  int offsetX = -1, offsetY = -1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (tetrominoes[t][i][j] != 0) {
        if (offsetX == -1) {
          offsetX = j;
          offsetY = i;
        }
        int u = y + i - offsetY;
        int v = x + j - offsetX;
        if (u < n && v < m) {
          total += arr[u][v];
        }
      }
    }
  }
  return total;
}

void print(int t) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << tetrominoes[t][i][j];
    }
    cout << '\n';
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int t = 0; t < 7; t++) {
        for (int r = 0; r < 4; r++) {
          ans = max(ans, sum(i, j, t));
          rotate(t);
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}