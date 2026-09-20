class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // vector<bool> zeroedRows(m, false);
        // vector<bool> zeroedCols(n, false);
        vector<int> zeroedRows;
        vector<int> zeroedCols;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (matrix[i][j] == 0) {                                        
                    zeroedRows.push_back(i);
                    zeroedCols.push_back(j);
                    // zeroedCols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // if i is in array zeroedRows OR j is is the array zeroedCols, make it 0
                if (find(zeroedRows.begin(), zeroedRows.end(), i) != zeroedRows.end()
                 || find(zeroedCols.begin(), zeroedCols.end(), j) != zeroedCols.end()) {
                    matrix[i][j] = 0;
                 }
            }
        }
    }
};
