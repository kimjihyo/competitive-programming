#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001]{};

void dfs(int u) {
  if (!visited[u]) {
    visited[u] = true;
    for (auto v : adj[u]) {
      dfs(v);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    if (!visited[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans << '\n';
  return 0;
}