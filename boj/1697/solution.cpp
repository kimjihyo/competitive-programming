#include <iostream>
#include <queue>
using namespace std;

int n, k, j;

int dist[200'002]{};

void bfs() {
  dist[n] = 0;
  queue<int> q;
  q.push(n);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == k) {
      break;
    }

    int v1 = u + 1;
    int v2 = u - 1;
    int v3 = u * 2;

    if (dist[v1] == -1) {
      dist[v1] = dist[u] + 1;
      q.push(v1);
    }
    if (dist[v2] == -1) {
      dist[v2] = dist[u] + 1;
      q.push(v2);
    }
    if (v3 < 2 * k + 1 && dist[v3] == -1) {
      dist[v3] = dist[u] + 1;
      q.push(v3);
    }
  }
}

int main() {
  cin >> n >> k;
  j = max(n, k);
  for (int i = 0; i < 2 * j + 1; i++) {
    dist[i] = -1;
  }
  bfs();

  cout << dist[k] << '\n';
}