#include <iostream>
#include <queue>
using namespace std;

struct pos {
  int y, x;
};

int n;
int state[20][20];
int currentX, currentY;
int currentSharkSize = 2;
int eatCount = 0;
pos dirs[] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0},
};

void printState() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == currentY && j == currentX) {
        cout << 9 << ' ';
      } else {
        cout << state[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}

int bfs(int y, int x) {
  int foundY = 21;
  int foundX = 21;
  int distances[20][20]{};
  queue<pos> q;
  q.push({y, x});
  distances[y][x] = 0;
  while (!q.empty()) {
    auto here = q.front();
    q.pop();
    for (auto dir : dirs) {
      pos there = {here.y + dir.y, here.x + dir.x};
      if (there.y < 0 || there.x < 0 || there.y > n - 1 || there.x > n - 1) {
        continue;
      }
      if (distances[there.y][there.x] == 0) {
        int theState = state[there.y][there.x];
        if (theState != 0 && theState < currentSharkSize) {
          distances[there.y][there.x] = distances[here.y][here.x] + 1;
          if (there.y < foundY || (there.y == foundY && there.x < foundX)) {
            if (foundY == 21 ||
                (distances[there.y][there.x] <= distances[foundY][foundX])) {
              foundY = there.y;
              foundX = there.x;
            }
          }
        }
        if (theState == 0 || theState == currentSharkSize) {
          distances[there.y][there.x] = distances[here.y][here.x] + 1;
          if (foundY == 21 && foundX == 21) {
            q.push({there.y, there.x});
          }
        }
      }
    }
  }
  if (foundY != 21) {
    state[foundY][foundX] = 0;
    currentX = foundX, currentY = foundY;
    eatCount++;
    if (eatCount == currentSharkSize) {
      currentSharkSize += 1;
      eatCount = 0;
    }
    return distances[foundY][foundX];
  }
  return 0;
}

int main() {
  int t, ans;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int input;
      cin >> input;
      if (input == 9) {
        currentX = j, currentY = i;
      } else {
        state[i][j] = input;
        if (input != 0) {
          t++;
        }
      }
    }
  }

  for (int i = 0; i < t; i++) {
    int delta = bfs(currentY, currentX);
    ans += delta;
    // cout << ans << ' ' << currentSharkSize << '\n';
    // printState();
    if (delta == 0) {
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}