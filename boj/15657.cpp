#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> selected;
vector<int> arr;
vector<int> res;

void combination(int idx, int cnt) {
  if (cnt == m) {
    // print arr
    for (auto val : res) {
      cout << val << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = idx; i < arr.size(); i++) {
    res.push_back(arr[i]);
    combination(i, cnt + 1);
    res.pop_back();
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
    selected.push_back(false);
  }
  sort(arr.begin(), arr.end());
  combination(0, 0);
  return 0;
}