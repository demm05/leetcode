#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int longest = 0;
    unordered_set<int> s(nums.begin(), nums.end(), nums.size());
    for (int x : s) {
      if (s.count(x - 1))
        continue;
      int temp = x;
      while (s.count(temp + 1)) {
        temp++;
      }
      int sub_longest = temp - x + 1;
      if (sub_longest > longest)
        longest = sub_longest;
    }
    return longest;
  }
};

int main(void) {
  Solution sl;
  vector<int> a{0, 3, 2, 5, 4, 6, 1, 1};
  cout << sl.longestConsecutive(a) << endl;
}
