class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        
        int i = 0, j = n-1;
        while (i < j) {       
            if (!isalnum(s[i])) {
                i++; 
                continue;
            }                
            if (!isalnum(s[j])) {
                j--; 
                continue;
            }

            if (tolower(s[i]) != tolower(s[j])) {
                cout << s[i] << " is not " << s[j] << "\n";
                return false;
            }
            j--;
            i++;
        }

        return true;
    }
};
