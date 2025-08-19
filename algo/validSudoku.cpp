#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool sudokuInsert(char c, unordered_set<char> &s) {
    if (c == '.')
      return true;
    if (s.insert(c).second == false)
      return false;
    return true;
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    if (board.size() != 9)
      return false;
    unordered_set<char> s(9);
    for (int i = 0; i < 9; i++) {
      vector<char> const &row = board[i];
      if (row.size() != 9)
        return false;
      for (char c : row) {
        if (!sudokuInsert(c, s))
          return false;
      }
      s.clear();
      for (int j = 0; j < 9; j++) {
        if (!sudokuInsert(board[j][i], s))
          return false;
      }
      s.clear();
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          std::cout << j + i / 3 << " " << k << "; ";
          char c = board[j + i / 3][k];
          if (!sudokuInsert(c, s))
            return false;
        }
      }
      cout << endl;
      s.clear();
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
      {'7', '.', '.', '.', '2', '8', '.', '.', '6'},
      {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  Solution sl;
  std::cout << sl.isValidSudoku(board);
}
