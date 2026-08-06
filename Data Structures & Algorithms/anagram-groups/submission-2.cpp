class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // We represent each string as a frequency map
        unordered_map<string, vector<string>> unique;        

        for (string s : strs) {
            map<char, int> f;
            for (const auto& c : s) {
                f[c]++;
            }
            string k = "";
            for (const auto& [key,v] : f) {
                k = k + key + to_string(v);
            }            
            cout << "Key is " << k << "\n";
            if (unique.count(k)) {
                unique[k].push_back(s);
            } else {
                unique[k] = {s};
            }
        }

        vector<vector<string>> ans;
        for (const auto& [k,v] : unique) {
            ans.push_back(v);
        }

        return ans;
    }
};
