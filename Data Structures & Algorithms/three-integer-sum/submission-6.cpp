class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;
        unordered_map<int, bool> m;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            m.clear();         

            for (int j = i + 1; j < n; j++) {
                int target = 0 - nums[j] - nums[i];
                if (m.count(target) && !m[target]) {
                    triplets.push_back({nums[i], nums[j], target});
                    m[target] = true;
                } else {
                    m.insert({nums[j], false});
                }
            }
        }

        return triplets;
    }
};
