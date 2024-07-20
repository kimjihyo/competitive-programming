#include <iostream>
using namespace std;

int main() {
  int n, m;
  int matrix[100][100];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int val;
      cin >> val;
      matrix[i][j] += val;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}