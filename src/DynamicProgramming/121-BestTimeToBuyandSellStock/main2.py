class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minP = prices[0]
        n = len(prices)
        ans = 0

        for i in range(1, n):
            ans = max(ans, prices[i] - minP)
            minP = min(minP, prices[i])

        return ans
