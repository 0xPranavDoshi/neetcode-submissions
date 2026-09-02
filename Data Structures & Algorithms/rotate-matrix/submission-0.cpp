class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();

        for (int i = 0; i < r/2; i++) {
            swap(matrix[i], matrix[r-1-i]);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
