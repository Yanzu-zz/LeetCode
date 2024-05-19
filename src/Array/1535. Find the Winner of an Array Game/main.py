class Solution:
  def getWinner(self, arr: List[int], k: int) -> int:
    maxV = arr[0]
    cnt = -1

    for a in arr:
      if a > maxV:
        maxV = a
        cnt = 0
      cnt += 1

      if cnt >= k:
        break

    return maxV
