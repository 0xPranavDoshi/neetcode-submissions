class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> h;

        for (int i = 0; i < n; i++) {
            h.insert(nums[i]);
        }
        
        return h.size() != n;
    }
};