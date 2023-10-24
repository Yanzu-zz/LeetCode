class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        if not (n <= target <= n * k):
            return 0

        MOD = 10 ** 9 + 7

        @cache
        def dfs(i, j):
            if i == 0:
                return int(j == 0)

            ans = 0
            for x in range(min(k, j + 1)):
                # 递归成子问题：用 i-1个骰子能有多少种方式 sum 到 j-x 数值
                ans += dfs(i - 1, j - x)
            return ans % MOD

        return dfs(n, target - n)
