class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0;

        unordered_map<char, int> f;
        for (const auto& c : t) {
            f[c]++;
        }

        int total = 0;
        unordered_map<char, int> matches;

        int smallest = INT_MAX;
        string min = "";

        while (j < s.size()) {
            cout << "Checking " << s.substr(i, (j-i)+1) << "\n";            
            if (f.count(s[j])) {
                if (matches[s[j]] < f[s[j]]) total++;                
                matches[s[j]]++;
            }
            if (total == t.size()) {                
                while (true) {
                    if (f.count(s[i])) {
                        cout << "Reached a " << s[i] << "\n";
                        if (matches[s[i]] <= f[s[i]]) {
                            cout << "Stopping at " << s[i] << "\n";
                            break;
                        } else {
                            matches[s[i]]--;
                        }
                    }
                    i++;
                }
                string sub = s.substr(i, (j-i) + 1);
                cout << "FOUND - " << sub << "\n";
                if (sub.size() < smallest) {
                    smallest = sub.size();
                    min = sub;
                }
            }
            j++;
        }

        return min;
    }
};
