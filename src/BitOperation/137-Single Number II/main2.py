class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = b = 0
        for x in nums:
            b = (b ^ x) & ~a
            a = (a ^ x) & ~b
        return b

        # ans = 0
        #
        # for i in range(32):
        #     cnt = 0
        #     for x in nums:
        #         cnt += (x >> i) & 1
        #     ans |= cnt % 3 << i
        #
        # return ans
