class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        int n = s.size();
        if (n == 0) return 0;
        int len = 1;

        int l = 0, r = 0;
        unordered_set<char> sub;
        while (l <= r && r < n) {            
            if (!sub.count(s[r])) {
                // Extend the window
                sub.insert(s[r]);
                r++;
                int window_size = r - l;
                if (window_size > len) len = window_size;   
            } else {
                // Shrink the window until its valid
                while (s[l] != s[r]) {
                    sub.erase(s[l]);
                    l++;
                }   
                sub.erase(s[l]);             
                l++;
            }
        }

        return len;
    }
};
