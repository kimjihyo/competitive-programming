#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s,
         int u) {
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(adj, visited, s, v);
    }
  }
  s.push(u);
}

void topologicalSort(vector<vector<int>> &adj) {
  stack<int> s;
  vector<bool> visited(adj.size(), false);
  for (int i = 1; i < adj.size(); i++) {
    if (!visited[i]) {
      dfs(adj, visited, s, i);
    }
  }
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << '\n';
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  topologicalSort(adj);

  return 0;
}