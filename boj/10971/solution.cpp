#include <climits>
#include <iostream>
using namespace std;

int n, ans = INT_MAX;
int w[10][10];

void dfs(bool *visited, int cnt, int start, int current, int costSum) {
  if (cnt == n && start == current) {
    if (costSum < ans) {
      ans = costSum;
    }
    return;
  }

  for (int i = 0; i < n; i++) {
    int cost = w[current][i];
    if (cost != 0 && !visited[i]) {
      visited[i] = true;
      dfs(visited, cnt + 1, start, i, cost + costSum);
      visited[i] = false;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> w[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    bool visited[10]{};
    dfs(visited, 0, i, i, 0);
  }
  cout << ans << '\n';
  return 0;
}