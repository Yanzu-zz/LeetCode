PRE_SUM = [0] * 1001

for i in range(1, 1001):
    s = str(i * i)
    n = len(s)


    # 逐段分割数字，并将它们加起来
    # 若加起来的和等于 s，则加入结果数组
    def dfs(p, sum):
        # 边界条件
        if p == n:
            return sum == i

        x = 0
        # 枚举并分割从 s[p] 到 s[j] 的子串
        for j in range(p, n):
            x = x * 10 + int(s[j])
            if dfs(j + 1, sum + x):
                return True

        return False


    PRE_SUM[i] = PRE_SUM[i - 1] + (i * i if dfs(0, 0) else 0)


class Solution:
    def punishmentNumber(self, n: int) -> int:
        return PRE_SUM[n]
