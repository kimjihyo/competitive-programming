#include <algorithm>
#include <iostream>
using namespace std;

// int arr[11];
// int tree[33];
int n;
int arr[100'001];
int tree[300'003];

int compare(int a, int b) {
  if (a == -1) {
    return b;
  }
  if (b == -1) {
    return a;
  }
  if (arr[a] < arr[b]) {
    return a;
  }
  if (arr[a] > arr[b]) {
    return b;
  }
  return min(a, b);
}

void init(int start, int end, int node) {
  if (start == end) {
    tree[node] = start;
    return;
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  init(start, mid, leftNode);
  init(mid + 1, end, rightNode);
  tree[node] = compare(tree[leftNode], tree[rightNode]);
}

int get(int start, int end, int node, int from, int to) {
  if (to < start || from > end) {
    return -1;
  }
  if (from <= start && to >= end) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  int leftResult = get(start, mid, leftNode, from, to);
  int rightResult = get(mid + 1, end, rightNode, from, to);
  return compare(leftResult, rightResult);
}

long long getMaxArea(int from, int to) {
  if (from > to) {
    return -1;
  }
  int indexOfMin = get(1, n, 1, from, to);
  long long height = arr[indexOfMin];
  long long width = to - from + 1;
  long long area = width * height;
  long long leftArea = getMaxArea(from, indexOfMin - 1);
  long long rightArea = getMaxArea(indexOfMin + 1, to);
  long long ret = max(area, max(leftArea, rightArea));
  return ret;
}

void printTree() {
  for (int i = 0; i < 30; i++) {
    cout << tree[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      cin >> arr[i + 1];
    }
    init(1, n, 1);
    long long ans = getMaxArea(1, n);
    cout << ans << '\n';
    // int ans = get(1, n, 1, 1, 4);
    // cout << ans << '\n';
  }
  return 0;
}