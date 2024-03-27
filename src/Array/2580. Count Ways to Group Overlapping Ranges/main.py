class Solution:
  def countWays(self, ranges) -> int:
    ranges.sort(key=lambda x: x[0])
    groupCnt, maxR = 0, -1
    n = len(ranges)

    for l, r in ranges:
      if l > maxR:
        groupCnt += 1
      maxR = max(maxR, r)

    return pow(2, groupCnt, 1_000_000_007)


arr = [[34, 56], [28, 29], [12, 16], [11, 48],
       [28, 54], [22, 55], [28, 41], [41, 44]]
print(Solution().countWays(arr))
