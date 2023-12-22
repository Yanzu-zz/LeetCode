from bisect import bisect_left


class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        g = []
        # 最长递减子序列和最长递增子序列
        suf = [0] * n

        # 开始预训练递减子序列
        for i in range(n - 1, 0, -1):
            # 套路写法了
            x = nums[i]
            j = bisect_left(g, x)
            if j == len(g):
                g.append(x)
            else:
                g[j] = x
            # 下标从 0 开始
            # 因为从后往前就是递减
            suf[i] = j + 1

        g = []
        ans = 0
        for i, x in enumerate(nums):
            j = bisect_left(g, x)
            if j == len(g):
                g.append(x)
            else:
                g[j] = x
            # 从前往后就是最长递增子序列
            pre = j + 1

            # 此时就可以计算以当前数值为最高山脉点的长度了
            if pre >= 2 and suf[i] >= 2:
                ans = max(ans, pre + suf[i] - 1)
        return n - ans
