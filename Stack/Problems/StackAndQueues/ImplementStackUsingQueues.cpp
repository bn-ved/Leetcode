#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class MyStack {
public:
  queue<int> mainQueue;
  queue<int> temp;

  MyStack() {}

  void push(int x) {
    temp.push(x);
    while (!mainQueue.empty()) {
      temp.push(mainQueue.front());
      mainQueue.pop();
    }
    swap(mainQueue, temp);
  }

  int pop() {
    int topElement = mainQueue.front();
    mainQueue.pop();
    return topElement;
  }

  int top() { return mainQueue.front(); }

  bool empty() { return mainQueue.empty(); }
};
