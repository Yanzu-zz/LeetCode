class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        # dp = [0] * (n + 1)
        # 从 dp[1] 开始，这样就能在 n<=2 时与其它长度统一操作
        # dp[1] = nums[0]

        # for i in range(2, n + 1):
        #     # dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1])

        # 用常数个变量替换数组
        a = nums[0]
        b, c = 0, a
        for i in range(1, n):
            c = max(a, b + nums[i])
            b = a
            a = c

        return c
