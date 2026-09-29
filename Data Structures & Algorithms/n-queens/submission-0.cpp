class Solution {
public:
    void placeQueen(vector<string>& board, int row, int col) {
        int n = board.size();

        board[row] = "";

        for (int i = 0; i < col; i++) {
            board[row] += ".";
        }

        board[row] += "Q";

        for (int i = col + 1; i < n; i++) {
            board[row] += ".";
        }
    }

    void removeQueen(int row, vector<string>& board) {
        int n = board.size();
        board[row] = "";
        for (int i = 0; i < n; i++) {
            board[row] += ".";
        }
    }

    bool isSafe(int row, int col, vector<string>& board) {
        int n = board.size();

        for (int i = 0; i < col; i++) {
            string r = board[row];
            if (r[i] == 'Q') return false;
        }
        
        for (int i = 0; i < row; i++) {
            string r = board[i];
            if (r[col] == 'Q') return false;
        }

        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            string row_to_check = board[r];
            if (row_to_check[c] == 'Q') return false;

            r -= 1;
            c -= 1;
        }

        r = row - 1, c = col + 1;
        while (r >= 0 && c >= 0) {
            string row_to_check = board[r];
            if (row_to_check[c] == 'Q') return false;

            r -= 1;
            c += 1;
        }

        return true;
    }

    void findPossibleBoard(int row, 
                           vector<string> board, 
                           vector<vector<string>>& res) {

        int n = board.size();

        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                placeQueen(board, row, col);
                findPossibleBoard(row + 1, board, res);
                removeQueen(row, board);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res = {};

        vector<string> board(n, "");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i] += ".";
            }
        }

        findPossibleBoard(0, board, res);

        return res;
    }
};
