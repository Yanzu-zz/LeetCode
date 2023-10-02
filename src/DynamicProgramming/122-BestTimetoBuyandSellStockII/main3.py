class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 每次遇到能赚的时候就卖出
        ans = 0
        n = len(prices)
        for i in range(1, n):
            ans += prices[i] - prices[i - 1] if prices[i] > prices[i - 1] else 0

        return ans
