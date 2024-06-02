#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(vector<int> adj[]) {
  int cnt = 0;
  bool visited[101]{};
  queue<int> q;
  visited[1] = true;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (!visited[v]) {
        cnt++;
        visited[v] = true;
        q.push(v);
      }
    }
  }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[101];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << bfs(adj) << '\n';
  return 0;
}