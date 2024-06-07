#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[50][50]{};
bool visited[50][50]{};
pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void print(int m, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j]) {
        cout << '*' << ' ';
      } else {
        cout << arr[i][j] << ' ';
      }
    }
    cout << "\n";
  }
  cout << '\n';
}
void resetArr(int m, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      arr[i][j] = 0;
      visited[i][j] = false;
    }
  }
}

void bfs(int m, int n, int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = true;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto d : dirs) {
      pair<int, int> v = {d.first + u.first, d.second + u.second};
      if (v.first < n && v.first > -1 && v.second < m && v.second > -1) {
        if (arr[v.first][v.second] == 1 && !visited[v.first][v.second]) {
          visited[v.first][v.second] = true;
          q.push({v.first, v.second});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int m, n, k;
    cin >> m >> n >> k;
    resetArr(m, n);
    vector<pair<int, int>> l;
    for (int j = 0; j < k; j++) {
      int y, x;
      cin >> x >> y;
      arr[y][x] = 1;
      l.push_back({y, x});
    }
    int cnt = 0;
    for (auto p : l) {
      if (!visited[p.first][p.second]) {
        bfs(m, n, p.first, p.second);
        cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}