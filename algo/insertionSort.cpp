#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void sortInsertion(vector<int> &v) {
    for (size_t i = 1; i < v.size(); i++) {
      int j = i;
      while (j > 0 && v[j - 1] > v[j]) {
        swap(v[j - 1], v[j]);
        j--;
      }
    }
  }
};

int main(void) {
  Solution sl;
  vector<int> a{9, 8, 7, 6, 5, 4, 3, 2, 1};
  sl.sortInsertion(a);
  for (auto x : a) {
    cout << x << " ";
  }
  cout << endl;
}
