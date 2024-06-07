class Solution:
  def maxOperations(self, nums: List[int]) -> int:
    val = nums[0] + nums[1]
    n = len(nums)
    ans = 1

    for i in range(3, n, 2):
      cur = nums[i - 1]
      cur += nums[i]

      if cur != val:
        break

      ans += 1

    return ans
