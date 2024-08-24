#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int n1, n2, n3;
  int pMax1, pMax2, pMax3;
  int pMin1, pMin2, pMin3;

  cin >> pMax1 >> pMax2 >> pMax3;
  pMin1 = pMax1, pMin2 = pMax2, pMin3 = pMax3;
  for (int i = 1; i < n; i++) {
    cin >> n1 >> n2 >> n3;

    int max1 = max(pMax1, pMax2) + n1;
    int max2 = max(pMax1, max(pMax2, pMax3)) + n2;
    int max3 = max(pMax2, pMax3) + n3;

    int min1 = min(pMin1, pMin2) + n1;
    int min2 = min(pMin1, min(pMin2, pMin3)) + n2;
    int min3 = min(pMin2, pMin3) + n3;

    pMax1 = max1;
    pMax2 = max2;
    pMax3 = max3;

    pMin1 = min1;
    pMin2 = min2;
    pMin3 = min3;
  }
  cout << max(pMax1, max(pMax2, pMax3)) << ' ' << min(pMin1, min(pMin2, pMin3))
       << '\n';
  return 0;
}