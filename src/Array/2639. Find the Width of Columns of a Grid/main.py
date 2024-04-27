class Solution:
  def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
    # m = len(grid)
    # n = len(grid[0])
    # ans = [1 for _ in range(n)]

    # for i in range(m):
    #   for j in range(n):
    #     ans[j] = max(ans[j], max(grid[i][j], -10 * grid[i][j]))

    # return ans
    # 此时 g 是按列排序的
    return [len(str(max(max(g), -10*min(g)))) for g in zip(*grid)]
