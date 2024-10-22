#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, r;
vector<vector<pair<int, int>>> adj;
vector<int> items;

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  }
};

int dijkstra(int s) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  vector<int> dist(adj.size(), INT_MAX);
  pq.push({s, 0});
  dist[s] = 0;
  while (!pq.empty()) {
    auto here = pq.top().first;
    int dist2here = pq.top().second;
    pq.pop();
    if (dist[here] < dist2here) {
      continue;
    }
    for (auto there : adj[here]) {
      int dist2there = dist2here + there.second;
      if (dist[there.first] > dist2there) {
        dist[there.first] = dist2there;
        pq.push({there.first, dist2there});
      }
    }
  }
  int sum = 0;
  for (int i = 1; i < n + 1; i++) {
    if (dist[i] < m + 1) {
      sum += items[i];
    }
  }
  return sum;
}

int main() {
  cin >> n >> m >> r;

  adj.resize(n + 1);
  items.resize(n + 1);

  for (int i = 1; i < n + 1; i++) {
    cin >> items[i];
  }

  for (int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
  }
  int ans = 0;
  for (int i = 1; i < n + 1; i++) {
    ans = max(ans, dijkstra(i));
  }
  cout << ans << '\n';
  return 0;
}
