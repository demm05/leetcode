#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  static inline bool sudokuInsert(char c, unordered_set<char> &s) {
    return (s.insert(c).second);
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<int, unordered_set<char>> cols_set(9);
    unordered_map<int, unordered_set<char>> boxes_set(9);
    unordered_set<char> row_set;

    for (int r = 0; r < 9; r++) {
      if (board[r].size() != 9)
        return false;
      for (int c = 0; c < 9; c++) {
        char ch = board[r][c];
        if (ch == '.')
          continue;
        if (!sudokuInsert(ch, row_set) || !sudokuInsert(ch, cols_set[c]) ||
            !sudokuInsert(ch, boxes_set[(r / 3) * 10 + (c / 3)]))
          return false;
      }
      row_set.clear();
    }
    return true;
  }
};

int main(void) {
  std::vector<std::vector<char>> board = {
      {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
      {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
      {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
      {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  Solution sl;
  std::cout << sl.isValidSudoku(board);
}
