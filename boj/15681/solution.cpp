#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<vector<int>> adj;
vector<int> sizes;
vector<bool> visited;

int countNumberOfSubtreeNodes(int root) {
  visited[root] = true;
  int n = 1;
  for (auto u : adj[root]) {
    if (!visited[u]) {
      n += countNumberOfSubtreeNodes(u);
    }
  }
  sizes[root] = n;
  return n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> r >> q;
  adj.resize(n + 1);
  sizes.resize(n + 1);
  visited.resize(n + 1);
  fill(sizes.begin(), sizes.end(), 0);
  fill(visited.begin(), visited.end(), false);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  countNumberOfSubtreeNodes(r);
  for (int i = 0; i < q; i++) {
    int query;
    cin >> query;
    cout << sizes[query] << '\n';
  }
  return 0;
}