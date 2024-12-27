#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    int h, w, n;
    cin >> h >> w >> n;
    int floor = n % h;
    floor = floor == 0 ? h : floor;
    int room_number = n % h == 0 ? n / h : n / h + 1;
    if (room_number < 10) {
      cout << floor << 0 << room_number << '\n';
    } else {
      cout << floor << room_number << '\n';
    }
  }
  return 0;
}
