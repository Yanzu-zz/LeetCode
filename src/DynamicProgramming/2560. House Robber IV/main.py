from bisect import bisect_left


class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        n = len(nums)

        def check(x):
            cnt = 0
            j = -2
            for i in range(n):
                # 只要当前值大于假定的最大能力值，或者上个房子偷过了，就忽略当前房子
                if nums[i] > x or i == j + 1:
                    continue
                cnt += 1
                j = i

            return cnt >= k

        # l, r = 0, max(nums)
        # while l < r:
        #     mid = l + (r - l) // 2
        #     if check(mid):
        #         r = mid
        #     else:
        #         l = mid + 1
        # return l

        return bisect_left(range(max(nums) + 1), True, key=check)
