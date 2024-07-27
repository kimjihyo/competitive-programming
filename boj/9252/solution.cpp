#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int memo[1001][1001]{};
  string str1, str2;
  cin >> str1 >> str2;
  for (int i = 1; i < str1.size() + 1; i++) {
    for (int j = 1; j < str2.size() + 1; j++) {
      int left = memo[i][j - 1];
      int top = memo[i - 1][j];
      int diag = memo[i - 1][j - 1];
      if (str1[i - 1] == str2[j - 1]) {
        diag++;
      }
      memo[i][j] = max(max(left, top), diag);
    }
  }

  int i = str1.size(), j = str2.size();
  string lcs = "";
  while (i > 0 && j > 0) {
    int current = memo[i][j];
    int left = memo[i][j - 1];
    int top = memo[i - 1][j];
    int diag = memo[i - 1][j - 1];
    if (current == top) {
      i--;
    } else if (current == left) {
      j--;
    } else if (current == diag + 1) {
      lcs = str1[i - 1] + lcs;
      i--;
      j--;
    } else {
      break;
    }
  }
  cout << lcs.size() << '\n';
  if (lcs.size() != 0) {
    cout << lcs << '\n';
  }
  return 0;
}