class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        maxV = max(nums)
        # 等差数列求和
        return (maxV + (maxV + k - 1)) * k // 2
