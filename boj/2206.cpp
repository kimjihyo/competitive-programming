#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
using pii = pair<int, int>;

int n, m;
bool world[1000][1000];
int d[1000][1000][2]{};
int ans = INT_MAX;
pii dirs[4]{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

void bfs() {
  queue<pii> q;
  q.push({0, 0});
  d[0][0][0] = 1;
  while (!q.empty()) {
    pii here = q.front();
    q.pop();
    for (pii dir : dirs) {
      pii there = {here.first + dir.first, here.second + dir.second};

      // check if there is within the world
      if (there.first > -1 && there.second > -1 && there.first < n &&
          there.second < m) {

        // check if there has been visited already
        if (d[there.first][there.second][0] == -1 ||
            (d[there.first][there.second][1] == 1 &&
             d[here.first][here.second][1] == 0)) {

          // check if there is not a wall
          if (world[there.first][there.second] == 0) {
            d[there.first][there.second][0] = d[here.first][here.second][0] + 1;
            d[there.first][there.second][1] = d[here.first][here.second][1];
            q.push({there.first, there.second});
          }

          // if there is a wall and able to break it through
          if (world[there.first][there.second] == 1 &&
              d[here.first][here.second][1] == 0) {
            d[there.first][there.second][0] = d[here.first][here.second][0] + 1;
            d[there.first][there.second][1] = 1;
            q.push({there.first, there.second});
          }
          if (there.first == n - 1 && there.second == m - 1) {
            ans = min(d[there.first][there.second][0], ans);
          }
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;

  // get user input
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      world[i][j] = s[j] - '0';
      d[i][j][0] = -1;
      d[i][j][1] = 0;
    }
  }

  bfs();

  cout << min(ans, d[n - 1][m - 1][0]) << '\n';

  return 0;
}