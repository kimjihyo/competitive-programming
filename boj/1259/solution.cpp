#include <iostream>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    string str;
    cin >> str;
    if (str == "0") {
      break;
    }
    bool is_pelindrome = true;
    for (int i = 0; i < str.size() / 2; i++) {
      if (str[i] != str[str.size() - i - 1]) {
        is_pelindrome = false;
        break;
      }
    }
    if (is_pelindrome) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}
