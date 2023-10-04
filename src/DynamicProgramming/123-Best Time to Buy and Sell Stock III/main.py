from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i, j, hold):
            if j < 0:
                return -inf
            if i < 0:
                return -prices[0] if hold else 0

            # 下面代码和 121 题一样，只不过就是加入了限制次数 j
            # 在 买入 或 卖出 两个操作种选一个减次数即可
            if hold:
                return max(dfs(i - 1, j, 1), dfs(i - 1, j, 0) - prices[i])
            return max(dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i])

        return dfs(len(prices) - 1, 2, 0)
