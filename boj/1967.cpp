#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int ans = 0;
int n;
vector<pair<int, int>> adj[10'001];

void bfs(int s) {
  int dist[10'001];
  fill(dist, dist + n + 1, -1);
  queue<int> q;
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    for (auto edge : adj[here]) {
      if (dist[edge.first] == -1) {
        dist[edge.first] = dist[here] + edge.second;
        q.push(edge.first);
        if (ans < dist[edge.first]) {
          ans = dist[edge.first];
        }
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  for (int i = 0; i < n; i++) {
    bfs(i + 1);
  }

  cout << ans << '\n';
  return 0;
}