#include <stack>

using namespace std;

// Monotone Stack.
class StockSpanner {
private:
  stack<pair<int, int>> stack_;

public:
  StockSpanner() {}

  int next(int price) {
    int span = 1;
    while (!stack_.empty() && price >= stack_.top().first) {
      span += stack_.top().second;
      stack_.pop();
    }
    stack_.push({price, span});
    return span;
  }
};
