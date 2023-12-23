#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      // Remove the top elements if they are out of bounds (i > k)
      if (dq.size() && dq.front() == i - k) {
        dq.pop_front();
      }
      // Remove the back elements if the element is smaller than current
      while (dq.size() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      // Start pushing maximums when i >= k - 1
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};
