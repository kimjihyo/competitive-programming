#include <iostream>
#include <stack>
#include <vector>
using namespace std;

pair<int, int> dfs(vector<vector<pair<int, int>>> &adj, int src) {
  int res = 0;
  int dest = -1;
  stack<pair<int, int>> s;
  vector<bool> visited(adj.size(), false);
  s.push({src, 0});
  visited[src] = true;
  while (!s.empty()) {
    int here = s.top().first;
    int distToHere = s.top().second;
    s.pop();
    for (auto p : adj[here]) {
      int there = p.first;
      int distToThere = p.second + distToHere;
      if (!visited[there]) {
        visited[there] = true;
        s.push({there, distToThere});
        res = max(res, distToThere);
        if (res == distToThere) {
          dest = there;
        }
      }
    }
  }
  return {dest, res};
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adj(n + 1);

  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    while (true) {
      int v, w;
      cin >> v;
      if (v == -1)
        break;
      cin >> w;
      adj[u].push_back({v, w});
    }
  }

  // int res = 0;
  // res = max(dfs(adj, i + 1), res);
  pair<int, int> res = dfs(adj, 1);
  int dest = res.first;
  int cost = res.second;
  cout << dfs(adj, dest).second << '\n';

  return 0;
}