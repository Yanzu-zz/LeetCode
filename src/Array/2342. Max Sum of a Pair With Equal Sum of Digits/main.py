class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        cnt = [0] * 82
        ans = -1

        for num in nums:
            cur, d = num, 0

            # 计算各个位置上的 sum
            while cur > 0:
                d += cur % 10
                cur //= 10

            # 如果有 2对 以上
            if cnt[d] > 0:
                ans = max(ans, cnt[d] + num)
            cnt[d] = max(cnt[d], num)

        return ans
