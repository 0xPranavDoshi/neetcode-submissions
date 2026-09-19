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
        // randomly picks an index from 0 to w.size() - 1.
        // probability of picking index i is w[i] / sum(w)

        // Generate number from 1 to total sum
        int n = prefix.size();
        int random = rand() % prefix[n-1] + 1;

        // Binary search prefix sum to find sum that's >= random number
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