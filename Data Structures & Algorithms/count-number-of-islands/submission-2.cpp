class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[i][j] = true;
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};

        for (pair<int,int> d : directions) {
            int r = i + d.first;
            int c = j + d.second;
            if (r >= 0 && r < m && c >= 0 && c < n) {
                if (grid[r][c] == '1' && !visited[r][c]) {                    
                    dfs(r, c, visited, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {                    
                    dfs(i, j, visited, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};
