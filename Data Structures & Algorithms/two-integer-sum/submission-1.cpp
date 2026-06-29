class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;        
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (seen.contains(target - nums[i])) {
                return {seen[target - nums[i]], i};
            } else {
                seen[nums[i]] = i;
            }
        }

        return {};
    }
};
