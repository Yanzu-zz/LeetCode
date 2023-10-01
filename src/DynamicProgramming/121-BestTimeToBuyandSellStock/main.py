class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [0] * n
        minP = prices[0]

        for i in range(1, n):
            dp[i] = max(dp[i - 1], prices[i] - minP)
            minP = min(minP, prices[i])

        return dp[n - 1]
