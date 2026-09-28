class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int buy = 0, sell = 1;
        int profit = 0;

        while (sell < n) {
            if (sell != n-1 && prices[sell+1] > prices[sell]) {sell++; continue;}
            if (buy < sell - 1 && prices[buy+1] < prices[buy]) {buy++; continue;}

            if (prices[sell] > prices[buy]) {
                profit += (prices[sell] - prices[buy]);
                if (sell < n - 2) {
                    buy = sell + 1;
                    sell = sell + 2;
                } else {
                    break;
                }             
            } else {
                buy++;
                sell++;
            }
        }

        return profit;
    }
};