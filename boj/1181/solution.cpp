#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool compare(string &a, string &b) {
  if (a.size() == b.size()) {
    return a < b;
  }
  return a.size() < b.size();
}

int main() {
  int n;
  vector<string> arr;
  unordered_set<string> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    if (s.find(input) == s.end()) {
      arr.push_back(input);
      s.insert(input);
    }
  }
  sort(arr.begin(), arr.end(), compare);

  for (auto str : arr) {
    cout << str << '\n';
  }
  return 0;
}