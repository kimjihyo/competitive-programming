#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int p = -1;
vector<int> arr;
vector<int> result;
vector<bool> selected;

void permutation() {
  if (result.size() == m) {
    for (auto val : result)
      cout << val << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!selected[i]) {
      result.push_back(arr[i]);
      selected[i] = true;
      if (p != arr[i]) {
        permutation();
      }
      result.pop_back();
      selected[i] = false;
      p = arr[i];
    }
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
  permutation();
  return 0;
}