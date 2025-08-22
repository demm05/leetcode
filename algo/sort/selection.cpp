#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void sortSelection(vector<int> &v) {
    for (size_t i = v.size() - 1; i > 0; i--) {
      size_t max_inx = i;
      for (size_t j = 0; j < i; j++) {
        if (v[j] > v[max_inx])
          max_inx = j;
      }
      swap(v[max_inx], v[i]);
    }
  }
};

int main(void) {
  Solution sl;
  vector<int> a{9, 8, 7, 6, 5, 4, 3, 2, 1};
  sl.sortSelection(a);
  for (auto x : a) {
    cout << x << " ";
  }
  cout << endl;
}
