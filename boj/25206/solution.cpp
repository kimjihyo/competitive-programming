#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, double> dict = {{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5},
                                        {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0},
                                        {"D+", 1.5}, {"D0", 1.0}, {"F", 0}};

  double sum = 0;
  double sum_credit = 0;
  for (int i = 0; i < 20; i++) {
    string subject, grade;
    double credit;
    cin >> subject >> credit >> grade;
    if (grade != "P") {
      sum += (credit * dict.find(grade)->second);
      sum_credit += credit;
    }
  }
  cout << sum / sum_credit;
}
