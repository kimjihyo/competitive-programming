#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, m;
  int arr[1000][1000];
  int distances[1000][1000];
  pair<int, int> directions[] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  queue<pair<int, int>> q;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      distances[i][j] = -1;
      if (arr[i][j] == 2) {
        distances[i][j] = 0;
        q.push({i, j});
      } else if (arr[i][j] == 0) {
        distances[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto dir : directions) {
      pair<int, int> v = {
          u.first + dir.first,
          u.second + dir.second,
      };
      if (v.first > -1 && v.first < n && v.second > -1 && v.second < m) {
        if (distances[v.first][v.second] == -1 && arr[v.first][v.second] != 0) {
          distances[v.first][v.second] = distances[u.first][u.second] + 1;
          q.push({v.first, v.second});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << distances[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}