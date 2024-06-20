#include <iostream>
#include <string>
using namespace std;

bool check(string &str) {
  bool arr[26]{};
  char prev = str[0];
  arr[prev - 'a'] = true;
  for (int i = 1; i < str.size(); i++) {
    if (arr[str[i] - 'a'] && str[i] != prev) {
      return false;
    }
    prev = str[i];
    arr[prev - 'a'] = true;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    if (check(str)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}