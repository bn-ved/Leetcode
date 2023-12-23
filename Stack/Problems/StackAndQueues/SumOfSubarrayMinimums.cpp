#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int sumSubarrayMins_bruteForce(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int mini = arr[i];
      for (int j = i; j < n; j++) {
        mini = min(mini, arr[j]);
        ans += mini;
        ans %= mod;
      }
    }
    return ans % mod;
  }

public:
  int sumSubarrayMins_better(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    int sum = 0;
    int mod = 1e9 + 7;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < n; i++) {
      sum = (sum + arr[i]) % mod;
      while (stk.top() != -1 && arr[stk.top()] >= arr[i]) {
        int j = stk.top();
        stk.pop();
        int c = j - stk.top();
        sum = (sum + c * (arr[i] - arr[j]) % mod) % mod;
      }
      stk.push(i);
      ans = (ans + sum) % mod;
    }
    return ans;
  }

public:
  int sumSubarrayMins(vector<int> &arr) {
    // Monotonic Stack
    int n = arr.size();
    stack<pair<int, int>> left;
    stack<pair<int, int>> right;
    vector<int> leftArray(n, 0);
    vector<int> rightArray(n, 0);
    int ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int count = 1;
      while (!left.empty() && arr[i] < left.top().first) {
        count += left.top().second;
        left.pop();
      }
      left.push({arr[i], count});
      leftArray[i] = count;
    }
    for (int i = n - 1; i >= 0; i--) {
      int count = 1;
      while (!right.empty() && arr[i] <= right.top().first) {
        count += right.top().second;
        right.pop();
      }
      right.push({arr[i], count});
      rightArray[i] = count;
    }
    for (int i = 0; i < n; i++) {
      ans = (ans + ((long long)arr[i] * leftArray[i] * rightArray[i]) % mod) %
            mod;
    }
    return (int)(ans % mod);
  }
};
