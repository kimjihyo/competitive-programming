#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, int u) {
  vector<bool> visited(adj.size(), false);
  stack<int> s;

  s.push(u);

  while (!s.empty()) {
    int h = s.top();
    s.pop();
    if (!visited[h]) {
      cout << h << ' ';
      visited[h] = true;
      for (auto v : adj[h]) {
        if (!visited[v]) {
          s.push(v);
        }
      }
    }
  }
  cout << '\n';
}

void bfs(vector<vector<int>> &adj, int u) {
  vector<bool> visited(adj.size(), false);
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while (!q.empty()) {
    int h = q.front();
    q.pop();
    cout << h << ' ';
    for (auto v : adj[h]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
  cout << '\n';
}

int main() {
  int n, m, v;
  cin >> n >> m >> v;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i < n + 1; i++) {
    sort(adj[i].begin(), adj[i].end(), greater<int>());
  }

  dfs(adj, v);

  for (int i = 1; i < n + 1; i++) {
    sort(adj[i].begin(), adj[i].end(), less<int>());
  }

  bfs(adj, v);

  return 0;
}