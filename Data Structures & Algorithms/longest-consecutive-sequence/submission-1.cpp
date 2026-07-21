class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> l;
        unordered_set<int> s;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        int longest = 0;

        for (int i = 0; i < n; i++) {
            if (s.count(nums[i] - 1)) continue;

            // This can be a start of a sequence
            int count = 1;
            while (s.count(nums[i]+count)) {
                count++;
            }

            cout << "Seq len: " << count << "\n";

            if (count > longest) {
                longest = count;
            }
        }

        return longest;
    }
};
