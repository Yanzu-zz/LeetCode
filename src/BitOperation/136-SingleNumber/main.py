class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        d = {}

        for num in nums:
            if num in d:
                d.pop(num, None)
            else:
                d[num] = 1

        return d.popitem()[0]

        # s = set()
        #
        # for num in nums:
        #     if num in s:
        #         s.remove(num)
        #     else:
        #         s.add(num)
        #
        # return s.pop()
