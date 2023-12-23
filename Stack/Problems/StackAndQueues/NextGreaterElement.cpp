#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement_bruteForce(vector<int> &nums1,
                                            vector<int> &nums2) {
    stack<int> stk;
    stack<int> temp;
    vector<int> ans;
    for (int i = 0; i < nums2.size(); i++)
      stk.push(nums2[i]);

    for (int i = 0; i < nums1.size(); i++) {
      int last = -1;
      while (stk.top() != nums1[i]) {
        if (stk.top() > nums1[i])
          last = stk.top();
        temp.push(stk.top());
        stk.pop();
      }

      if (last >= stk.top())
        ans.push_back(last);
      else
        ans.push_back(-1);

      while (!temp.empty()) {
        stk.push(temp.top());
        temp.pop();
      }
    }
    return ans;
  }
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int n = nums2.size();
    stack<int> stk;
    unordered_map<int, int> mpp;
    for (int i = n - 1; i >= 0; i--) {
      while (!stk.empty() && nums2[i] > stk.top())
        stk.pop();

      if (stk.empty()) {
        mpp[nums2[i]] = -1;
        stk.push(nums2[i]);
      } else {
        mpp[nums2[i]] = stk.top();
        stk.push(nums2[i]);
      }
    }
    vector<int> ans;
    for (int x : nums1) {
      if (mpp.find(x) != mpp.end())
        ans.push_back(mpp[x]);
      else
        ans.push_back(-1);
    }
    return ans;
  }
};
