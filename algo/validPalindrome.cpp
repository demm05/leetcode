#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0;
    int r = s.size() - 1;
    while (i < r) {
      while (i < r && !isalnum(s[i]))
        i++;
      while (r > i && !isalnum(s[r]))
        r--;
      if (tolower(s[i++]) != tolower(s[r--]))
        return false;
    }
    return true;
  }
};

int main() {
  Solution sl;
  cout << sl.isPalindrome("a.") << endl;
}
