class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r = n-1;

        int ans = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r]) {
                return min(ans, nums[l]);
            }

            int m = l + (r - l) / 2;    
            ans = min(ans, nums[m]);

            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }   
        }

        return ans;
    }
};
