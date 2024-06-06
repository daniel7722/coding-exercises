#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            if (!validRow(board, r)) return false;
        }
        for (int c = 0; c < 9; c++) {
            if (!validCol(board, c)) return false;
        }
        for (int b = 0; b < 9; b += 3) {
            for (int g = 0; g < 9; g += 3) {
                if (!validBox(board, b, g)) return false;
            }
        }
        return true;
    }

    bool validRow(vector<vector<char>>& board, int row_num) {
        unordered_set<int> s;
        for (int i = 0; i < 9; i++) {
            if (board[row_num][i] == '.') {
                continue;
            } else if (s.count(board[row_num][i]) != 0) {
                return false;
            }
            s.insert(board[row_num][i]);
        }
        return true;
    }

    bool validCol(vector<vector<char>>& board, int col_num) {
        unordered_set<int> s;
        for (int i = 0; i < 9; i++) {
            if (board[i][col_num] == '.') {
                continue;
            } else if (s.count(board[i][col_num]) != 0) {
                return false;
            }
            s.insert(board[i][col_num]);
        }
        return true;
    }
    bool validBox(vector<vector<char>>& board, int row, int col) {
        unordered_set<int> s;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[row + r][col + c] == '.') {
                    continue;
                } else if (s.count(board[row + r][col + c]) != 0) {
                    return false;
                }
                s.insert(board[row + r][col + c]);
            }
        }
        return true;
    }
};