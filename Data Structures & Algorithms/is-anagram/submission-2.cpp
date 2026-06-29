class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> seen;

        for (const auto& c: s) {
            if (seen.contains(c)) {
                seen[c] += 1;
            } else {
                seen[c] = 1;
            }
        }

        for (const auto& c : t) {
            if (!seen.count(c)) {
                return false;
            } else {
                seen[c] -= 1;
            }
        }

        for (const auto& [_, v] : seen) {
            if (v > 0) return false;
        }

        return true;
    }
};
