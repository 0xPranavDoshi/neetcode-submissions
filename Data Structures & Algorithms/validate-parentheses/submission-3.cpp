class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        unordered_map<char, char> corresponding = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> c;

        for (int i = 0; i < s.size(); i++) {
            if (c.empty()) {
                c.push(s[i]);
                continue;
            }
            if (corresponding[s[i]] == c.top()) c.pop();
            else c.push(s[i]);
        }

        return c.empty();
    }
};
