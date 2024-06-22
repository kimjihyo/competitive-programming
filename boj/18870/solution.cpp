#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> original;
  vector<int> sorted;
  unordered_set<int> s;
  unordered_map<int, int> m;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    original.push_back(val);
    if (s.find(val) == s.end()) {
      sorted.push_back(val);
      s.insert(val);
    }
  }

  sort(sorted.begin(), sorted.end());

  for (int i = 0; i < sorted.size(); i++) {
    m.insert({sorted[i], i});
  }

  for (auto val : original) {
    cout << m.find(val)->second << ' ';
  }

  cout << '\n';
  return 0;
}