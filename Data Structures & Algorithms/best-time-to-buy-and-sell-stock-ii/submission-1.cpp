class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int totalProfit = 0;
        int buyingPrice = prices[0];
        int i = 1;
        while (i < n) {
            int sellingPrice = prices[i];

            if (prices[i-1] < buyingPrice) {
                buyingPrice = prices[i-1];
            }

            if (i != n-1 && prices[i+1] > prices[i]) {
                i++;
                continue;
            }

            int profit = sellingPrice - buyingPrice;
            cout << "buying at " << buyingPrice << ", selling at " << sellingPrice << "\n";
            if (profit > 0) totalProfit += profit;
            if (i+1 >= n) break;
            buyingPrice = prices[i+1];            
            i += 2;
        }

        return totalProfit;
    }
};