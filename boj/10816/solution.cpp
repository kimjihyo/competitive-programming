#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  unordered_map<int, int> memo;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    auto it = memo.find(num);
    if (it == memo.end()) {
      memo.insert({num, 1});
    } else {
      it->second++;
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    auto it = memo.find(num);
    if (it == memo.end()) {
      cout << 0 << ' ';
    } else {
      cout << it->second << ' ';
    }
  }
  cout << '\n';
  return 0;
}