class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {        
        unordered_set<int> s;

        // Rows
        for (int i = 0; i < 9; i++) {
            s.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (s.count(board[i][j])) {
                    cout << "found [" << i << "][" << j << "]\n";
                    return false;
                } else {
                    s.insert(board[i][j]);
                }
            }
        }

        cout << "rows clear\n";

        // Cols
        for (int i = 0; i < 9; i++) {
            s.clear();
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (s.count(board[j][i])) {
                    cout << "found [" << i << "][" << j << "]\n";
                    return false;
                } else {
                    s.insert(board[j][i]);
                }
            }
        }

        cout << "cols clear\n";
        
        for (int a = 0; a < 3; a++) {            
            for (int i = 0; i < 3; i++) {
                s.clear();
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (board[j + 3*i][k + 3*a] == '.') continue;
                        if (s.count(board[j + 3*i][k + 3*a])) {
                            cout << "found [" << i << "][" << j << "]\n";
                            return false;
                        } else {
                            s.insert(board[j + 3*i][k + 3*a]);
                        }
                    }
                }
            }
        }

        return true;
    }
};
