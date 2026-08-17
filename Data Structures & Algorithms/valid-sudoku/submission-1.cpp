class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> dups;
        for (int i = 0; i < 9; i++) {
            dups.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;                
                if (dups.count(board[i][j])) return false;
                dups.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            dups.clear();
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (dups.count(board[j][i])) return false;
                dups.insert(board[j][i]);
            }
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dups.clear();
                cout << "clearing\n";
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i*3 + k][3*j + l] == '.') continue;
                        cout << "checking board at [" << i*3 + k << "][" << i*3 + l << "]\n";
                        if (dups.count(board[i*3 + k][3*j + l])) return false;
                        dups.insert(board[3*i + k][3*j + l]);
                    }
                }
            }   
        }

        return true;
    }
};
