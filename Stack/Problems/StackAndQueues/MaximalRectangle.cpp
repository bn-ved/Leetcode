#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangle(vector<int> &heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> stk;
    for (int i = 0; i <= n; i++) {
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

public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int maxArea = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        heights[j] = matrix[i][j] == '1' ? ++heights[j] : 0;
      }
      maxArea = max(maxArea, largestRectangle(heights));
    }
    return maxArea;
  }
};
