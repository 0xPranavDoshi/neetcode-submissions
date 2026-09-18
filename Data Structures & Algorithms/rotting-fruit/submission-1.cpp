class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {         
        int m = grid.size(), n = grid[0].size();

        if (m == 0) return -1;

        int minutes = 0;

        queue<pair<int,int>> q;
        int fresh_count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        if (fresh_count == 0) return 0;
        if (q.empty()) return -1;

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()) {
            int size = q.size();
            int found = 0;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();        

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nc >= 0 && nr >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {                    
                        cout << "Found [" << nr << "," << nc << "] in minute " << minutes << "\n";
                        q.push({nr, nc});
                        fresh_count--;
                        grid[nr][nc] = 2;
                        found = 1;
                    }
                }
            }               

            if (found) {
                minutes++;
            }         
        }

        return fresh_count == 0 ? minutes : -1;
    }
};
