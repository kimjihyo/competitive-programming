#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  unordered_set<int> s;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string command;
    int value;
    cin >> command;
    if (command == "add") {
      cin >> value;
      s.insert(value);
    } else if (command == "remove") {
      cin >> value;
      s.erase(s.find(value));
    } else if (command == "check") {
      cin >> value;
      if (s.find(value) == s.end()) {
        cout << 0 << '\n';
      } else {
        cout << 1 << '\n';
      }
    } else if (command == "toggle") {
      cin >> value;
      auto itr = s.find(value);
      if (itr == s.end()) {
        s.insert(value);
      } else {
        s.erase(itr);
      }
    } else if (command == "all") {
      s.clear();
      for (int j = 1; j < 21; j++) {
        s.insert(j);
      }
    } else if (command == "empty") {
      s.clear();
    }
  }
  return 0;
}