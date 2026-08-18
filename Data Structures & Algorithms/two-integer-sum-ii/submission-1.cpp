class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {        
        int n = numbers.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (m.count(target - numbers[i])) return {m[target-numbers[i]]+1, i+1};
            m.insert({numbers[i], i});
        }

        return {};
    }
};
