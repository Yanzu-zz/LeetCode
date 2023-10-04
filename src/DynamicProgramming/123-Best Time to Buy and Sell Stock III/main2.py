from cmath import inf
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        k = 2
        n = len(prices)
        f = [[[-inf] * 2 for _ in range(k + 2)] for _ in range(n + 1)]

        # 第一天不买入的情况
        for j in range(1, k + 2):
            f[0][j][0] = 0

        # 开始递推
        for i, p in enumerate(prices):
            for j in range(1, k + 2):
                f[i + 1][j][0] = max(f[i][j][0], f[i][j - 1][1] + p)
                f[i + 1][j][1] = max(f[i][j][1], f[i][j][0] - p)

        return f[n][k + 1][0]

        # @cache
        # def dfs(i, j, hold):
        #     if j < 0:
        #         return -inf
        #     if i < 0:
        #         return -prices[0] if hold else 0
        #
        #     # 下面代码和 121 题一样，只不过就是加入了限制次数 j
        #     # 在 买入 或 卖出 两个操作种选一个减次数即可
        #     if hold:
        #         return max(dfs(i - 1, j, 1), dfs(i - 1, j, 0) - prices[i])
        #     return max(dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i])
        #
        # return dfs(len(prices) - 1, 2, 0)
