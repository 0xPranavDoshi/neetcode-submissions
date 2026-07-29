class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        int rows = matrix.size();

        int l = 0;
        int r = rows - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (find(matrix[m].begin(), matrix[m].end(), target) != matrix[m].end()) {
                row = m;
                break;
            }

            if (target < matrix[m][0]) r = m - 1;
            else l = m + 1;
        }

        if (row == -1) return false;

        return true;
    }
};
