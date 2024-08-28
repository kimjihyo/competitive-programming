#include <iostream>
using namespace std;
typedef long long ll;

ll tree[3'000'003];
ll arr[1'000'001];

void init(int start, int end, int node) {
  if (start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  init(start, mid, leftNode);
  init(mid + 1, end, rightNode);
  tree[node] = tree[leftNode] + tree[rightNode];
}

ll sum(int start, int end, int node, int from, int to) {
  if (from > end || to < start) {
    return 0;
  }
  if (from <= start && to >= end) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  return sum(start, mid, leftNode, from, to) +
         sum(mid + 1, end, rightNode, from, to);
}

void update(int start, int end, int node, int index, ll value) {
  if (index < start || index > end)
    return;
  if (start == end) {
    tree[node] = value;
    arr[index] = value;
    return;
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  update(start, mid, leftNode, index, value);
  update(mid + 1, end, rightNode, index, value);
  tree[node] = tree[leftNode] + tree[rightNode];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i + 1];
  }
  init(1, n, 1);
  for (int i = 0; i < k + m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, n, 1, b, c);
    } else {
      ll result = sum(1, n, 1, b, c);
      cout << result << '\n';
    }
  }
}