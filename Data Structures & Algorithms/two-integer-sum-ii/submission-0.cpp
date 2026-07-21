class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> s;   
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int diff = target - numbers[i];
            if (s.count(diff)) {
                return {s[diff] + 1, i + 1};
            }

            s[numbers[i]] = i;
        }
        
        return {};
    }
};
