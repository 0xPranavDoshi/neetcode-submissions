class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0 || s.size() == 1) return s.size();

        int i = 0, j = 0;

        int maxLen = 1;
        unordered_map<char, int> freq;

        freq[s[0]] = 1;
        int mostFreqCount = 1;
        char mostFreq = s[0];
        
        while (j < s.size()) {
            int subSize = j - i + 1;
            int replacements = subSize - mostFreqCount;

            if (replacements <= k) {
                maxLen = max(maxLen, subSize);
                j++;
                if (j >= s.size()) break;
                freq[s[j]]++;                
                if (freq[s[j]] > mostFreqCount) {
                    mostFreq = s[j];
                    mostFreqCount = freq[s[j]];
                }
            } else {
                freq[s[i]]--;
                i++;                
            }
        }

        return maxLen;
    }
};
