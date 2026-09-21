class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;

        int buyPrice = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i-1] < buyPrice) buyPrice = prices[i-1];

            profit = max(profit, prices[i] - buyPrice);
        }

        return profit;
    }
};
