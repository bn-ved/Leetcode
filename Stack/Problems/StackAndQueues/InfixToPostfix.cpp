#include <iostream>
#include <stack>

using namespace std;

int precedence(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '/' || c == '*') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  } else {
    return -1;
  }
}

string infixToPostfix(string s) {
  stack<char> stk;
  string result;

  for (int c : s) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9')) {
      result += c;
    } else if (c == '(') {
      stk.push('(');
    } else if (c == ')') {
      while (stk.top() != '(') {
        result += stk.top();
        stk.pop();
      }
      stk.pop();
    } else {
      while (!stk.empty() && precedence(c) <= precedence(stk.top())) {
        result += stk.top();
        stk.pop();
      }
      stk.push(c);
    }
  }
  while (!stk.empty()) {
    result += stk.top();
    stk.pop();
  }
  return result;
}
