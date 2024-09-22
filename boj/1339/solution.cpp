#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct info {
  int cnt;
  char c;
};

bool compare(info &a, info &b) { return a.cnt > b.cnt; }

unordered_map<char, int> m;
unordered_map<char, info> m2;

int toNum(string &str) {
  int ret = 0;
  for (auto c : str) {
    auto it = m.find(c);
    ret = ret * 10 + it->second;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    int len = arr[i].size();
    for (int j = 0; j < len; j++) {
      auto it = m2.find(arr[i][j]);
      if (it == m2.end()) {
        m2.insert({arr[i][j],
                   {
                       (int)pow(10, len - j - 1),
                       arr[i][j],
                   }});
      } else {
        it->second.cnt += (int)pow(10, len - j - 1);
      }
    }
  }
  vector<info> arr2;
  for (auto v : m2) {
    arr2.push_back(v.second);
  }
  sort(arr2.begin(), arr2.end(), compare);
  int num = 9;
  for (auto v : arr2) {
    // cout << v.c << ' ' << v.cnt << '\n';
    m.insert({v.c, num--});
    // cout << v.c << ' ' << num + 1 << '\n';
  }
  int sum = 0;
  for (auto s : arr) {
    sum += toNum(s);
  }
  cout << sum << '\n';
  return 0;
}