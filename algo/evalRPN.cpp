#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isAllDigit(string const &s) {
    if (s.empty())
      return false;
    auto it = s.begin();
    if (*it == '-' && s.size() != 1)
      it++;
    return all_of(it, s.end(), ::isdigit);
  }

  int evalRPN(vector<string> &tokens) {
    stack<int> s;
    int res = 0;
    for (auto const &x : tokens) {
      if (isAllDigit(x.c_str())) {
        s.push(stoi(x));
        // cout << s.top() << "->" << endl;
      }
      else if (s.size() >= 2 && x.size() == 1) {
        int b = s.top(); s.pop();
        int a = s.top(); s.pop();
        // cout << a << " " << x << " " << b << endl;
        char op = x[0];
        switch (op) {
          case '+': res = a + b; break;
          case '-': res = a - b; break;
          case '*': res = a * b; break;
          case '/': { if (b == 0) return res; res = a / b; break; }
          default: return res;
        } 
        s.push(res);
      }
      else
        break;
    }
    if (!s.empty())
      return s.top();
    return res;
  }
};

int main(void) {
  Solution sl;
  vector<string> a{"1","2","+","3","*","4","-"};

  std::cout << sl.evalRPN(a) << std::endl;
}
