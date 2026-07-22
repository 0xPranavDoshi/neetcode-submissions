class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int max = 0;
        int lowest = INT_MAX;
        for (int i = 0; i < n; i++) {
            int profit = prices[i] - lowest;
            if (profit > max) max = profit;
            if (prices[i] < lowest) lowest = prices[i];
        }

        return max;
    }
};
