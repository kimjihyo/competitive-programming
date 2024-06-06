#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct position {
  int x, y, z;
};

int m, n, h;
int arr[100][100][100];
vector<position> pos;
position dirs[6] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                    {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};

void bfs() {
  queue<position> q;
  for (auto p : pos) {
    q.push(p);
  }
  while (!q.empty()) {
    position u = q.front();
    q.pop();
    for (auto d : dirs) {
      position v = {d.x + u.x, d.y + u.y, d.z + u.z};
      if (v.x < h && v.x > -1 && v.y < n && v.y > -1 && v.z < m && v.z > -1) {
        if (arr[v.x][v.y][v.z] == 0) {
          arr[v.x][v.y][v.z] = arr[u.x][u.y][u.z] + 1;
          q.push({v.x, v.y, v.z});
        }
      }
    }
  }
}

int main() {
  cin >> m >> n >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> arr[i][j][k];
        if (arr[i][j][k] == 1) {
          pos.push_back({i, j, k});
        }
      }
    }
  }
  bfs();
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (arr[i][j][k] == 0) {
          cout << -1 << '\n';
          return 0;
        }
        ans = max(ans, arr[i][j][k]);
      }
    }
  }
  cout << ans - 1 << '\n';
  return 0;
}