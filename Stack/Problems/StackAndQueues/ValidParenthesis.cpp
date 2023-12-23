#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        st.push(s[i]);
      } else if (!st.empty() && ((s[i] == ')' && st.top() == '(') ||
                                 (s[i] == ']' && st.top() == '[') ||
                                 (s[i] == '}' && st.top() == '{'))) {
        st.pop();
      } else {
        return false;
      }
    }
    return st.empty();
  }

public:
  int print(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      cout << i << "\n";
    }
    return 0;
  }
};
