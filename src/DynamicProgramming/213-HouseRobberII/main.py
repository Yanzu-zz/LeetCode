class Solution:
    def rob(self, nums: List[int]) -> int:
        def rob_(nums):
            f0 = f1 = 0
            for x in nums:
                f0, f1 = f1, max(f1, f0 + x)

            return f1

        return max(nums[0] + rob_(nums[2:-1]), rob_(nums[1:]))
