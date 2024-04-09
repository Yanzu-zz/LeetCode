class Solution:
  def maximumCount(self, nums: List[int]) -> int:
    # 正数和负数计数器
    cnt1 = cnt2 = 0

    for num in nums:
      cnt1 += 1 if num > 0 else 0
      cnt2 += 1 if num < 0 else 0

    return max(cnt1, cnt2)
