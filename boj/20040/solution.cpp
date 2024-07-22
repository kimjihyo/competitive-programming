#include <iostream>
#include <vector>
using namespace std;

vector<int> parents;
vector<int> ranks;

int findSet(int v) {
  if (v == parents[v]) {
    return v;
  }
  return parents[v] = findSet(parents[v]);
}

bool unionSet(int u, int v) {
  u = findSet(u);
  v = findSet(v);
  if (u != v) {
    if (ranks[u] < ranks[v])
      swap(u, v);
    parents[v] = u;
    ranks[u] += ranks[v];
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  parents.resize(n);
  ranks.resize(n);

  for (int i = 0; i < n; i++) {
    parents[i] = i;
    ranks[i] = 1;
  }

  int ans = 0;

  for (int i = 0; i < m; i++) {
    int p1, p2;
    cin >> p1 >> p2;
    if (ans == 0 && !unionSet(p1, p2)) {
      ans = i + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}