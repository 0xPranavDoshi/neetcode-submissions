class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {        
        vector<int> a;
        int n = nums.size();

        vector<vector<int>> b(n+1);
        unordered_map<int, int> f;

        if (n == 1 && k >= 1) return nums;
        
        for (int i = 0; i < n; i++) {            
            f[nums[i]]++;
        }

        for (const auto& [k, v] : f) {
            b[v].push_back(k);
        }

        int count = 0;
        for (int i = b.size() - 1; i > 0; i--) {
            for (int j = 0; j < b[i].size(); j++) {
                cout << b[i][j] << " ";
                a.push_back(b[i][j]);
                count++;
                if (count == k) return a;
            }
        }

        return a;
    }
};
