class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        if (n == 0) return;

        // Swap the rows
        for (int i = 0; i < n/2; i++) {
            // swap row i with row m-1-i
            swap(matrix[i], matrix[n-1-i]);
        }

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {                                
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
