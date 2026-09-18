class Solution {
public:
    void bfs(queue<pair<int,int>>& q, vector<vector<char>>& board, char character) {
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        int m = board.size(), n = board[0].size();

        while (!q.empty()) {
            auto [r,c] = q.front();
            board[r][c] = character;
            q.pop();

            for (auto [dr,dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'O') {
                    q.push({nr,nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') q.push({0,i});
            if (board[m-1][i] == 'O') q.push({m-1,i});
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') q.push({i,0});
            if (board[i][n-1] == 'O') q.push({i,n-1});
        }     

        bfs(q, board, '#');

        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (board[i][j] == 'O') q.push({i,j});
            }
        }
        
        bfs(q, board, 'X');

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
