class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int longest = 1;
        int i = 0;
        int j = 1;

        unordered_set<char> t = {s[0]};        
        while (j < n) {
            if (t.count(s[j])) {
                i++;
                j = i + 1;
                t.clear();
                t.insert(s[i]);
            } else {
                t.insert(s[j]);
                j++;                
                if (j - i > longest) {
                    longest = j - i;
                }
            }            
        }

        return longest;
    }
};
