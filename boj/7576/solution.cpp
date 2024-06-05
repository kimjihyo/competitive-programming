#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int arr[1'000][1'000];
vector<pair<int, int>> pos;
pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void printArr() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
}

void bfs() {
  queue<pair<int, int>> q;
  for (auto p : pos) {
    q.push({p.first, p.second});
  }
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto d : dirs) {
      pair<int, int> v = {d.first + u.first, d.second + u.second};
      if (v.first > -1 && v.first < n && v.second > -1 && v.second < m) {
        if (arr[v.first][v.second] == 0) {
          arr[v.first][v.second] = arr[u.first][u.second] + 1;
          q.push({v.first, v.second});
        }
      }
    }
  }
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        pos.push_back({i, j});
      }
    }
  }
  bfs();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        cout << -1 << '\n';
        return 0;
      } else {
        ans = max(ans, arr[i][j] - 1);
      }
    }
  }

  cout << ans << '\n';
  return 0;
}