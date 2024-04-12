class Solution:
  def findChampion(self, grid: List[List[int]]) -> int:
    n = len(grid)
    cnt = [sum(grid[i]) for i in range(n)]

    return cnt.index(max(cnt))
