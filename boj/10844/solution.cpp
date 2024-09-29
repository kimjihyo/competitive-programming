#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> dp[10];
  for (int i = 1; i < 11; i++) {
    dp[i].push_back(i);
  }
  return 0;
}
