from typing import List


class Solution:

    def findTheArrayConcVal(self, nums: List[int]) -> int:
        n = len(nums)
        aLen = n // 2 + (n % 2 == 1)
        # one-liner
        ans = sum([int(str(nums[i]) + str(nums[n - 1 - i])) if (i != n // 2) else nums[i] for i in range(aLen)])

        return ans

        # while l <= r:
        #     tmp = int(str(nums[l]) + str(nums[r]))
        #     if l == r:
        #         tmp = nums[l]
        #     ans += tmp
        #     l += 1
        #     r -= 1
        #
        # return ans


a = findTheArrayConcVal([5, 14, 13, 8, 12])
print(a)
