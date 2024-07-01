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
    int value;
    cin >> value;
    s.insert(value);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int value;
    cin >> value;
    if (s.find(value) == s.end()) {
      cout << 0 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }

  return 0;
}