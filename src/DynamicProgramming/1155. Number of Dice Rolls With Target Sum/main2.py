class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        if not (n <= target <= n * k):
            return 0

        MOD = 10 ** 9 + 7
        f = [[0] * (target - n + 1) for _ in range(n + 1)]
        f[0][0] = 1

        # 转成递推
        # n 个骰子
        for i in range(1, n + 1):
            # 剩下的骰子的和值只能是 (0)-(k-1)，因为当前的 i 骰子值最小是1
            for j in range(target - n + 1):
                # 然后 f[i][j] = f[i-1][j-1] + f[i-1][j-2] + ...
                for x in range(min(k, j + 1)):
                    # 别忘了求模
                    f[i][j] = (f[i][j] + f[i - 1][j - x]) % MOD

        return f[n][-1]
