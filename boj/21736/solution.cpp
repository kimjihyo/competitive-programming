#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> campus(n, vector<char>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, int>> q;
  vector<pair<int, int>> dirs;
  dirs.push_back({1, 0});
  dirs.push_back({-1, 0});
  dirs.push_back({0, 1});
  dirs.push_back({0, -1});

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      campus[i][j] = str[j];
      if (campus[i][j] == 'I') {
        q.push({i, j});
        visited[i][j] = true;
      }
    }
  }
  int cnt = 0;
  while (!q.empty()) {
    auto here = q.front();
    q.pop();
    for (auto dir : dirs) {
      pair<int, int> there = {here.first + dir.first, here.second + dir.second};
      // check if there is within the bounary
      if (!(there.first > -1 && there.first < n && there.second > -1 &&
            there.second < m)) {
        continue;
      }
      // check if there is a wall
      if (campus[there.first][there.second] == 'X') {
        continue;
      }
      // check if there has already been visited
      if (visited[there.first][there.second]) {
        continue;
      }
      // if met a person
      if (campus[there.first][there.second] == 'P') {
        cnt++;
      }
      visited[there.first][there.second] = true;
      q.push({there.first, there.second});
    }
  }
  if (cnt == 0) {
    cout << "TT\n";
  } else {
    cout << cnt << '\n';
  }
  return 0;
}