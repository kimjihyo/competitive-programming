#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;

  for (char c : str) {
    // upper case
    if (c > 64 && c < 91) {
      cout << (char)(c + 32);
    }

    // lower case
    if (c > 96 && c < 123) {
      cout << (char)(c - 32);
    }
  }
  cout << '\n';
  return 0;
}
