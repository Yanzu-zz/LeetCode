class Solution:
  def maximumScore(self, nums: List[int], k: int) -> int:
    n = len(nums)
    min_h = nums[k]
    ans = nums[k]
    i = j = k

    for _ in range(n - 1):
      if j == n - 1 or i and nums[i-1] > nums[j+1]:
        min_h = min(min_h, nums[i-1])
        i -= 1
      else:
        min_h = min(min_h, nums[j+1])
        j += 1

      ans = max(ans, min_h * (j - i + 1))

    return ans
