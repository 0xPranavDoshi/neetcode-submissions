class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        stack<pair<int, int>> s;
        vector<int> visited(n, false);
        s.push({0, -1});
        int nodesVisited = 0;

        while (!s.empty()) {
            auto [cur_node, parent] = s.top();
            s.pop();

            if (!visited[cur_node]) {
                visited[cur_node] = true;
                nodesVisited++;
            }

            for (int node : adj[cur_node]) {
                if (node == parent) continue;
                if (visited[node]) return false;                
                s.push({node, cur_node});
            }
        }

        if (nodesVisited < n) return false;

        return true;
    }
};
