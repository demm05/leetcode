#include <iostream>
#include <vector>

using namespace std;

// Input: nums =	[1,2,3,4]
// First for loop:  [1,1,2,6]
// Second with res: [24,12,4,1]
// Output: 			[24,12,8,6]

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size());
    int prev = 1;
    for (size_t i = 0; i < nums.size(); i++) {
      res[i] = prev;
      prev *= nums[i];
    }
    prev = 1;
    for (size_t i = nums.size(); i > 0; i--) {
      res[i - 1] *= prev;
      prev *= nums[i - 1];
    }
    return res;
  }
};

int main(void) {
  Solution sl;
  vector<int> a{1, 2, 3, 4};
  auto res = sl.productExceptSelf(a);
  for (auto x : res) {
    std::cout << x << " ";
  }
}
