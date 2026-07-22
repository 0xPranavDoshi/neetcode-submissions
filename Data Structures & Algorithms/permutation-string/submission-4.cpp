class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        int j = 0;

        unordered_map<char, int> e;

        for (const auto& c : s1) {
            e[c]++;
        }

        unordered_map<char, int> window_set;
        int total = 0;

        while (j < s2.size()) {
            // cout << "Current window is [" << i << ", " << j << "]" << ": " << s2.substr(i, (j-i)+1) << "\n";           

            if (!e.count(s2[j])) {
                window_set.erase(s2[i]);
                total >= 1 ? total-- : total = 0;
                i++; j++;
            } else {                                
                // cout << "Inserting " << s2[j] << " to set\n";        

                if (window_set[s2[j]] >= e[s2[j]]) {
                    // cout << "too many\n";
                    window_set.clear();
                    window_set[s2[i+1]] = 1;
                    total = 1;
                    i++;
                    j = i+1;
                } else {
                    window_set[s2[j]]++;
                    j++;
                    total++;
                    // if (window_set.size() >= s1.size()) return true;
                }
            }

            // for (const auto& [k,v] : window_set) {
            //     cout << k << "(" << v << ")\n";
            // }
            // cout << "Total: " << total << " / " << s1.size() << "\n\n";     

            if (total == s1.size()) return true;         
        }

        return false;
    }
};
