#include "00. leetcode.h"

// 回溯，递归的终止条件是索引越界或字符不匹配，或找到了路径
// 注意破坏现场后要记得复原

class Solution {
 public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (dfs(board, word, i, j, 0)) return true;
      }
    }
    return false;
  }

 private:
  bool dfs(vector<vector<char>> &board, string word, int i, int j, int idx) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
        board[i][j] != word[idx])
      return false;
    if (idx == word.size() - 1) return true;

    char tmp = board[i][j];
    board[i][j] = '\0';
    if (dfs(board, word, i + 1, j, idx + 1) ||
        dfs(board, word, i, j + 1, idx + 1) ||
        dfs(board, word, i - 1, j, idx + 1) ||
        dfs(board, word, i, j - 1, idx + 1))
      return true;
    board[i][j] = tmp;
    return false;
  }
};
