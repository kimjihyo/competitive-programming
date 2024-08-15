#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
  bool operator()(int a, int b) { return b < a; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> indegree(n + 1, 0);
  queue<int> q;
  priority_queue<int, vector<int>, compare> pq;
  vector<int> result;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i < n + 1; i++) {
    for (auto v : adj[i]) {
      indegree[v]++;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    if (indegree[i] == 0) {
      q.push(i);
      pq.push(i);
    }
  }

  while (!pq.empty()) {
    auto u = pq.top();
    pq.pop();
    result.push_back(u);

    for (auto v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        pq.push(v);
      }
    }
  }

  for (auto it : result) {
    cout << it << ' ';
  }
  cout << '\n';
  return 0;
}