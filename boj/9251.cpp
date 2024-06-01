#include <iostream>
#include <string>
using namespace std;

int main() {
  int memo[1'001][1'001]{};
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 1; i < s1.size() + 1; i++) {
    int val = 0;
    for (int j = 1; j < s2.size() + 1; j++) {
      val = max(memo[i - 1][j - 1], val);
      val = max(memo[i - 1][j], val);
      if (s1[i - 1] == s2[j - 1]) {
        val = max(memo[i - 1][j - 1] + 1, val);
      }
      memo[i][j] = val;
    }
  }
  cout << memo[s1.size()][s2.size()] << '\n';
  return 0;
}