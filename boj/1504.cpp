#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  }
};

int dijkstra(vector<vector<pair<int, int>>> &adj, int src, int dest) {
  vector<int> dist(adj.size(), INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  dist[src] = 0;
  pq.push({src, 0});
  while (!pq.empty()) {
    int here = pq.top().first;
    int distToHere = pq.top().second;
    pq.pop();
    if (dist[here] < distToHere)
      continue;
    for (auto e : adj[here]) {
      int there = e.first;
      int distToThere = e.second + distToHere;
      if (distToThere < dist[there]) {
        dist[there] = distToThere;
        pq.push({there, distToThere});
      }
    }
  }
  if (dist[dest] == INT_MAX)
    return -1;
  return dist[dest];
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int v1, v2;
  cin >> v1 >> v2;

  int path1 = -1;
  int a1 = dijkstra(adj, 1, v1);
  int b1 = dijkstra(adj, v1, v2);
  int c1 = dijkstra(adj, v2, n);
  if (a1 != -1 && b1 != -1 && c1 != -1) {
    path1 = a1 + b1 + c1;
  }

  int path2 = -1;
  int a2 = dijkstra(adj, 1, v2);
  int b2 = dijkstra(adj, v2, v1);
  int c2 = dijkstra(adj, v1, n);
  if (a2 != -1 && b2 != -1 && c2 != -1) {
    path2 = a2 + b2 + c2;
  }

  cout << min(path1, path2) << '\n';

  return 0;
}