from heapq import heappop, heappush
from multiprocessing.forkserver import ensure_running
from typing import List


class Solution:
  def kSum(self, nums: List[int], k: int) -> int:
    # 先算正元素的和
    # s = sum([num if num > 0 else 0 for num in nums])
    mx = 0
    n = len(nums)
    for i, num in enumerate(nums):
      if num > 0:
        mx += num
      else:
        nums[i] = -num

    # 小顶堆（k个）
    h = [(0, 0)]
    nums.sort()
    for _ in range(k - 1):
      s, i = heappop(h)
      if i < n:
        heappush(h, (s + nums[i], i+1))

        # 减去某个元素，再加新的，这样循环下去就能把所有元素组合都遍历到
        if i:
          heappush(h, (s + nums[i] - nums[i - 1], i+1))

    return mx - h[0][0]
