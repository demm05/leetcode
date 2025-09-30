
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// 1 3 4 6

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum == target)
        return {l + 1, r + 1};
      else if (sum > target) {
        r--;
      } else
        l++;
    }
    return {};
  }
};

int main() {
  Solution sl;
  vector<int> t{1, 2, 3, 4, 5};
  vector<int> a = sl.twoSum(t, 3);
  cout << a.size() << endl;
  if (a.size() >= 2)
    cout << a[0] << " " << a[1] << endl;
}
