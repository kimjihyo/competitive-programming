#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(n + 1, vector<int>());
  int ans = 0;
  int ans_idx = -1;

  for (int i = 0; i < n + 1; i++) {
    arr[i].push_back(n);
    arr[i].push_back(i);
    while (arr[i][arr[i].size() - 2] - arr[i][arr[i].size() - 1] >= 0) {
      arr[i].push_back(arr[i][arr[i].size() - 2] - arr[i][arr[i].size() - 1]);
    }
    if (arr[i].size() > ans) {
      ans = arr[i].size();
      ans_idx = i;
    }
  }
  cout << ans << '\n';
  for (auto e : arr[ans_idx]) {
    cout << e << ' ';
  }
  cout << '\n';

  return 0;
}
