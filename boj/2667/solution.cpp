#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n;
bool arr[25][25];
bool visited[25][25];

pair<int, int> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int sy, int sx) {
  int ret = 1;
  stack<pair<int, int>> st;
  st.push({sy, sx});
  visited[sy][sx] = true;
  while (!st.empty()) {
    int y = st.top().first;
    int x = st.top().second;
    st.pop();
    for (auto dir : dirs) {
      int ny = y + dir.first;
      int nx = x + dir.second;
      if (ny > -1 && nx > -1 && ny < n && nx < n) {
        if (!visited[ny][nx] && arr[ny][nx] == 1) {
          visited[ny][nx] = true;
          st.push({ny, nx});
          ret++;
        }
      }
    }
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      arr[i][j] = str[j] - '0';
    }
  }
  vector<int> cnt;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 1 && !visited[i][j]) {
        cnt.push_back(dfs(i, j));
      }
    }
  }
  sort(cnt.begin(), cnt.end());
  cout << cnt.size() << '\n';
  for (auto n : cnt) {
    cout << n << '\n';
  }
  return 0;
}