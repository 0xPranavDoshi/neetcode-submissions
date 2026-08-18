class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<int> s;        

        for (int i = 0; i < n-1; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            s.clear();
            int used = INT_MAX;
            int target = 0 - nums[i];
            for (int j = i+1; j < n; j++) {
                if (nums[j] == used) continue;
                if (s.count(target - nums[j])) {
                    ans.push_back({nums[i], nums[j], target-nums[j]});                    
                    used = nums[j];
                }
                s.insert(nums[j]);
            }
        }

        return ans;
    }
};
