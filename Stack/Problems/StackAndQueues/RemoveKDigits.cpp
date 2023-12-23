#include <string>

using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    string ans;
    for (char n : num) {
      while (!ans.empty() && ans.back() > n && k) {
        ans.pop_back();
        k--;
      }
      if (!ans.empty() || n != '0') {
        ans.push_back(n);
      }
    }
    while (k && !ans.empty()) {
      ans.pop_back();
      k--;
    }
    return ans == "" ? "0" : ans;
  }
};
