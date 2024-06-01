#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
  int u;
  int v;
  int w;
};

bool comp(edge &a, edge &b) { return a.w < b.w; }

int find(vector<int> &parents, int u) {
  if (parents[u] == u)
    return u;
  parents[u] = find(parents, parents[u]);
  return parents[u];
}

void unite(vector<int> &parents, vector<int> &ranks, int u, int v) {
  u = find(parents, u);
  v = find(parents, v);
  if (u == v)
    return;
  if (ranks[u] > ranks[v]) {
    parents[v] = u;
  } else if (ranks[u] < ranks[v]) {
    parents[u] = v;
  } else {
    parents[u] = v;
    ranks[v] += 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int v, e;
  vector<edge> edges;
  vector<int> parents;
  vector<int> ranks;

  cin >> v >> e;

  for (int i = 0; i < v; i++) {
    parents.push_back(i);
    ranks.push_back(1);
  }

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end(), comp);

  int cost = 0;
  for (auto edge : edges) {
    int rootU = find(parents, edge.u);
    int rootV = find(parents, edge.v);
    if (rootU != rootV) {
      cost += edge.w;
      unite(parents, ranks, edge.u, edge.v);
    }
  }

  cout << cost << '\n';
  return 0;
}