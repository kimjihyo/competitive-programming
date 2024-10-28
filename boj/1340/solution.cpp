#include <ios>
#include <iostream>
#include <string>
using namespace std;

bool is_leap_year(int y) {
  if (y % 400 == 0)
    return true;
  if (y % 100 == 0)
    return false;
  return y % 4 == 0;
}

int main() {
  string months[] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string m, d, t;
  int y;

  cin >> m >> d >> y >> t;

  int mi = 0;
  for (int i = 0; i < 12; i++) {
    if (months[i] == m) {
      mi = i;
      break;
    }
  }
  if (is_leap_year(y)) {
    days[1] += 1;
  }

  int dc = 0;
  for (int i = 0; i < mi; i++) {
    dc += days[i];
  }
  int id = stoi(d.substr(0, d.size() - 1));
  dc += id;
  dc -= 1;

  int minutes = dc * 24 * 60;

  int hours = stoi(t.substr(0, 2));
  int min = stoi(t.substr(3, 5));
  minutes += hours * 60;
  minutes += min;

  cout << fixed;
  cout.precision(9);
  if (is_leap_year(y)) {
    cout << (double)minutes / 527040 * 100 << '\n';
  } else {

    cout << (double)minutes / 525600 * 100 << '\n';
  }

  return 0;
}
