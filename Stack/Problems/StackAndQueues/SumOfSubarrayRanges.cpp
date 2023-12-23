#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  long long subArrayRanges_bruteForce(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int mini = nums[i];
      int maxi = nums[i];
      for (int j = i + 1; j < n; j++) {
        mini = min(mini, nums[j]);
        maxi = max(maxi, nums[j]);
        sum += (maxi - mini);
      }
    }
    return sum;
  }

public:
  long long subArrayRanges(vector<int> &nums) {
    int n = nums.size();
    long long ans = 0;
    stack<int> stk;

    // Find the sum of all the mininum
    for (int right = 0; right <= n; right++) {
      while (!stk.empty() && (right == n || nums[stk.top()] >= nums[right])) {
        int mid = stk.top();
        stk.pop();
        int left = stk.empty() ? -1 : stk.top();
        ans -= (long long)nums[mid] * (right - mid) * (mid - left);
      }
      stk.push(right);
    }

    stk.pop();
    // Find the sum of all the maximum
    for (int right = 0; right <= n; right++) {
      while (!stk.empty() && (right == n || nums[stk.top()] <= nums[right])) {
        int mid = stk.top();
        stk.pop();
        int left = stk.empty() ? -1 : stk.top();
        ans += (long long)nums[mid] * (right - mid) * (mid - left);
      }
      stk.push(right);
    }
    return ans;
  }
};
