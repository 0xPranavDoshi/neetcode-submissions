class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {        
        int n = t.size();
        vector<int> res(n, 0);
        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; i++) {
            if (t[i] > t[i-1]) {
                cout << "Found warming temp\n";
                while (!s.empty() && t[s.top()] < t[i]) {      
                    cout << "Popping " << t[s.top()] << "\n";
                    res[s.top()] = i - s.top();
                    s.pop();
                }                
            }

            s.push(i);
        }

        return res;
    }
};
