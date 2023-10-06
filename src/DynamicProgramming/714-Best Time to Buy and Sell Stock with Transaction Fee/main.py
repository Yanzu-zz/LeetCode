from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)

        @cache
        def dfs(i, hold):
            if i < 0:
                return -prices[0] if hold else 0

            if hold:
                return max(dfs(i - 1, 1), dfs(i - 1, 0) - prices[i])
            # 不同点就是卖出时加多个交易税就行
            return max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i] - fee)

        return dfs(n - 1, 0)
