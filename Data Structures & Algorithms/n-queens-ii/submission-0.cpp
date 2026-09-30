class Solution {
public:
    bool isSafe(int row, int col, vector<vector<bool>>& board) {        
        for (int i = 0; i < row; i++) {
            if (board[i][col]) return false;
        }

        int r = row-1, c = col-1;
        while (r >= 0 && c >= 0) {
            if (board[r][c]) return false;
            r--; c--;
        }

        r = row-1, c = col+1;
        while (r >= 0 && c < board.size()) {
            if (board[r][c]) return false;
            r--; c++;
        }

        return true;
    }

    void placeQueen(int row, int col, vector<vector<bool>>& board) {
        board[row][col] = true;
    }

    void removeQueen(int row, int col, vector<vector<bool>>& board) {
        board[row][col] = false;
    }

    void findArrangements(vector<vector<bool>> board, int row, int& solutions) {
        int n = board.size();

        if (row == n) {
            solutions++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (isSafe(row, c, board)) {
                placeQueen(row, c, board);
                findArrangements(board, row+1, solutions);
                removeQueen(row, c, board);
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));

        int solutions = 0;

        findArrangements(board, 0, solutions);

        return solutions;
    }
};