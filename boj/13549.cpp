#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using edge = pair<int, int>;

const int MAX = 200'000;

struct compare {
  bool operator()(edge a, edge b) { return a.second > b.second; }
};

int search(int start, int dest) {
  if (start == dest)
    return 0;
  vector<int> dists(MAX, INT_MAX);
  priority_queue<edge, vector<edge>, compare> pq;
  pq.push(make_pair(start, 0));
  while (!pq.empty()) {
    int here = pq.top().first;
    int distToHere = pq.top().second;
    pq.pop();
    edge edges[3]{
        make_pair(here * 2, 0),
        make_pair(here + 1, 1),
        make_pair(here - 1, 1),
    };
    for (auto edge : edges) {
      int there = edge.first;
      if (here >= dest && there != here - 1) {
        continue;
      }
      int distToThere = distToHere + edge.second;
      if (dists[there] > distToThere) {
        dists[there] = distToThere;
        pq.push(make_pair(there, distToThere));
      }
    }
  }
  return dists[dest];
}

int main() {
  int n, k;
  cin >> n >> k;
  int minDist = search(n, k);
  cout << minDist << '\n';
  return 0;
}