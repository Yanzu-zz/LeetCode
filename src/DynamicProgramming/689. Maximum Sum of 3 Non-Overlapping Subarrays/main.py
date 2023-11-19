import operator
from itertools import accumulate


class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        # 预处理数组，i前面的最大连续k数组和和以及i后面的最大连续k数组和
        s = list(accumulate(nums, initial=0))
        pre = [[] for _ in range(n)]
        suf = [[] for _ in range(n)]

        # 开始预处理
        t, idx = 0, 0  # 这些只是辅助记录 tmp 最大值和索引
        for i in range(n - k + 1):
            # 发现了更大的连续 k 数组和
            if (cur := s[i + k] - s[i]) > t:
                # 注意，pre是记录 [0, p] 的最大值，此处的 p 也就是 i+k-1 处
                pre[i + k - 1] = [cur, i]
                t, idx = cur, i
            else:
                # 如果没找到，则记录之前求得的最大值
                pre[i + k - 1] = [t, idx]

        # 预处理 后面的
        t, idx = 0, 0
        for i in range(n - k, -1, -1):
            if (cur := s[i + k] - s[i]) >= t:
                suf[i] = [cur, i]
                t, idx = cur, i
            else:
                suf[i] = [t, idx]

        # 接着就是循环查看 [0, i-1]——[i, i+k]——[i+k+1, n] 处的三个最大值
        t = 0
        ans = []
        for i in range(k, n - 2 * k + 1):
            # 找到更大的 三个数组
            if (cur := s[i + k] - s[i] + pre[i - 1][0] + suf[i + k][0]) > t:
                ans = [pre[i - 1][1], i, suf[i + k][1]]
                t = cur

        return ans
