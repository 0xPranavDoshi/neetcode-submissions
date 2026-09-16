class Solution {
public:
    void bfs(queue<pair<int,int>>& q, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            // Check 4 neighbours of q
            int r = current.first, c = current.second;
            if (r < m-1 && grid[r+1][c] == '1' && !visited[r+1][c]) {
                q.push({r+1, c});
                visited[r+1][c] = true;
            }
            if (r > 0 && grid[r-1][c] == '1' && !visited[r-1][c]) {
                q.push({r-1, c});
                visited[r-1][c] = true;
            }
            if (c > 0 && grid[r][c-1] == '1' && !visited[r][c-1]) {
                q.push({r, c-1});
                visited[r][c-1] = true;
            }
            if (c < n-1 && grid[r][c+1] == '1' && !visited[r][c+1]) {
                q.push({r, c+1});
                visited[r][c+1] = true;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // The lands are the nodes and they are connected to each other by edges

        int number_of_islands = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {                    
                    q.push({i, j});
                    visited[i][j] = true;

                    bfs(q, grid, visited);

                    number_of_islands++;
                } 
            }
        }

        return number_of_islands;
    }
};
