#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool comp(string &input, string &keyword, int start_index) {
  for (int i = start_index; i < start_index + keyword.length(); i++) {
    if (input[i] != keyword[i - start_index]) {
      return false;
    }
  }
  return true;
}

int main() {
  string input, keyword;
  getline(cin, input);
  getline(cin, keyword);

  int ans = 0;
  for (int i = 0; i < input.length(); i++) {
    // i is the staring index to search from
    int n = 0;
    for (int j = i; j < (int)input.length() - (int)keyword.length() + 1; j++) {
      if (comp(input, keyword, j)) {
        j += keyword.length() - 1;
        n++;
      }
    }
    ans = max(ans, n);
  }
  cout << ans << '\n';

  return 0;
}
