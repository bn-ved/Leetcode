#include <iostream>
#include <vector>

using namespace std;

class Queue {
  int *arr;
  int start;
  int end;
  int count;
  int size;

public:
  Queue() {
    arr = new int[5];
    start = -1;
    end = -1;
    count = 0;
    size = 5;
  }
  Queue(int size) {
    arr = new int[size];
    start = -1;
    end = -1;
    count = 0;
    (*this).size = size;
  }
  void push(int element) {
    if (count == size) {
      cout << "Queue is full"
           << "\n";
      exit(1);
    }
    if (end == -1) {
      start = 0;
      end = 0;
    } else {
      end = (end + 1) % size;
    }
    arr[end] = element;
    count++;
  }
  void pop() {
    if (start == -1) {
      cout << "Queue is empty"
           << "\n";
      exit(1);
    }
    if (size == 1) {
      start = -1;
      end = -1;
    } else {
      start = (start + 1) % size;
    }
    size--;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is empty"
           << "\n";
      exit(1);
    }
    return arr[start];
  }
  bool qSize() { return count; }
};
