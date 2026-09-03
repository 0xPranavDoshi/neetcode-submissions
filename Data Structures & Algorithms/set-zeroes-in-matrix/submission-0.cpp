class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> rowsZero(rows, false);
        vector<bool> colsZero(cols, false);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    rowsZero[i] = true;
                    colsZero[j] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (rowsZero[i] || colsZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }        
    }
};
