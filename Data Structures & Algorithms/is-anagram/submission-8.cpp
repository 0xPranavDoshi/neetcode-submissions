class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> f;
        unordered_map<char, int> f2;

        for (const auto& c : s) {
            f[c]++;
        }

        for (const auto& c : t) {
            f2[c]++;
        }

        return f == f2;
    }
};
