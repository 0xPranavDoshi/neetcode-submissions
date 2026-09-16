class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true;
                    int area = 1;
                    q.push({i,j});
                    
                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();

                        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

                        for (pair<int,int> d : directions) {
                            int r = current.first + d.first, c = current.second + d.second;

                            if (r >= 0 && c >= 0 && r < m 
                                && c < n && grid[r][c] == 1 && !visited[r][c]) {
                                q.push({r,c});
                                visited[r][c] = true;
                                area++;
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
