#include <bits/stdc++.h>
#include <limits>

using namespace std;

class MinStack {
public:
  MinStack() : min_(numeric_limits<int>::max()) {}

  void push(int val) {
    if (val < min_) {
      min_ = val;
    }
    values_.push(val);
    minValues_.push(min_);
  }

  void pop() {
    if (values_.empty())
      return;
    values_.pop();
    minValues_.pop();
    if (values_.empty())
      min_ = numeric_limits<int>::max();
    else
      min_ = minValues_.top();
  }

  int top() { return values_.top(); }

  int getMin() { return minValues_.top(); }

private:
  int min_;
  stack<int> values_;
  stack<int> minValues_;
};

int main() {
  MinStack s;
  s.push(10);
  s.pop();
  s.push(20);
  cout << s.top() << endl;
  s.push(-20);
  cout << s.getMin() << endl;
}
