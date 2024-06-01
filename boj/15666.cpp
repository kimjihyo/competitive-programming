#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;
vector<int> selected;

void combination(int idx) {
  if (selected.size() == m) {
    for (auto val : selected)
      cout << val << ' ';
    cout << '\n';
    return;
  }
  for (int i = idx; i < arr.size(); i++) {
    selected.push_back(arr[i]);
    if (i == 0 || arr[i - 1] != arr[i]) {
      combination(i);
    }
    selected.pop_back();
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