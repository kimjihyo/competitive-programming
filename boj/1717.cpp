#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parents, int a) {
  if (parents[a] == a)
    return a;
  return parents[a] = find(parents, parents[a]);
}

void merge(vector<int> &parents, int a, int b) {
  int rootA = find(parents, a);
  int rootB = find(parents, b);
  parents[rootA] = rootB;
}

void areTheyInTheSameSet(vector<int> &parents, int a, int b) {
  int rootA = find(parents, a);
  int rootB = find(parents, b);
  if (rootA == rootB) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> parents(n + 1);
  for (int i = 0; i < n + 1; i++) {
    parents[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int c, a, b;
    cin >> c >> a >> b;
    switch (c) {
    case 0:
      merge(parents, a, b);
      break;
    case 1:
      areTheyInTheSameSet(parents, a, b);
      break;
    default:
      break;
    }
  }
  return 0;
}