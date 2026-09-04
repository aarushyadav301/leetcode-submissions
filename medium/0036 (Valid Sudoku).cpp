#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return (cellcheck(board) && columnchecking(board) && rowcheck(board));
    }

    bool cellcheck(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                
                unordered_set <char> cur;
                
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i + k][j + l] == '.') {
                            continue;
                        }

                        if (cur.count(board[i + k][j + l]) == 1) {
                            return (false);
                        }
                        cur.insert(board[i + k][j + l]);
                    }
                }
            }
        }

        return (true);
    }

    bool columnchecking(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            unordered_set <char> cur;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (cur.count(board[j][i]) == 1) {
                    return (false);
                }
                cur.insert(board[j][i]);
            }
        }

        return (true);
    }

    bool rowcheck(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            unordered_set <char> cur;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (cur.count(board[i][j]) == 1) {
                    return (false);
                }
                cur.insert(board[i][j]);
            }
        }

        return (true);
    }
};