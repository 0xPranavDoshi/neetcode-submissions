class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;

        int top = 0, right = cols, bottom = rows, left = 0;
        
        while (top < bottom && left < right) {
            for (int i = left; i < right; i++) {
                cout << matrix[top][i] << " ";
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i < bottom; i++) {
                cout << matrix[i][right - 1] << " ";
                res.push_back(matrix[i][right - 1]);                
            }
            right--;

            if (!(left < right && top < bottom)) {
                break;
            }

            for (int i = right - 1; i >= left; i--) {
                cout << matrix[bottom - 1][i] << " ";
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;

            for (int i = bottom - 1; i >= top; i--) {
                cout << matrix[i][left] << " ";
                res.push_back(matrix[i][left]);
            }            
            left++;
        }

        return res;
    }
};
