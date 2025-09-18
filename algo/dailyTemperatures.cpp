#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// 30,38,30,36,35,40,28
// 30
// {1}
// 38 {1}
// 38,30 {1}
// 38,36 {1,0,1}
// 38,36,35 {1,0,1}
// 38,36 {1,0,1,0,1,0,0}
// 38 {1,0,1,2,1,0,0}
// {1,4,1,2,1,0,0}
// 40 {1,4,1,2,1,0,0}
// 40,28 {1,4,1,2,1,0,0}

// 30,29,28,27,26,30
// 30
// 30,29
// 30,29,28,
// 30,29,28,27
// 30,29,28,27,26
// 30,29,28,27 {0, 0, 0, 0, 1, 0}
// 30,29,28 {0, 0, 0, 2, 1, 0}
// 30,29 {0, 0, 3, 2, 1, 0}
// 30 {0, 4, 3, 2, 1, 0}

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &nums) {
    if (nums.empty())
      return {};
    vector<int> res(nums.size());
    stack<pair<int, int>> st;
    for (size_t i = 0; i < nums.size(); i++) {
      while (!st.empty() && nums[i] > st.top().second) {
        size_t idx = st.top().first;
        res[idx] = i - idx;
        st.pop();
      }
      st.emplace(i, nums[i]);
    }
    return res;
  }
};

int main(void) {
  Solution sl;
  vector<int> a{30, 38, 30, 36, 35, 40, 28};
  auto res = sl.dailyTemperatures(a);
  for (auto x : res) {
    cout << x << ", ";
  }
  cout << endl;
}
