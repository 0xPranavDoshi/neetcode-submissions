class Solution {
public:
    void printMap(unordered_map<char, int> m) {
        for (const auto& [c, i] : m) {
            if (i != -1) {
                cout << c << ",";
            }            
        }
        cout << "\n\n";
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if (n == 0 || n == 1) return n;

        int i = 0, j = 1;
        int longest = 1;

        unordered_map<char, int> m;
        m[s[i]] = i;        
        while (j < n) {            
            if (!m.count(s[j]) || m[s[j]] == -1) {             
                m[s[j]] = j;
                longest = max(longest, j-i+1);
                j++; 

                // cout << "Extended to:\n";
                // printMap(m);   
            } else {
                // cout << "First instance at " << m[s[j]] << "\n";
                while (i <= m[s[j]]) {
                    m[s[i]] = -1;
                    i++;
                }
                // cout << "Shrunk to:\n";
                // printMap(m);     
            }   
        }

        return longest;
    }
};
