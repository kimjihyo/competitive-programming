#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a1;
  vector<int> a2;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    a1.push_back(val);
  }
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    a2.push_back(val);
  }
  sort(a1.begin(), a1.end());
  sort(a2.rbegin(), a2.rend());

  int ans = 0;
  for (int i = 0; i < n; i++) {

    int val = a1[i] * a2[i];
    ans += val;
  }
  cout << ans << '\n';
  return 0;
}