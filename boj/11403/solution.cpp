#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<bool>> adj;
vector<vector<bool>> visited;

void bfs(int node) {
  queue<int> q;
  q.push(node);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; v++) {
      if (adj[u][v] == 1 && !visited[node][v]) {
        visited[node][v] = 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> n;
  adj.resize(n);
  visited.resize(n);
  fill(adj.begin(), adj.end(), vector<bool>(n, 0));
  fill(visited.begin(), visited.end(), vector<bool>(n, 0));


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool value;
      cin >> value;
      adj[i][j] = value;
    }
  }
  for (int i = 0; i < n; i++) {
    bfs(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << visited[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
