#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int lab[8][8]{};
int vacantSize = 0;
int virusSize = 0;
pair<int, int> vacants[64];
pair<int, int> viruses[64];
bool selected[64];
int ans = 0;

pair<int, int> dirs[4]{
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

int bfs(bool visited[][8], pair<int, int> start) {
  int count = 0;
  queue<pair<int, int>> q;
  q.push(start);
  visited[start.first][start.second] = true;
  while (!q.empty()) {
    pair<int, int> here = q.front();
    q.pop();
    for (auto dir : dirs) {
      pair<int, int> there =
          make_pair(here.first + dir.first, here.second + dir.second);
      if (there.first < n && there.first > -1 && there.second < m &&
          there.second > -1) {
        if (lab[there.first][there.second] == 0) {
          if (!visited[there.first][there.second]) {
            count++;
            visited[there.first][there.second] = true;
            q.push({there.first, there.second});
          }
        }
      }
    }
  }
  return count;
}

void combination(int idx, int cnt) {
  if (cnt == 3) {
    for (int i = 0; i < vacantSize; i++) {
      if (selected[i]) {
        lab[vacants[i].first][vacants[i].second] = 1;
      }
    }

    int sum = 0;
    bool visited[8][8]{};
    for (int i = 0; i < virusSize; i++) {
      sum += bfs(visited, viruses[i]);
    }
    ans = max(vacantSize - 3 - sum, ans);
    for (int i = 0; i < vacantSize; i++) {
      if (selected[i]) {
        lab[vacants[i].first][vacants[i].second] = 0;
      }
    }
    return;
  }

  for (int i = idx; i < vacantSize; i++) {
    selected[i] = true;
    combination(i + 1, cnt + 1);
    selected[i] = false;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> lab[i][j];
      if (lab[i][j] == 0) {
        vacants[vacantSize] = make_pair(i + 0, j + 0);
        selected[vacantSize] = false;
        vacantSize++;
      } else if (lab[i][j] == 2) {
        viruses[virusSize] = make_pair(i + 0, j + 0);
        virusSize++;
      }
    }
  }
  combination(0, 0);
  cout << ans << '\n';
  return 0;
}