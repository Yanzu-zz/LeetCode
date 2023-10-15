from collections import Counter


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # one-liner
        return next(k for k, v in Counter(nums).items() if v == 1)

        # c = Counter(nums)
        # ans = [k for k, v in c.items() if v == 1]
        # return ans[0]
