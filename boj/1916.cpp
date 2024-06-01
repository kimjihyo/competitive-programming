#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct compare {
  bool operator()(pair<int, long long> &a, pair<int, long long> &b) {
    return a.second > b.second;
  }
};

void dijkstra(vector<vector<pair<int, long long>>> &adj, vector<long long> &d,
              int source) {
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, compare>
      pq;
  // 미방문 상태의 노드를 저장하는 우선순위 큐
  // 출발점으로 부터의 거리가 제일 짧은 순서대로 뽑기 위해서
  // 우선순위 큐를 사용한다.
  // 출발 노드에는 0을 넣어준다.
  d[source] = 0;
  pq.push(make_pair(source, 0));

  while (!pq.empty()) {
    // 출발점으로 부터의 거리가 제일 짧은 노드, u를 고른다.
    int u = pq.top().first; // 노드, u
    int distToU = pq.top().second;
    pq.pop(); // 노드 u를 방문한 것이므로 큐에서 제거
    if (distToU > d[u]) {
      continue;
    } else {
      cout << distToU << ' ' << d[u] << '\n';
    }
    for (auto n : adj[u]) {
      int v = n.first;               // 이웃 노드, v
      int distToV = d[u] + n.second; // 출발점에서 v까지의 거리
      if (d[v] > distToV) {
        d[v] = distToV;
        pq.push(make_pair(v, distToV));
      }
    }
    cout << '\n';
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, long long>>> adj(n + 1);
  vector<long long> dist(n + 1, LONG_LONG_MAX);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
  }

  int from, to;
  cin >> from >> to;
  dijkstra(adj, dist, from);
  cout << '\n';
  cout << dist[to] << '\n';
  return 0;
}