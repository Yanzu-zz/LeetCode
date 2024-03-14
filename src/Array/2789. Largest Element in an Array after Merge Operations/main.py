class Solution:
  def maxArrayValue(self, nums: List[int]) -> int:
    ans = 0
    n = len(nums)

    for i in range(n-1, -1, -1):
      ans = ans + nums[i] if nums[i] <= ans else nums[i]

    return ans
