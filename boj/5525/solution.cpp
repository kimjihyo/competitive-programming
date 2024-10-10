#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int n, m;
  string str;
  cin >> n >> m >> str;

  unordered_map<int, int> memo;
  char expected = 'I';
  int size = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == expected) {
      size++;
      expected = expected == 'I' ? 'O' : 'I';
    } else {
      if (str[i] == 'I') {
        auto it = memo.find(size);
        if (it == memo.end()) {
          memo.insert({size, 1});
        } else {
          it->second++;
        }
        size = 1;
        expected = 'O';
      } else {
        size--;
        auto it = memo.find(size);
        if (it == memo.end()) {
          memo.insert({size, 1});
        } else {
          it->second++;
        }
        size = 0;
      }
    }
  }
  if (size != 0) {
    if (str[str.size() - 1] == 'I') {
      auto it = memo.find(size);
      if (it == memo.end()) {
        memo.insert({size, 1});
      } else {
        it->second++;
      }
    } else {
      size--;
      auto it = memo.find(size);
      if (it == memo.end()) {
        memo.insert({size, 1});
      } else {
        it->second++;
      }
    }
  }
  int ans = 0;
  for (auto it : memo) {
    // cout << it.first << ' ' << it.second << '\n';
    if (it.first >= n * 2 + 1) {
      ans += ((it.first - 1) / 2 - n + 1) * it.second;
    }
  }
  cout << ans << '\n';
  return 0;
}
