class Solution:
  def countTestedDevices(self, batteryPercentages: List[int]) -> int:
    curCnt = 0
    ans = 0
    for i, b in enumerate(batteryPercentages):
      if b - curCnt > 0:
        ans += 1
        curCnt += 1

    return ans
