class Solution {
private:
    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    // This is land
                    q.push({i,j});
                    visited[i][j] = true;
                    int area = 0;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        area++;

                        for (auto [dr, dc] : dirs) {
                            int row = dr + r;
                            int col = dc + c;

                            if (isValid(row, col, m, n)
                                && grid[row][col] == 1
                                && !visited[row][col]) {

                                q.push({row, col});
                                visited[row][col] = true;
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
