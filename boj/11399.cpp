#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }
  sort(arr.begin(), arr.end());
  int sum = 0;
  int ans = 0;
  for (int val : arr) {
    sum += val;
    ans += sum;
  }
  cout << ans << '\n';
  return 0;
}