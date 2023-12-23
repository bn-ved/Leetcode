#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
  stack<int> mainQueue;
  stack<int> temp;
  MyQueue() {}

  void push(int x) {
    while (!mainQueue.empty()) {
      temp.push(mainQueue.top());
      mainQueue.pop();
    }
    temp.push(x);
    while (!temp.empty()) {
      mainQueue.push(temp.top());
      temp.pop();
    }
  }

  int pop() {
    int topElement = mainQueue.top();
    mainQueue.pop();
    return topElement;
  }

  int peek() { return mainQueue.top(); }

  bool empty() { return mainQueue.empty(); }
};
