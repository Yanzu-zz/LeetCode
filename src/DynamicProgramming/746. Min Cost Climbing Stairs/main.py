class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # n = len(cost)
        # dp = [0] * (n + 1)
        #
        # for i in range(2, n + 1):
        #     dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1])
        #
        # return dp[n]

        # 上面的 dp 很明显只需要用 3 个变量就能轮换
        n = len(cost)
        a, b, c = 0, 0, 0
        for i in range(2, n + 1):
            a = min(b + cost[i - 2], c + cost[i - 1])
            b = c
            c = a

        return a
