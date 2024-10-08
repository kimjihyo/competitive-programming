#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  unordered_set<int> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    s.insert(val);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int val;
    cin >> val;
    auto it = s.find(val);
    if (it == s.end()) {
      cout << 0 << ' '; 
    } else {
      cout << 1 << ' ';
    }
  }
  cout << '\n';
  return 0;
}
