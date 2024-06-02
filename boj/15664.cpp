#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> result;

void combination(int idx) {
  if (result.size() == m) {
    for (auto val : result) {
      cout << val << ' ';
    }
    cout << '\n';
    return;
  }

  int prev = -1;
  for (int i = idx; i < n; i++) {
    result.push_back(arr[i]);
    if (prev != arr[i]) {
      combination(i + 1);
    }
    prev = arr[i];
    result.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  sort(arr.begin(), arr.end());
  combination(0);
  return 0;
}