#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'p') {
      if (++i >= str.size() || str[i] != 'i') {
        cout << "NO\n";
        return 0;
      }
    } else if (str[i] == 'k') {
      if (++i >= str.size() || str[i] != 'a') {
        cout << "NO\n";
        return 0;
      }
    } else if (str[i] == 'c') {
      if (++i >= str.size() || str[i] != 'h') {
        cout << "NO\n";
        return 0;
      }
      if (++i >= str.size() || str[i] != 'u') {
        cout << "NO\n";
        return 0;
      }
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}