#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  bool isPalindrome[2500][2500];
  int dp[2500];

  isPalindrome[0][0] = true;
  dp[0] = 1;
  for (int i = 1; i < str.size(); i++) {
    isPalindrome[i][i] = true;
    dp[i] = dp[i - 1] + 1;
    for (int j = i - 1; j > -1; j--) {
      if (str[i] == str[j]) {
        if (isPalindrome[j + 1][i - 1] || i - j == 1) {
          isPalindrome[j][i] = true;
          if (j - 1 > -1) {
            dp[i] = min(dp[i], 1 + dp[j - 1]);
          } else {
            dp[i] = 1;
          }
        }
      }
    }
  }

  cout << dp[str.size() - 1] << '\n';
  return 0;
}