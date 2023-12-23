#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.length();
    stack<char> stk;
    vector<int> visited(26, 0);
    vector<int> freq(26, 0);
    string ans = "";

    // Keep track of frequency
    for (char c : s) {
      freq[c - 'a']++;
    }

    for (char c : s) {
      freq[c - 'a']--;
      if (visited[c - 'a']) {
        continue;
      }
      while (!stk.empty() && stk.top() > c && freq[stk.top() - 'a']) {
        char temp = stk.top();
        visited[temp - 'a'] = 0;
        stk.pop();
      }
      visited[c - 'a'] = 1;
      stk.push(c);
    }
    while (!stk.empty()) {
      ans = stk.top() + ans;
      stk.pop();
    }
    return ans;
  }
};
