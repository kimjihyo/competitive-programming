#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  }
};

int dijkstra(vector<pair<int, int>> adj[], int size, int src, int dest) {
  int dist[1'001];
  fill(dist, dist + size, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  dist[src] = 0;
  pq.push(make_pair(src, 0));
  while (!pq.empty()) {
    int here = pq.top().first;
    int distToHere = pq.top().second;
    pq.pop();
    if (distToHere > dist[here])
      continue;
    for (pair<int, int> edge : adj[here]) {
      int there = edge.first;
      int distToThere = edge.second + distToHere;
      if (distToThere < dist[there]) {
        dist[there] = distToThere;
        pq.push(make_pair(there, distToThere));
      }
    }
  }
  return dist[dest];
}

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<pair<int, int>> adj[1'001];

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
  }

  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    int dist = dijkstra(adj, n + 1, i, x) + dijkstra(adj, n + 1, x, i);
    if (dist > ans) {
      ans = dist;
    }
  }
  cout << ans << '\n';
  return 0;
}