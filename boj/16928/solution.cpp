#include <iostream>
#include <queue>
using namespace std;

int world[101]{};
int dist[101]{};
int visited[101]{};

void bfs() {
  queue<int> q;

  q.push(1);
  dist[1] = 0;
  visited[1] = true;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int i = 1; i < 7; i++) {
      int next = c + i;
      if (next < 101) {
        if (world[next] != 0) {
          next = world[next];
        }
        if (!visited[next]) {
          visited[next] = true;
          dist[next] = dist[c] + 1;
          q.push(next);
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    world[x] = y;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    world[u] = v;
  }
  bfs();
  cout << dist[100] << '\n';
  return 0;
}