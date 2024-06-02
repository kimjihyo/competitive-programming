#include <iostream>
#include <vector>
using namespace std;

int n, m;

int tree[51];
int rank[51];
bool memo[51];
vector<int> parties;

int find(int i) {
  if (tree[i] == i)
    return i;
  tree[i] = find(tree[i]);
  return tree[i];
}

void unite(int i, int j) {
  int pi = find(i);
  int pj = find(j);
  if (pi == pj)
    return;
  if (memo[pi]) {
    tree[pj] = pi;
  } else {
    tree[pi] = pj;
  }
}

int main() {
  int k;
  cin >> n >> m >> k;

  for (int i = 1; i < n + 1; i++) {
    tree[i] = i;
  }

  for (int i = 0; i < k; i++) {
    int val;
    cin >> val;
    memo[val] = true;
  }

  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    int prev;
    for (int j = 0; j < num; j++) {
      int val;
      cin >> val;
      if (j > 0) {
        unite(prev, val);
      }
      prev = val;
    }
    parties.push_back(find(prev));
  }
  int cnt = 0;

  for (auto party : parties) {
    if (!memo[find(party)]) {
      cnt++;
    }
  }

  cout << cnt << '\n';

  return 0;
}