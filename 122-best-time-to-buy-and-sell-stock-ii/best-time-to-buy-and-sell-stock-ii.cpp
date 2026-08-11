class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int holding, vector<int>& prices, int n) {
        if (i >= n) return 0;

        if (dp[i][holding] != -1) return dp[i][holding];

        int profit = 0;

        if (holding == 0) {
            int buy = -prices[i] + f(i + 1, 1, prices, n);
            int skip = f(i + 1, 0, prices, n);
            profit = max(buy, skip);
        } else {
            int sell = prices[i] + f(i + 1, 0, prices, n);
            int skip = f(i + 1, 1, prices, n);
            profit = max(sell, skip);
        }

        return dp[i][holding] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return f(0, 0, prices, n); 
    }
};