class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();    

        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();

            for (auto [dr, rc] : dirs) {
                int r = cr+dr, c = cc + rc;

                if (r >= 0 && c >= 0 && c < n && r < m && grid[r][c] == INT_MAX) {
                    grid[r][c] = grid[cr][cc] + 1;
                    q.push({r,c});
                }
            }
        }
    }   
};
