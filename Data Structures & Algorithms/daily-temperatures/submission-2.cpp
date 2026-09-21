class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> s;
        s.push(0);

        vector<int> out(n, 0);

        for (int i = 1; i < n; i++) {
            if (temperatures[i] > temperatures[i-1]) {
                while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                    out[s.top()] = i - s.top();
                    s.pop();
                }
            }
            s.push(i);
        }

        return out;
    }
};
