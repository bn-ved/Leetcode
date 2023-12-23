#include <stack>
#include <vector>

using namespace std;

void immediateSmaller(vector<int> &a) {
  int n = a.size();
  stack<int> stk;
  stk.push(-1);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      stk.push(a[i + 1]);
    } else {
      stk.push(-1);
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = stk.top();
    stk.pop();
  }
}
