#include <iostream>
using namespace std;

struct date {
  int year;
  int month;
  int day;
};

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
  if (year % 400 == 0)
    return true;
  if (year % 100 == 0)
    return false;
  return year % 4 == 0;
}

int get_days(date &d) {
  int cnt = 0;
  for (int i = 1; i < d.year; i++) {
    for (int i = 0; i < 12; i++) {
      cnt += days[i];
    }
    if (is_leap_year(i))
      cnt++;
  }
  for (int i = 0; i < d.month - 1; i++) {
    cnt += days[i];
    if (i == 1 && is_leap_year(d.year)) {
      cnt++;
    }
  }
  cnt += d.day;
  return cnt;
}

int main() {
  date d1, d2;
  cin >> d1.year >> d1.month >> d1.day >> d2.year >> d2.month >> d2.day;

  if (d2.year - d1.year == 1000) {
    if (d2.month > d1.month || (d2.month == d1.month && d2.day >= d1.day)) {
      cout << "gg\n";
      return 0;
    }
  } else if (d2.year - d1.year > 1000) {
    cout << "gg\n";
    return 0;
  }

  int diff = get_days(d2) - get_days(d1);
  cout << "D-" << diff << '\n';

  return 0;
}
