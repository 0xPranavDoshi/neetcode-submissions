class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of cols

        // Use binary search to find the row

        int row = -1;
        int t = 0, b = m - 1;
        while (t <= b) {
            int m = t + (b - t) / 2;
            if (target >= matrix[m][0] && target <= matrix[m][n-1]) {
                // target exists in this row
                row = m;
                break;        
            }

            if (target < matrix[m][0]) {
                b = m - 1;
            } else {
                t = m + 1;
            }
        }

        if (row == -1) return false;

        // Then use binary search again to find the element

        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (target == matrix[row][m]) {
                return true;
            } else if (target < matrix[row][m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
};
