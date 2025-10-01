#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 1,7,2,5,4,7,3,6
// 1,7 1 1
// 2,7 1 4
// 5,7 2 10
// 4,7 3 12
// 7,7 4 28
// 3,7 5 15
// 6,7 6 36

struct p {
  int x;
  int pos;
};

class Solution {
public:
  int maxArea(vector<int> &heights) {
    if (heights.empty())
      return 0;
    else if (heights.size() == 1)
      return heights[0];
    p min{heights[0]};
    p max;
  }
};

int main(void) {
  Solution sl;
  vector<int> a{30, 38, 30, 36, 35, 40, 28};
  cout << sl.maxArea(a) << endl;
}
