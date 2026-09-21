class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int, int> m;        

        for (int i = 0; i < n; i++) {
            int diff = target - numbers[i];
            if (m.count(diff) && m[diff] != i) {
                return {m[diff]+1, i+1};
            } else {
                m.insert({numbers[i], i});
            }
        }

        return {};
    }
};
