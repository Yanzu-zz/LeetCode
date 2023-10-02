class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0] * 2 for _ in range(n)]

        # 第一天买入股票的情况（不买就是0不用再初始化）
        dp[0][1] = -prices[0]

        for i in range(1, n):
            # 第 i 天不持有股票的状态，只能由 昨天不持有 和 昨天持有但我今天卖了 两个状态转移过来
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])
            # 第 i 天持有股票的状态，只能由 昨天持有 和 昨天不持有，但我今天买进了 两种状态转移的来
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])

        # 较大的值肯定是最有一天不买入得来
        return dp[n - 1][0]
