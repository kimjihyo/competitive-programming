#include <algorithm>
#include <iostream>
using namespace std;

int n;
pair<int, int> arr[500'000]{};
int tree[1'500'000]{};

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}

int get(int start, int end, int node, int from, int to) {
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
    tree[node] = 1;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    arr[i] = {i, value};
  }
  sort(arr, arr + n, compare);

  for (int i = 0; i < n; i++) {
    int from = arr[i].first + 1;
    int to = n - 1;
    cout << "from: " << from << " to: " << to << '\n';
  }
  return 0;
}