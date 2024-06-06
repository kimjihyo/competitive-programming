#include <cmath>
#include <iostream>
#include <utility>
using namespace std;

void heapifyDown(int index);
void minHeapifyDown(int index);
void maxHeapifyDown(int index);

int count = 0;               // the number of elements in the heap
long long heap[1'000'001]{}; // the heap

int getLevel(int index) { return log2(index); }

int findSmallestDescent(int index) {
  int left = index * 2;
  int right = index * 2 + 1;
  int grandLeft = index * 4;
  int grandRight = index * 4 + 1;
  int smallest = index;
  if (left <= count && heap[left] < heap[smallest]) {
    smallest = left;
  }
  if (right <= count && heap[right] < heap[smallest]) {
    smallest = right;
  }
  if (grandLeft <= count && heap[grandLeft] < heap[smallest]) {
    smallest = grandLeft;
  }
  if (grandRight <= count && heap[grandRight] < heap[smallest]) {
    smallest = grandRight;
  }
  return smallest;
}
int findLargestDescent(int index) {
  int left = index * 2;
  int right = index * 2 + 1;
  int grandLeft = index * 4;
  int grandRight = index * 4 + 1;
  int largest = index;
  if (left <= count && heap[left] > heap[largest]) {
    largest = left;
  }
  if (right <= count && heap[right] > heap[largest]) {
    largest = right;
  }
  if (grandLeft <= count && heap[grandLeft] > heap[largest]) {
    largest = grandLeft;
  }
  if (grandRight <= count && heap[grandRight] > heap[largest]) {
    largest = grandRight;
  }
  return largest;
}

void heapifyDown(int index) {
  if (getLevel(index) % 2 == 0) {
    minHeapifyDown(index);
  } else {
    maxHeapifyDown(index);
  }
}

void minHeapifyDown(int index) {
  if (index * 2 > count)
    return;
  int smallest = findSmallestDescent(index);
  if (smallest >= index * 4) {
    if (heap[smallest] < heap[index]) {
      swap(heap[smallest], heap[index]);
      index = smallest;
      if (heap[index] > heap[index / 2]) {
        swap(heap[index], heap[index / 2]);
        index = index / 2;
      }
      heapifyDown(index);
    }
  } else if (smallest >= index * 2) {
    if (heap[smallest] < heap[index]) {
      swap(heap[smallest], heap[index]);
    }
  }
}

void maxHeapifyDown(int index) {
  if (index * 2 > count)
    return;
  int largest = findLargestDescent(index);
  if (largest >= index * 4) {
    if (heap[largest] > heap[index]) {
      swap(heap[largest], heap[index]);
      index = largest;
      if (heap[index] < heap[index / 2]) {
        swap(heap[index], heap[index / 2]);
        index = index / 2;
      }
      heapifyDown(index);
    }
  } else if (largest >= index * 2) {
    if (heap[largest] > heap[index]) {
      swap(heap[largest], heap[index]);
    }
  }
}

void minHeapifyUp(int index) {
  if (index < 4)
    return;
  if (heap[index] < heap[index / 4]) {
    swap(heap[index], heap[index / 4]);
    minHeapifyUp(index / 4);
  }
}

void maxHeapifyUp(int index) {
  if (index < 4)
    return;
  if (heap[index] > heap[index / 4]) {
    swap(heap[index], heap[index / 4]);
    maxHeapifyUp(index / 4);
  }
}

void insert(long long value) {
  heap[++count] = value;
  if (count == 1)
    return;
  int index = count;
  if (getLevel(index) % 2 == 0) {
    if (heap[index] > heap[index / 2]) {
      swap(heap[index], heap[index / 2]);
      maxHeapifyUp(index / 2);
    } else {
      minHeapifyUp(index);
    }
  } else {
    if (heap[index] < heap[index / 2]) {
      swap(heap[index], heap[index / 2]);
      minHeapifyUp(index / 2);
    } else {
      maxHeapifyUp(index);
    }
  }
}

void popMin() {
  if (count == 0)
    return;
  heap[1] = heap[count--];
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
  else {
    if (heap[2] > heap[3])
      index = 2;
    else
      index = 3;
  }
  heap[index] = heap[count--];
  heapifyDown(index);
}

long long seekMin() { return heap[1]; }

long long seekMax() {
  if (count == 0 || count == 1)
    return heap[1];
  if (count == 2)
    return heap[2];
  else {
    return max(heap[2], heap[3]);
  }
}

void print() {
  for (int i = 0; i < 15; i++) {
    cout << heap[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int t0 = 0; t0 < t; t0++) {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      char o;
      long long val;
      cin >> o >> val;
      if (o == 'I') {
        insert(val);
      }
      if (o == 'D') {
        if (val == 1) {
          popMax();
        } else {
          popMin();
        }
      }
    }
    if (count == 0) {
      cout << "EMPTY\n";
    } else {
      cout << seekMax() << ' ' << seekMin() << '\n';
    }
    count = 0;
  }
  return 0;
}