class Solution {
private:
    vector<int> prefix;

public:
    Solution(vector<int>& w) {
        int n = w.size();

        int sum = 0;
        for (int x : w) {
            sum += x;
            prefix.push_back(sum);
        }
    }
    
    int pickIndex() {        
        int n = prefix.size();
        int random = rand() % prefix[n-1] + 1;

        int index = 0;

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (prefix[m] >= random) {
                index = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */