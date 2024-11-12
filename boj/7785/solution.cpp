#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  unordered_set<string> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str, enter_or_leave;
    cin >> str >> enter_or_leave;
    if (enter_or_leave == "enter") {
      s.insert(str);
    } else {
      auto it = s.find(str);
      if (it != s.end()) {
        s.erase(str);
      }
    }
  }

  vector<string> arr;

  for (auto str : s) {
    arr.push_back(str);
  }

  sort(arr.begin(), arr.end());
  reverse(arr.begin(), arr.end());
  for (auto str : arr) {
    cout << str << '\n';
  }

  return 0;
}
