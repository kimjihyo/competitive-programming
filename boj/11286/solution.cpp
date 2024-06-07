#include <algorithm>
#include <iostream>
using namespace std;

int cnt = 0;
long long arr[100'001];

long long absolute(long long val) {
  if (val < 0)
    return -val;
  return val;
}

void heapifyUp(int idx) {
  if (idx == 1)
    return;
  if (absolute(arr[idx]) < abs(arr[idx / 2])) {
    swap(arr[idx], arr[idx / 2]);
    heapifyUp(idx / 2);
  }

  if (absolute(arr[idx]) == abs(arr[idx / 2]) && arr[idx] < arr[idx / 2]) {
    swap(arr[idx], arr[idx / 2]);
    heapifyUp(idx / 2);
  }
}

void heapifyDown(int idx) {
  if (idx * 2 > cnt)
    return;
  int left = idx * 2;
  int right = idx * 2 + 1;
  // int m = absolute(arr[left]) > abs(arr[right]) ? right : left;
  int m = left;
  if (absolute(arr[left]) > abs(arr[right])) {
    m = right;
  } else if (absolute(arr[left]) == absolute(arr[right]) &&
             arr[left] > arr[right]) {
    m = right;
  }

  if (absolute(arr[m]) < abs(arr[idx])) {
    swap(arr[m], arr[idx]);
    heapifyDown(m);
  }
  if (absolute(arr[m]) == abs(arr[idx]) && arr[m] < arr[idx]) {
    swap(arr[m], arr[idx]);
    heapifyDown(m);
  }
}

void push(long long val) {
  arr[++cnt] = val;
  heapifyUp(cnt);
}

long long pop() {
  long long ret = arr[1];
  arr[1] = arr[cnt--];
  heapifyDown(1);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long v;
    cin >> v;
    if (v == 0) {
      if (cnt == 0) {
        cout << 0 << '\n';
      } else {
        cout << pop() << '\n';
      }
    } else {
      push(v);
    }
  }
  return 0;
}