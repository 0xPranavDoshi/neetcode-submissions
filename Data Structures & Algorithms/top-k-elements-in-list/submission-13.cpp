class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == k) return nums;

        unordered_map<int, vector<int>> buckets(n+1);

        unordered_map<int, int> f;

        for (int num : nums) {
            f[num]++;
        }

        for (const auto& [num, freq] : f) {
            buckets[freq].push_back(num);
        }

        vector<int> res;

        for (int i = n+1; i >= 0; i--) {
            if (!buckets[i].empty()) {
                for (int j = 0; j < buckets[i].size(); j++) {
                    res.push_back(buckets[i][j]);
                    if (res.size() == k) return res;
                }
            }
        }
    }
};
