class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        int just_used = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            s.clear();
            just_used = INT_MAX;
            for (int j = i+1; j < n; j++) {
                if (nums[j] == just_used) continue;
                int target = 0 - nums[i] - nums[j];
                if (s.count(target)) {                    
                    ans.push_back({target, nums[i], nums[j]});
                    just_used = nums[j];
                } else {
                    s.insert(nums[j]);
                }
            }
        }

        return ans;
    }
};
