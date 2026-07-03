class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;        
        unordered_map<string, vector<string>> f;

        for (string s : strs) {
            vector<int> count(26, 0);
            for (const char& c : s) {
                count[c - 'a']++;
            }
            
            string key = "";
            for (int n : count) {
                key = key + "|" +  to_string(n);
            }

            cout << "key is " << key << "\n";

            if (f.count(key)) {
                vector<string> v = f[key];
                v.push_back(s);
                f[key] = v;
            } else {
                f[key] = {s};
            }
        }

        for (const auto& [_, v] : f) {
            ans.push_back(v);
        }

        return ans;
    }
};
