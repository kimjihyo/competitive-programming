#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int arr[100][100]{};
pair<int, int> dirs[4]{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

bool melt() {
  bool ret = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] > 2) {
        ret = false;
        arr[i][j] = 4;
      } else if (arr[i][j] < 3) {
        arr[i][j] = 0;
      } else {
        arr[i][j] = 0;
      }
    }
  }
  return ret;
}

void bfs() {
  queue<pair<int, int>> q;
  bool visited[100][100]{};
  visited[0][0] = true;
  q.push({0, 0});
  while (!q.empty()) {
    pair<int, int> here = q.front();
    q.pop();
    for (pair<int, int> dir : dirs) {
      pair<int, int> there = {here.first + dir.first, here.second + dir.second};
      if (there.first < 0 || there.second < 0 || there.first > n - 1 ||
          there.second > m - 1)
        continue;
      if (!visited[there.first][there.second] &&
          arr[there.first][there.second] == 0) {
        visited[there.first][there.second] = true;
        q.push({there.first, there.second});
      } else if (arr[there.first][there.second] > 0) {
        arr[there.first][there.second]--;
      }
    }
  }
}

int main() {
  int cnt, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] > 0) {
        cnt++;
        arr[i][j] = 4;
      }
    }
  }
  while (!melt()) {
    bfs();
    ans++;
  }
  cout << ans << '\n';
  return 0;
}