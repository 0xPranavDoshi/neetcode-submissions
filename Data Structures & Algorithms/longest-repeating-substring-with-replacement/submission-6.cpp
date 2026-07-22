class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;        
    
        unordered_map<char, int> f;
        char mostFrequent = s[0];
        int maxValue = 1;        

        int maxSub = 0;

        while (i <= j && j < s.size()) {   
            char c = s[j];
            f[c]++;
            if (f[c] > maxValue) {
                maxValue = f[c];
                mostFrequent = c;
            }

            cout << "most frequent from [" << i << ", " << j << "] is " << mostFrequent << " (" << maxValue << ")\n";

            string sub = s.substr(i, (j-i)+1);

            cout << "substring is " << sub << "\n";
            int num_rep = sub.size() - maxValue;

            cout << "number of replacements needed is " << num_rep << "\n\n";

            if (num_rep > k) {
                cout << "more replacements needed than " << k << " - sliding i\n\n";
                f[s[i]]--;
                i++; j++;
            } else {
                int l = sub.size();
                if (l > maxSub) maxSub = l;
                j++;
            }
        }

        return maxSub;
    }
};
