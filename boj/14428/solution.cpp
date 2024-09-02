#include <algorithm>
#include <iostream>
using namespace std;

int n;
int arr[100'001];
int tree[300'003];

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
  if (arr[tree[leftNode]] < arr[tree[rightNode]]) {
    tree[node] = tree[leftNode];
  } else if (arr[tree[leftNode]] > arr[tree[rightNode]]) {
    tree[node] = tree[rightNode];
  } else {
    tree[node] = min(tree[leftNode], tree[rightNode]);
  }
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
  if (leftResult == -1) {
    return rightResult;
  }
  if (rightResult == -1) {
    return leftResult;
  }
  if (arr[leftResult] < arr[rightResult]) {
    return leftResult;
  } else if (arr[leftResult] > arr[rightResult]) {
    return rightResult;
  } else {
    return min(leftResult, rightResult);
  }
}

void update(int start, int end, int node, int index, int value) {
  if (index < start || index > end) {
    return;
  }
  if (start == end) {
    arr[index] = value;
    tree[node] = index;
    return;
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  update(start, mid, leftNode, index, value);
  update(mid + 1, end, rightNode, index, value);
  if (arr[tree[leftNode]] < arr[tree[rightNode]]) {
    tree[node] = tree[leftNode];
  } else if (arr[tree[leftNode]] > arr[tree[rightNode]]) {
    tree[node] = tree[rightNode];
  } else {
    tree[node] = min(tree[leftNode], tree[rightNode]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> arr[i];
  }
  init(1, n, 1);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int q, a, b;
    cin >> q >> a >> b;
    if (q == 1) {
      update(1, n, 1, a, b);
    } else {
      int result = get(1, n, 1, a, b);
      cout << result << '\n';
    }
  }
  return 0;
}