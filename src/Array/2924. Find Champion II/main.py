class Solution:
  def findChampion(self, n: int, edges: List[List[int]]) -> int:
    # 建图
    g = [[0 for _ in range(n)] for _ in range(n)]
    for a, b in edges:
      g[b][a] = 1

    zeroCnt = 0
    sumArr = [0] * n
    for i in range(n):
      v = sum(g[i])
      if v == 0:
        zeroCnt += 1

        if zeroCnt > 1:
          return -1

      sumArr[i] = v

    return sumArr.index(min(sumArr))
