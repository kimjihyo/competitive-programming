#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<int> pos(26, -1);
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (pos[str[i] - 'a'] == -1) {
      pos[str[i] - 'a'] = i;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << pos[i] << ' ';
  }
  cout << '\n';
  return 0;
}
