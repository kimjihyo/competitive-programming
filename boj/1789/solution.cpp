#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long i = 1;
  long long sum = 0;
  while (sum < n) {
    sum += i++;
  }
  i--;
  if (n < sum)
    i--;
  cout << i << '\n';
  return 0;
}