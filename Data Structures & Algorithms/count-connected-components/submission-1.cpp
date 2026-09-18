class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0, nodes = 0;
        stack<int> s;
        vector<int> visited(n, false);        

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                s.push(i);

                while (!s.empty()) {
                    int cur = s.top();
                    s.pop();

                    if (!visited[cur]) {
                        visited[cur] = true;
                        nodes++;
                    }

                    for (int node : adj[cur]) {
                        if (!visited[node]) s.push(node);
                    }
                }
            }            
        }      

        return count; 
    }
};
