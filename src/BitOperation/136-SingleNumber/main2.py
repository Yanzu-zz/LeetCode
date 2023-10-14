from functools import reduce
from operator import xor


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda x, y: x ^ y, nums)
        # return reduce(xor, nums)
        # ans = 0
        #
        # for num in nums:
        #     ans ^= num
        #
        # return ans
