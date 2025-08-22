#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    array<int, 26> ar{0};
    for (size_t i = 0; i < s.size(); i++) {
      ar[s[i] - 'a']++;
      ar[t[i] - 'a']--;
    }
    for (auto x : ar) {
      if (x != 0)
        return false;
    }
    return true;
  }
};

int main() {
  Solution sl;
  cout << sl.isAnagram("anagram", "nagaram") << endl;
}
