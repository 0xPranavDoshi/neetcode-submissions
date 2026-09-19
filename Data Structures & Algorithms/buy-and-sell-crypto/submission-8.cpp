class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;
        int buyingPrice = prices[0];

        for (int i = 1; i < n; i++) {         
            int sellingPrice = prices[i];
            
            if (prices[i-1] < buyingPrice) {
                buyingPrice = prices[i-1];
            }

            int p = sellingPrice - buyingPrice;

            if (p > profit) profit = p;
        }

        return profit;
    }
};