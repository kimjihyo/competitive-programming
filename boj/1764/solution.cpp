#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_set<string> s;
  vector<string> r;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    s.insert(str);
  }

  for (int i = 0; i < m; i++) {
    string str;
    cin >> str;
    if (s.find(str) != s.end()) {
      r.push_back(str);
    }
  }

  cout << r.size() << '\n';
  sort(r.begin(), r.end());
  for (string str : r) {
    cout << str << '\n';
  }

  return 0;
}