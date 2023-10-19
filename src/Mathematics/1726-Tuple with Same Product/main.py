from collections import Counter
from itertools import combinations


class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        return sum(c * (c - 1) for c in Counter(x * y for x, y in combinations(nums, 2)).values()) << 2
        # n = len(nums)
        # cnt = Counter([nums[i] * nums[j] for i in range(n) for j in range(i + 1, n)])
        #
        # ans = 0
        # for _, v in cnt.items():
        #     ans += v * (v - 1) >> 1
        #
        # return ans << 3
