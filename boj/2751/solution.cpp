#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> arr;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  sort(arr.begin(), arr.end());
  for (auto val : arr) {
    cout << val << '\n';
  }
  return 0;
}