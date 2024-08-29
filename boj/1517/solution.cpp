#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> arr[500]{};
long long tree[1'500]{};

bool compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

long long get(int start, int end, int node, int from, int to) {
  if (from > end || to < start) {
    return 0;
  }
  if (from <= start && to >= end) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  return get(start, mid, leftNode, from, to) +
         get(mid + 1, end, rightNode, from, to);
}

void update(int start, int end, int node, int index, int value) {
  if (index < start || index > end) {
    return;
  }
  if (start == end) {
    tree[node] = value;
    return;
  }
  int mid = (start + end) / 2;
  int leftNode = node * 2;
  int rightNode = node * 2 + 1;
  update(start, mid, leftNode, index, value);
  update(mid + 1, end, rightNode, index, value);
  tree[node] = tree[leftNode] + tree[rightNode];
}

void printTree() {
  for (int i = 0; i < n * 3; i++) {
    cout << tree[i] << ' ';
  }
  cout << '\n';
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    arr[i] = {i, value};
  }
  sort(arr, arr + n, compare);
  long long swap = 0;
  for (int i = 0; i < n; i++) {
    int from = arr[i].first + 1;
    int to = n - 1;
    // cout << "from: " << from << " to: " << to << ' '
    //      << "value: " << arr[i].second << ' ';

    swap += get(0, n - 1, 1, from, to);
    // cout << "swap: " << swap << '\n';
    update(0, n - 1, 1, arr[i].first, 1);
    // printTree();
  }
  cout << swap << '\n';
  return 0;
}