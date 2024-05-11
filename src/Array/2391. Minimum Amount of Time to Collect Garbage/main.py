class Solution:
  def garbageCollection(self, garbage, travel):
    n = len(garbage)
    presum = [0] * n

    for i in range(1, n):
      presum[i] = presum[i-1] + travel[i-1]

    ans = 0
    mIdx = pIdx = gIdx = 0
    for i, gar in enumerate(garbage):
      mCnt = gar.count('M')
      pCnt = gar.count('P')
      gCnt = gar.count('G')

      # 每个都要操作一分钟，先记下来
      ans += mCnt + pCnt + gCnt

      # 然后如果有 cnt 就记录到达时间消耗
      if mCnt > 0:
        mIdx = i
      if pCnt > 0:
        pIdx = i
      if gCnt > 0:
        gIdx = i

    ans += presum[mIdx] + presum[pIdx] + presum[gIdx]
    return ans


garbage = ["G", "P", "GP", "GG"]
travel = [2, 4, 3]
print(Solution().garbageCollection(garbage, travel))
