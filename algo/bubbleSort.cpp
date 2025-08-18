#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  // O(n^2)
  void sortBubble(vector<int> &nums) {
    bool sorted = false;
    size_t sortet_untill = nums.size();
    while (!sorted) {
      sorted = true;
      for (size_t i = 1; i < sortet_untill; i++) {
        if (nums[i - 1] > nums[i]) {
          swap(nums[i], nums[i - 1]);
          sorted = false;
        }
      }
      sortet_untill--;
    }
  }
};

Solution sl;

int main(void) {
  vector<int> a {1, 0};
  sl.sortBubble(a);
  for (auto x: a) {
    cout << x << " ";
  }
  cout << endl;
}
