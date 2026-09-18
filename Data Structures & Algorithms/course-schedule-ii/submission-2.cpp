class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegrees(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegrees[pre[0]]++;
        }

        queue<int> q;
        vector<bool> completed(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
                completed[i] = true;
            }
        }
        
        vector<int> order = {};
        int coursesCompleted = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);  
            coursesCompleted++;                    

            for (int c : adj[cur]) {
                inDegrees[c]--;
                if (!completed[c] && inDegrees[c] == 0) {
                    completed[c] = true;
                    q.push(c);
                }
            }
        }

        if (coursesCompleted < numCourses) return {};

        return order;
    }
};
