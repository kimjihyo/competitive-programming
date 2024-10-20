#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int s, d, p = 0;
  cin >> s >> d;
  vector<int> dist(200'001, -1);
  queue<int> q;
  if (s == d) {
    p++;
  } else {

    q.push(s);
  }
  dist[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v[3] = {
        u - 1,
        u + 1,
        u * 2,
    };
    for (int i = 0; i < 3; i++) {
      if (v[i] < 0 || v[i] >= 200'001) {
        continue;
      }
      if (dist[v[i]] == -1 || dist[v[i]] == dist[u] + 1) {
        dist[v[i]] = dist[u] + 1;
        if (v[i] == d) {
          p++;
        } else {
          q.push(v[i]);
        }
      }
    }
  }
  cout << dist[d] << '\n';
  cout << p << '\n';

  return 0;
}
