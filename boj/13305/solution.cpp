#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dists(n - 1);
  vector<long long> costs(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> dists[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
  }
  long long cost = costs[0];
  long long totalCost = 0;
  for (int i = 0; i < n - 1; i++) {
    int dist = dists[i];
    totalCost += cost * dist;
    if (cost > costs[i + 1]) {
      cost = costs[i + 1];
    }
  }
  cout << totalCost << '\n';
  return 0;
}