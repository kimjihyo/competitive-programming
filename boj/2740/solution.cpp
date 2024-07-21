#include <iostream>
using namespace std;

int main() {
  int n, m, k;
  int a[100][100];
  int b[100][100];
  int r[100][100];

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  cin >> m >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int tmp = 0;
      for (int t = 0; t < m; t++) {
        tmp += a[i][t] * b[t][j];
      }
      r[i][j] = tmp;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cout << r[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}