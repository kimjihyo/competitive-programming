#include <iostream>
#include <vector>
#define MAX 30'000'000
using namespace std;
struct edge {
  int u, v, w;
};

bool bellmanFord(int n, vector<edge> &edges) {
  vector<int> dist(n + 1, MAX);
  dist[1] = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < edges.size(); j++) {
      int u = edges[j].u;
      int v = edges[j].v;
      int w = edges[j].w;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }
  for (int j = 0; j < edges.size(); j++) {
    int u = edges[j].u;
    int v = edges[j].v;
    int w = edges[j].w;
    if (dist[u] + w < dist[v]) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n, m, w;
    cin >> n >> m >> w;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
      int u, v, wt;
      cin >> u >> v >> wt;
      edges.push_back({u, v, wt});
      edges.push_back({v, u, wt});
    }

    for (int i = 0; i < w; i++) {
      int u, v, wt;
      cin >> u >> v >> wt;
      edges.push_back({u, v, -wt});
    }
    if (bellmanFord(n, edges)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}