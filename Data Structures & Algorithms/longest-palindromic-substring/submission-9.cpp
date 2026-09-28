class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n == 0 || n == 1) return s;

        bool diff = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[0]) diff = true;
        }

        if (!diff) return s;

        string pal = "";

        int res = 0;
        int res_len = 0;        

        for (int i = 0; i < n; i++) {
            res = i;
            res_len = 1;

            while (res-1 >= 0 && res+1 < n && s[res-1] == s[res+res_len]) {
                res--;
                res_len += 2;
            }

            if (res_len > pal.size()) {
                pal = s.substr(res, res_len);
            }        

            if (res+1 < n && s[res] != s[res+1]) continue;

            res = i;
            res_len = 2;            

            while (res-1 >= 0 && res+1 < n && s[res-1] == s[res+res_len]) {
                res--;
                res_len += 2;
            }

            if (res_len > pal.size()) {
                pal = s.substr(res, res_len);
            }
        }

        return pal;
    }
};
