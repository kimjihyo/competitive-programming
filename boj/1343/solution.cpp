#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  string ans = "";
  cin >> str;
  int xcnt = 0;
  bool valid = true;
  for (auto c : str) {
    if (c == '.') {
      if (xcnt % 2 != 0) {
        valid = false;
        break;
      } else {
        int acnt = xcnt / 4;
        int bcnt = (xcnt % 4) / 2;
        for (int i = 0; i < acnt; i++) {
          ans += "AAAA";
        }
        for (int i = 0; i < bcnt; i++) {
          ans += "BB";
        }
        ans += ".";
        xcnt = 0;
      }
    } else {
      xcnt++;
    }
  }
  if (!valid || xcnt % 2 != 0) {
    cout << -1 << '\n';
  } else {
    int acnt = xcnt / 4;
    int bcnt = (xcnt % 4) / 2;
    for (int i = 0; i < acnt; i++) {
      ans += "AAAA";
    }
    for (int i = 0; i < bcnt; i++) {
      ans += "BB";
    }
    cout << ans << '\n';
  }
  return 0;
}