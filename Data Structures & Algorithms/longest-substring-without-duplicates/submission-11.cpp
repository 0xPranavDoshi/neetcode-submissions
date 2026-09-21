class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0 || s.size() == 1) return s.size();

        unordered_set<char> inset;        

        int i = 0, j = 1, longest = 1;
        inset.insert(s[0]);

        while (j < s.size()) {
            if (inset.count(s[j])) {                
                while (inset.count(s[j])) {                    
                    inset.erase(s[i]);
                    i++;
                }
            }

            longest = max(longest, j - i + 1);
            inset.insert(s[j]);
            j++;
        }

        return longest;
    }
};
