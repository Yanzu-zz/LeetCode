class Solution:
    def climbStairs(self, n: int) -> int:
        # 其实就是一个斐波那契数列，可以只用3个变量轮换
        a, b = 1, 2
        c = min(n, b)

        for i in range(3, n + 1):
            c = a + b
            a = b
            b = c

        return c
