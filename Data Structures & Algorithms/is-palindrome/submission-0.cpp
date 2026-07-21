class Solution {
public:
    bool isPalindrome(string s) {
        erase_if(s, [](unsigned char c) {
            return !isalnum(c);
        });

        cout << s;

        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++; j--;
        }

        return true;
    }
};
