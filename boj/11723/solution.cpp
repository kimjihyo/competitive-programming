#include <iostream>
#include <string>
using namespace std;

struct set {
  int store = 0;
  void add(int x) {
    int bit = 1 << x;
    store = store | bit;
  }

  void remove(int x) {
    int bit = 1 << x;
    bit = ~bit;
    store = store & bit;
  }

  bool check(int x) {
    int bit = 1 << x;
    return (store & bit) > 0;
  }

  void toggle(int x) {
    int bit = 1 << x;
    store = store ^ bit;
  }

  void all() { store = (1 << 21) - 1; }

  void empty() { store = 0; }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  set s;
  for (int i = 0; i < n; i++) {
    string command;
    int num;
    cin >> command;
    if (command == "add") {
      cin >> num;
      s.add(num);
    } else if (command == "remove") {
      cin >> num;
      s.remove(num);
    } else if (command == "check") {
      cin >> num;
      bool result = s.check(num);
      cout << result << '\n';
    } else if (command == "all") {
      s.all();
    } else if (command == "empty") {
      s.empty();
    } else if (command == "toggle") {
      cin >> num;
      s.toggle(num);
    }
  }
  return 0;
}