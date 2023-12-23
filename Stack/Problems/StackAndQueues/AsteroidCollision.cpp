#include <vector>

using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> ans;
    for (int i : asteroids) {
      if (i > 0) { // if the asteroid is greater than 0
        ans.push_back(i);
      } else { // if the asteroid is less than 0
        // destory every positive asteroids.
        while (!ans.empty() && ans.back() > 0 && ans.back() < -i) {
          ans.pop_back();
        }
        if (!ans.empty() && ans.back() == -i) {
          // explode both asteroid if equal.
          ans.pop_back();
          // C++ Lazy or calculation so the order of conditional matters
        } else if (ans.empty() || ans.back() < 0) {
          ans.push_back(i);
        }
      }
    }
    return ans;
  }
};
