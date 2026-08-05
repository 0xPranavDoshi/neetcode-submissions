class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;        
        int pivot = -1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        pivot = l;

        if (target == nums[pivot]) return pivot;

        l = pivot;
        r = n - 1;

        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) {
                return m;
            }
            if (target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        l = 0;
        r = pivot;

        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) {
                return m;
            }
            if (target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
};
