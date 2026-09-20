class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        for (int i = 0; i <= n; i++) total_sum += i;

        int sum = 0;

        for (int num : nums) sum += num;

        return total_sum - sum;
    }
};
