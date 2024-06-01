#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

using adj_list = vector<vector<pair<int, int>>>;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

void dijkstra(adj_list &adj, vector<int> &dist, int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  pq.push(make_pair(s, 0));
  dist[s] = 0;
  while (!pq.empty()) {
    pair<int, int> here = pq.top();
    pq.pop();

    for (auto there : adj[here.first]) {
      int cost = here.second + there.second;
      if (dist[there.first] > cost) {
        dist[there.first] = cost;
        pq.push(make_pair(there.first, cost));
      }
    }
  }
}

int main() {
  int v, e, s;
  cin >> v >> e >> s;
  adj_list adj(v + 1);
  vector<int> dist(v + 1, INT_MAX);

  for (int i = 1; i < v + 1; i++) {
    adj[i] = vector<pair<int, int>>();
  }

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
  }

  dijkstra(adj, dist, s);

  for (int i = 1; i < v + 1; i++) {
    if (dist[i] == INT_MAX) {
      cout << "INF" << '\n';
    } else {
      cout << dist[i] << '\n';
    }
  }

  return 0;
}