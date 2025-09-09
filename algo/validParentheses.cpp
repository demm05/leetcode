#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  static inline bool matchParentheses(char o, char c) {
    return (o == '{' && c == '}') || (o == '[' && c == ']') ||
           (o == '(' && c == ')');
  }

  static inline bool isClosing(char c) {
    return c == '}' || c == ']' || c == ')';
  }

  static inline bool isOpening(char c) {
    return c == '[' || c == '{' || c == '(';
  }

  bool isValid(string s) {
    stack<char> st;
    for (auto it = s.begin(); it != s.end(); ++it) {
      if (isClosing(*it)) {
        if (st.empty() || !matchParentheses(st.top(), *it))
          return false;
        st.pop();
      } else if (isOpening(*it))
        st.push(*it);
      else
        return false;
    }
    return st.empty();
  }
};

int main() {
  Solution sl;
  cout << sl.isValid("[][[{()}]]") << endl;
}
