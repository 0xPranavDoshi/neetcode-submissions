class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0) return 0;
        int l = 0, r = 0;
        int len = 1;

        vector<int> f_map(26, 0);
        f_map[s[0] - 'A'] = 1;
        int most_freq = 1;

        while (l <= r && r < n) {      
            if (f_map[s[r] - 'A'] > most_freq) {
                most_freq = f_map[s[r] - 'A'];
            }

            if (r-l+1 - most_freq <= k) {
                if (r-l+1 > len) len = r-l+1;

                r++;                                
                if (r < n) {
                    f_map[s[r] - 'A']++;
                }           
            } else {                
                f_map[s[l] - 'A']--;
                l++;
            }
        }

        return len;
    }
};
