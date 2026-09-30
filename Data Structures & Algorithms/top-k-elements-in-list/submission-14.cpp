class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> f;

        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        vector<pair<int,int>> f_pairs(n);

        for (const auto& [num, freq] : f) {
            f_pairs.push_back({freq, num});
        }

        sort(f_pairs.begin(), f_pairs.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.first < b.first;
        });

        vector<int> res;

        while (res.size() < k) {
            res.push_back(f_pairs.back().second);
            f_pairs.pop_back();
        }

        return res;        
    }
};
