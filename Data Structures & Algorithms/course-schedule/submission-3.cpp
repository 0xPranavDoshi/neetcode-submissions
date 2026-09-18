class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (const auto& req : prerequisites) {
            int dest = req[0];
            int src = req[1];
            
            adj[src].push_back(dest);
            inDegree[dest]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            // cout << "In Degree of course " << i << " is " << inDegree[i] << "\n";
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> courseTaken(numCourses, false);

        int coursesTaken = 0;        

        while (!q.empty()) {
            int course = q.front();
            // cout << "Popping " << course << "\n";
            q.pop();
            courseTaken[course] = true;
            coursesTaken++;

            vector<int> nextCourses = adj[course];
            // cout << "Course " << course << " has " << nextCourses.size() << " neighbours\n";
            for (int c : nextCourses) {
                inDegree[c]--;
                if (!courseTaken[c] && inDegree[c] == 0) {
                    q.push(c);
                    courseTaken[c] = true;
                }
            }
        }

        if (coursesTaken == numCourses) return true;

        return false;
    }
};
