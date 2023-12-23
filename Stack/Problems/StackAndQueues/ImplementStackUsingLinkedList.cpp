#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int n) : data(n), next(NULL) {}
};

class Stack {
private:
  Node *top;

public:
  Stack() { top = NULL; }
  bool isEmpty() { return top == NULL; }
  void push(int data) {
    Node *temp = new Node(data);

    if (!temp) {
      cout << "\nStack Overflow";
      exit(1);
    }
    temp->next = top;
    top = temp;
  }
  int peek() {
    if (!isEmpty()) {
      return top->data;
    }
    return -1;
  }
  void pop() {
    if (!isEmpty()) {
      Node *temp = top;
      top = top->next;
      free(temp);
    } else {
      cout << "Stack Overflow"
           << "\n";
    }
  }
};

int main() {
  Stack s;

  for (int i = 1; i <= 10; i++) {
    s.push(i);
  }

  while (!s.isEmpty()) {
    cout << s.peek() << "\n";
    s.pop();
  }
}
