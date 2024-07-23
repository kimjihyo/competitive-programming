#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    unordered_map<string, int> m;
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      string name, category;
      cin >> name >> category;
      auto iter = m.find(category);
      if (iter != m.end()) {
        iter->second += 1;
      } else {
        m.insert({category, 1});
      }
    }
    int ans = 1;
    for (auto p : m) {
      ans *= p.second + 1;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}