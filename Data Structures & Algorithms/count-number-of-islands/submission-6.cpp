class Solution {
private: 
    bool isValid(int r, int c, int rows, int cols) {
        return (r < rows && r >= 0 && c < cols && c >= 0);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for (const auto& [dr, dc] : dirs) {
                            if (isValid(r+dr, c+dc, m, n) 
                                && grid[r+dr][c+dc] == '1'
                                && !visited[r+dr][c+dc]) {

                                q.push({r + dr, c + dc});      
                                visited[r+dr][c+dc] = true;                      
                            }
                        }
                    }  
                }              
            }
        }

        return islands;
    }
};
