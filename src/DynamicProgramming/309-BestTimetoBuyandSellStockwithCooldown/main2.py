from cmath import inf
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # 有交易冷却时间，本质上也就是持有的状态只能从昨天持有或者前天没持有转移过来
        f = [[0] * 2 for _ in range(n + 2)]
        f[1][1] = -inf

        for i, p in enumerate(prices):
            f[i + 2][0] = max(f[i + 1][0], f[i + 1][1] + p)
            f[i + 2][1] = max(f[i + 1][1], f[i][0] - p)
        return f[-1][0]

        # @cache
        # def dfs(i, hold):
        #     if i < 0:
        #         return -inf if hold else 0
        #
        #     if hold:
        #         return max(dfs(i - 1, 1), dfs(i - 2, 0) - prices[i])
        #     return max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i])
        #
        # return dfs(n - 1, 0)
