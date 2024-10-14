#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> m >> n;
  int numSinglesToBuy = m % 6;
  int numPackagesToBuy = m / 6;
  vector<int> singlePrices;
  vector<int> packagePrices;
  for (int i = 0; i < n; i++) {
    int singlePrice, packagePrice;
    cin >> packagePrice >> singlePrice;
    if (singlePrice * 6 < packagePrice) {
      packagePrice = singlePrice * 6;
    }
    singlePrices.push_back(singlePrice);
    packagePrices.push_back(packagePrice);
  }
  sort(singlePrices.begin(), singlePrices.end());
  sort(packagePrices.begin(), packagePrices.end());
  int ans1 = packagePrices[0] * (numPackagesToBuy + 1);
  int ans2 =
      packagePrices[0] * numPackagesToBuy + singlePrices[0] * numSinglesToBuy;
  cout << min(ans1, ans2) << '\n';
  return 0;
}
