#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int u, v, w;
};

bool compare(Edge &a, Edge &b) { return a.w < b.w; }

struct DisjointSet {
  vector<int> parents;
  vector<int> ranks;

  DisjointSet(int maxSize) {
    parents.resize(maxSize);
    ranks.resize(maxSize);
    for (int i = 0; i < maxSize; i++) {
      parents[i] = i;
      ranks[i] = 1;
    }
  }

  int findSet(int v) {
    if (v == parents[v])
      return v;
    return parents[v] = findSet(parents[v]);
  }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
      if (ranks[a] < ranks[b])
        swap(a, b);
      parents[b] = a;
      ranks[a] += ranks[b];
    }
  }
};

int main() {
  int n, m, cost = 0;
  cin >> n >> m;
  DisjointSet dset(n + 1);
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  sort(edges.begin(), edges.end(), compare);
  int longest = 0;
  for (auto e : edges) {
    int rootU = dset.findSet(e.u);
    int rootV = dset.findSet(e.v);
    if (rootU != rootV) {
      cost += e.w;
      dset.unionSet(e.u, e.v);
      if (e.w > longest) {
        longest = e.w;
      }
    }
  }
  cout << cost - longest << '\n';
  return 0;
}