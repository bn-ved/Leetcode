#include <iostream>

using namespace std;

#define MAX_SIZE 10
class Stack {
private:
  int top;
  int arr[MAX_SIZE];

public:
  Stack() { top = -1; }
  bool isEmpty() { return top == -1; }
  bool isFull() { return top == MAX_SIZE; }
  void push(int data) {
    if (!isFull()) {
      top++;
      this->arr[top] = data;
    } else {
      cout << "Stack is Full."
           << "\n";
    }
  }
  void pop() {
    if (!isEmpty()) {
      this->arr[top] = 0;
      top--;
    } else {
      cout << "Stack is empty"
           << "\n";
    }
  }
  int top_element() {
    if (!isEmpty()) {
      return this->arr[top];
    } else {
      return -1;
    }
  }
};

int main() {
  Stack s;

  for (int i = 1; i <= 5; i++) {
    s.push(i);
  }

  while (!s.isEmpty()) {
    cout << s.top_element() << "\n";
    s.pop();
  }
}
