class Solution309 {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        /**
         * 	所以对于每一天i，都有可能是三种状态（状态定义）：
         * 		0. 不持股且当天没卖出,定义其最大收益dp[i][0];
         * 		1. 持股,定义其最大收益dp[i][1]；
         *      2. 不持股且当天卖出了，定义其最大收益dp[i][2]；
         */
        int[][] dp = new int[n][3]; // 每天有三种状态
        dp[0][0] = 0;          // 第一天啥也不干
        dp[0][1] = -prices[0]; // 第一天买入，那肯定是要花钱的
        dp[0][2] = 0;

        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][2]);        // 当天没有股票的情况
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 当天持有股票的情况
            dp[i][2] = dp[i - 1][1] + prices[i];                         // 这天卖股票了，查看收益
        }

        // 最后收益高的一定是 “不持有股票” 的两个状态
        return Math.max(dp[n - 1][0], dp[n - 1][2]);
    }
}