#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;

int bfs(int s) {
  int total = 0;
  vector<int> dist(n + 1, -1);
  queue<int> q;
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        total += dist[v];
        q.push(v);
      }
    }
  }
  return total;
}

int main() {
  cin >> n >> m;
  adj.reserve(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int minDist = INT_MAX;
  int ans = -1;
  for (int i = 1; i < n + 1; i++) {
    int dist = bfs(i);
    if (minDist > dist) {
      ans = i;
      minDist = dist;
    }
  }
  cout << ans << '\n';
  return 0;
}