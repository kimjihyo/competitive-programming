// min-max heap
// odd level is min heap
// even level is max heap
#include <cmath>
#include <iostream>
#include <utility>
using namespace std;

void minHeapifyDown(int index);
void maxHeapifyDown(int index);
void heapifyDown(int index);

int count = 0;
long long arr[1'000'001];

void printArr() {
  for (int i = 1; i < 10; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

int getLevel(int index) { return log2(index); }
bool isMinLevel(int index) { return getLevel(index) % 2 == 0; }

void minHeapifyUp(int index) {
  if (index < 4)
    return;
  if (arr[index] < arr[index / 4]) {
    swap(arr[index], arr[index / 4]);
    minHeapifyUp(index / 4);
  }
}

void maxHeapifyUp(int index) {
  if (index < 4)
    return;
  if (arr[index] > arr[index / 4]) {
    swap(arr[index], arr[index / 4]);
    maxHeapifyUp(index / 4);
  }
}

void heapifyUp(int index) {
  if (index == 1)
    return;
  if (isMinLevel(index)) {
    if (arr[index] > arr[index / 2]) {
      swap(arr[index], arr[index / 2]);
      maxHeapifyUp(index / 2);
    } else {
      minHeapifyUp(index);
    }
  } else {
    if (arr[index] < arr[index / 2]) {
      swap(arr[index], arr[index / 2]);
      minHeapifyUp(index / 2);
    } else {
      maxHeapifyUp(index);
    }
  }
}

int getSmallest(int index) {
  int resultIndex = index * 2;
  long long resultValue = arr[index * 2];
  int indices[] = {
      index * 2 + 1, index * 4, index * 4 + 1, index * 4 + 2, index * 4 + 3,
  };

  for (auto i : indices) {
    if (i <= count) {
      resultValue = min(resultValue, arr[i]);
      if (resultValue == arr[i])
        resultIndex = i;
    }
  }
  return resultIndex;
}
int getLargest(int index) {
  int resultIndex = index * 2;
  long long resultValue = arr[index * 2];
  int indices[] = {
      index * 2 + 1, index * 4, index * 4 + 1, index * 4 + 2, index * 4 + 3,
  };

  for (auto i : indices) {
    if (i <= count) {
      resultValue = max(resultValue, arr[i]);
      if (resultValue == arr[i])
        resultIndex = i;
    }
  }
  return resultIndex;
}

void heapifyDown(int index) {
  if (isMinLevel(index)) {
    minHeapifyDown(index);
  } else {
    maxHeapifyDown(index);
  }
}

void minHeapifyDown(int index) {
  if (index * 2 > count)
    return;
  int smallest = getSmallest(index);
  if (smallest >= index * 4) {
    if (arr[smallest] < arr[index]) {
      swap(arr[smallest], arr[index]);
      if (arr[smallest] > arr[smallest / 2]) {
        swap(arr[smallest], arr[smallest / 2]);
      }
      minHeapifyDown(smallest);
    }
  } else if (arr[smallest] < arr[index]) {
    swap(arr[smallest], arr[index]);
  }
}

void maxHeapifyDown(int index) {
  if (index * 2 > count)
    return;
  int largest = getLargest(index);
  if (largest >= index * 4) {
    if (arr[largest] > arr[index]) {
      swap(arr[largest], arr[index]);
      if (arr[largest] < arr[largest / 2]) {
        swap(arr[largest], arr[largest / 2]);
      }
      maxHeapifyDown(largest);
    }
  } else if (arr[largest] > arr[index]) {
    swap(arr[largest], arr[index]);
  }
}

void insert(long long value) {
  arr[++count] = value;
  heapifyUp(count);
}

void popMin() {
  if (count == 0)
    return;
  arr[1] = arr[count--];
  heapifyDown(1);
}

void popMax() {
  if (count == 0)
    return;
  int index = 1;
  if (count == 1)
    index = 1;
  if (count == 2)
    index = 2;
  if (count >= 3) {
    if (arr[2] > arr[3]) {
      index = 2;
    } else {
      index = 3;
    }
  }
  arr[index] = arr[count--];
  heapifyDown(index);
}

long long seekMin() { return arr[1]; }

long long seekMax() {
  int index = 1;
  if (count == 1)
    index = 1;
  if (count == 2)
    index = 2;
  if (count >= 3) {
    if (arr[2] > arr[3]) {
      index = 2;
    } else {
      index = 3;
    }
  }
  return arr[index];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int q;
    cin >> q;
    for (int j = 0; j < q; j++) {
      char a;
      long long b;
      cin >> a >> b;
      if (a == 'I') {
        insert(b);
      } else if (a == 'D') {
        if (b < 0) {
          popMin();
        } else {
          popMax();
        }
      }
    }
    if (count == 0)
      cout << "EMPTY\n";
    else
      cout << seekMax() << ' ' << seekMin() << '\n';
    count = 0;
  }
  return 0;
}