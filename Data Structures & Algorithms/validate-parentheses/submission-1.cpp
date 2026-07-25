class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;

        stack<char> c;

        for (int i = 0; i < s.size(); i++) {
            if (c.empty()) {
                c.push(s[i]);
                continue;
            }
            if (s[i] == getCorresponding(c.top())) c.pop();
            else c.push(s[i]);
        }

        return c.empty();
    }

    char getCorresponding(char c) {
        switch (c) {
            case '(':
                return ')';
            case '{':
                return '}';
            case '[':
                return ']';
            default:
                return '\0';
        }
    }
};
