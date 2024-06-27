#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
  unordered_set<string> s;
  s.insert("c=");
  s.insert("c-");
  s.insert("dz=");
  s.insert("d-");
  s.insert("lj");
  s.insert("nj");
  s.insert("s=");
  s.insert("z=");

  string str;
  cin >> str;
  int ans = 0;

  for (int i = 0; i < str.size(); i++) {
    string alphabet;
    for (int j = 1; j < 4; j++) {
      alphabet = str.substr(i, j);
      if (s.find(alphabet) != s.end()) {
        i += j - 1;
      }
    }
    ans++;
  }

  cout << ans << '\n';

  return 0;
}