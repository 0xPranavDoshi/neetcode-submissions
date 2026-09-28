class Solution {
private: 
    unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:

    int romanToInt(string s) {
        int n = s.size();
        int num = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C') {
                if (i < n-1 && m[s[i+1]] > m[s[i]]) {
                    num += (m[s[i+1]] - m[s[i]]);
                    i++;
                    continue;
                }
            }

            num += m[s[i]];
        }

        return num;
    }    
};