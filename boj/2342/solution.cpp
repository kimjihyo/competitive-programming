#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int costs[5][5] = {
    {0, 2, 2, 2, 2}, {0, 1, 3, 4, 3}, {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3}, {0, 3, 4, 3, 1},
};

int dp[100'000][5][5]{};
vector<int> arr;

int dfs(int n, int n1, int n2) {
  if (n > arr.size())
    return 0;

  if (dp[n][n1][n2] != 0) {
    return dp[n][n1][n2];
  }

  int nextMove = arr[n + 1];
  int prevN1 = n1, prevN2 = n2;
  int nextN1, nextN2, cost1, cost2;

  // first
  nextN1 = nextMove, nextN2 = prevN2;
  cost1 = costs[prevN1][nextN1];
  if (nextN1 > nextN2)
    swap(nextN1, nextN2);
  cost1 += dfs(n + 1, nextN1, nextN2);

  // second
  nextN1 = prevN1, nextN2 = nextMove;
  cost2 = costs[prevN2][nextN2];
  if (nextN1 > nextN2)
    swap(nextN1, nextN2);
  cost2 += dfs(n + 1, nextN1, nextN2);

  dp[n][n1][n2] = min(cost1, cost2);

  return dp[n][n1][n2];
}

int main() {
  arr.push_back(0);
  while (true) {
    int num;
    cin >> num;
    if (num == 0)
      break;
    arr.push_back(num);
  }
  cout << dfs(0, 0, 0) << '\n';
  return 0;
}