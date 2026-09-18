class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int,int>> pacific_q;
        queue<pair<int,int>> atlantic_q;

        for (int i = 0; i < m; i++) {
            pacific_q.push({i, 0});
            atlantic_q.push({i, n-1});
        }
        
        for (int i = 0; i < n; i++) {
            pacific_q.push({0, i});
            atlantic_q.push({m-1, i});
        }

        vector<vector<bool>> pv(m, vector<bool>(n, false));
        vector<vector<bool>> av(m, vector<bool>(n, false));

        while (!pacific_q.empty()) {
            auto [r,c] = pacific_q.front();
            pacific_q.pop();
            pv[r][c] = true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n 
                && heights[nr][nc] >= heights[r][c] && !pv[nr][nc]) {
                    pacific_q.push({nr,nc});
                }
            }
        }

        while (!atlantic_q.empty()) {
            auto [r,c] = atlantic_q.front();
            atlantic_q.pop();
            av[r][c] = true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n 
                && heights[nr][nc] >= heights[r][c] && !av[nr][nc]) {
                    atlantic_q.push({nr,nc});
                }
            }
        }        

        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pv[i][j] && av[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
