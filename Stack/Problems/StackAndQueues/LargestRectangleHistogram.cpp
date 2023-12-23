#include <climits>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public: // Brute Force
  int largestRectangleArea_bruteForce(vector<int> &heights) {
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
      int minHeight = INT_MAX;
      for (int j = i; j < heights.size(); j++) {
        minHeight = min(minHeight, heights[j]);
        maxArea = max(maxArea, minHeight * j - i);
      }
    }
    return maxArea;
  }

public: // Better using Next Smaller Element and Previous Smaller Element
  int largestRectangleArea_better(vector<int> &heights) {
    int n = heights.size();
    stack<int> stk;
    int left[n];
    int right[n];
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && heights[stk.top()] >= heights[i]) {
        stk.pop();
      }
      if (stk.empty()) {
        left[i] = 0;
      } else {
        left[i] = stk.top() + 1;
      }
      stk.push(i);
    }

    while (!stk.empty()) {
      stk.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && heights[stk.top()] >= heights[i]) {
        stk.pop();
      }
      if (stk.empty()) {
        right[i] = n - 1;
      } else {
        right[i] = stk.top() - 1;
      }
      stk.push(i);
    }
    for (int i = 0; i < n; i++) {
      maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
    }
    return maxArea;
  }

public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> stk;
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
      while (!stk.empty() && (i == n || heights[stk.top()] >= heights[i])) {
        int height = heights[stk.top()];
        stk.pop();
        int width = stk.empty() ? i : i - stk.top() - 1;
        maxArea = max(maxArea, width * height);
      }
      stk.push(i);
    }
    return maxArea;
  }
};
