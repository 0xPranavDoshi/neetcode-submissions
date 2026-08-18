class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max = 0;

        int buy = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (prices[i] < buy) buy = prices[i];
            int p = prices[i] - buy;
            if (p > max) max = p;            
        }

        return max;
    }
};
