#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1'001];
vector<int> treeAdj[1'001];
vector<int> dist(1'001, INT_MAX);
vector<bool> visited(1'001, false);
vector<int> prevNodes(1'001, -1);

struct compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
  }
};

void dijkstra(int start, int dest) {
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  pq.push({start, 0});
  while (!pq.empty()) {
    int here = pq.top().first;
    int distToHere = pq.top().second;
    pq.pop();
    if (dist[here] < distToHere)
      continue;
    for (auto e : adj[here]) {
      int there = e.first;
      int distToThere = distToHere + e.second;
      if (dist[there] > distToThere) {
        dist[there] = distToThere;
        pq.push({there, distToThere});
        treeAdj[here].push_back(there);
        prevNodes[there] = here;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  int start, dest;
  cin >> start >> dest;
  dijkstra(start, dest);
  cout << dist[dest] << '\n';
  stack<int> s;
  int temp = dest;
  while (temp != -1) {
    s.push(temp);
    temp = prevNodes[temp];
  }
  cout << s.size() << '\n';
  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << '\n';
  return 0;
}