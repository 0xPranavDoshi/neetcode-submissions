class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        int n = nums.size();

        unordered_set<int> hash_set(n);
        for (int i = 0; i < n; i++) {
            hash_set.insert(nums[i]);
        }        

        for (int i = 0; i < n; i++) {
            if (!hash_set.count(nums[i]-1)) {
                // Can be start of sequence
                int count = 1;
                while (hash_set.count(nums[i]+count)) {
                    count++;
                }
                if (count > longest) longest = count;
            }
        }

        return longest;
    }
};
