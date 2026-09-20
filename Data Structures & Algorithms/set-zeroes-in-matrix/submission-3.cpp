class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<bool> zeroedRows(m, false);
        vector<bool> zeroedCols(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (matrix[i][j] == 0) {                                        
                    zeroedRows[i] = true;
                    zeroedCols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (zeroedRows[i] == true || zeroedCols[j] == true) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
