#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int n;
char grid[100][100];
bool visited[100][100]{};

pair<int, int> dirs[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

void dfs(int y, int x) {
  visited[y][x] = true;
  for (auto dir : dirs) {
    int ny = y + dir.first;
    int nx = x + dir.second;
    if (ny > -1 && nx > -1 && ny < n && nx < n) {
      if (!visited[ny][nx] && grid[ny][nx] == grid[y][x]) {
        dfs(ny, nx);
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < n; j++) {
      grid[i][j] = input[j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        cnt++;
        dfs(i, j);
      }
    }
  }
  cout << cnt << ' ';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = false;
      if (grid[i][j] == 'R') {
        grid[i][j] = 'G';
      }
    }
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        cnt++;
        dfs(i, j);
      }
    }
  }
  cout << cnt << '\n';

  return 0;
}