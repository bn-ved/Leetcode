#include <vector>

using namespace std;

class Solution {
public:
  int trap_bruteForce(vector<int> &height) {
    int n = height.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
      int j = i;
      int leftMax = 0;
      int rightMax = 0;
      while (j >= 0)
        leftMax = max(leftMax, height[j--]);
      j = i;
      while (j < n)
        rightMax = max(rightMax, height[j++]);
      waterTrapped += min(leftMax, rightMax) - height[i];
    }
    return waterTrapped;
  }

public:
  int trap_better(vector<int> &height) {
    int n = height.size();
    int waterTrapped = 0;
    int prefix[n];
    int suffix[n];
    prefix[0] = height[0];
    suffix[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
      prefix[i] = max(prefix[i - 1], height[i]);
    for (int i = n - 2; i >= 0; i--)
      suffix[i] = max(suffix[i + 1], height[i]);
    for (int i = 0; i < n; i++) {
      waterTrapped += min(prefix[i], suffix[i]) - height[i];
    }
    return waterTrapped;
  }

public:
  int trap(vector<int> &height) {
    int n = height.size();
    int leftMax = 0;
    int rightMax = 0;
    int waterTrapped = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] >= leftMax)
          leftMax = height[left++];
        else
          waterTrapped += leftMax - height[left++];
      } else {
        if (height[right] >= rightMax)
          rightMax = height[right--];
        else
          waterTrapped += rightMax - height[right--];
      }
    }
    return waterTrapped;
  }
};
