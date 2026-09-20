class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n+1, 0);

        for (int i = 0; i <= n; i++) {
            int num = i;

            while (num > 0) {
                out[i] += num % 2;
                num /= 2;
            }
        } 

        return out;
    }
};
