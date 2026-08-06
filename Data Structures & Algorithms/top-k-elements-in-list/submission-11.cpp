class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {        
        int n = nums.size();

        if (n == k) {
            return nums;
        }

        unordered_map<int, vector<int>> buckets(n+1);

        unordered_map<int, int> f;
        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        for (const auto& [k, v] : f) {  
            buckets[v].push_back(k);
        }

        vector<int> ans = {};
        for (int i = n; i >= 0; i--) {            
            for (int j = 0; j < buckets[i].size(); j++) {
                ans.push_back(buckets[i][j]);
                if (ans.size() == k) return ans;
            }         
        }

        return ans;
    }
};
