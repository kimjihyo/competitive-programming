#include <iostream>
#include <queue>
using namespace std;

int n, m;
int adj[201][201];
int cities[1000];
bool visited[201]{};

void resetVisited() {
  for (int i = 0; i < m; i++) {
    visited[i] = false;
  }
}

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    visited[here] = true;
    for (int i = 1; i < n + 1; i++) {
      if (adj[here][i] == 1 && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      cin >> adj[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> cities[i];
  }

  bool found = false;
  for (int i = 0; i < m; i++) {
    bfs(cities[i]);
    bool allVisited = true;
    for (int j = 0; j < m; j++) {
      if (!visited[cities[j]]) {
        allVisited = false;
        break;
      }
    }
    if (allVisited) {
      found = true;
      break;
    }
    resetVisited();
  }

  if (found) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}