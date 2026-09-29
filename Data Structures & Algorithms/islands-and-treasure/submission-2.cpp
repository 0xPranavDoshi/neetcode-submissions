class Solution {
private:
    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = pow(2,31) - 1;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();            

            for (const auto& [dr, dc] : dirs) {
                if (isValid(dr+r, dc+c, m, n)                     
                    && grid[dr+r][dc+c] == INT_MAX) {
                                    
                    grid[dr+r][dc+c] = grid[r][c] + 1;
                    q.push({dr+r, dc+c});
                }
            }
        }
    }
};
