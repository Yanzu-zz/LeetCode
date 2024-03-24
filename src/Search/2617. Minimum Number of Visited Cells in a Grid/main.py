from queue import Queue


class Solution:
  def minimumVisitedCells(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    visited = [[False for _ in range(n)] for _ in range(m)]
    q = Queue()
    # 顺序是 元素值，i, j, step
    q.put((grid[0][0], 0, 0, 1))
    ans = 10000000

    def isValid(i, j):
      return i >= 0 and i < m and j >= 0 and j < n and visited[i][j] == False

    while not q.empty():
      curLen = q.qsize()

      for _ in range(curLen):
        val, i, j, step = q.get()
        if i == m - 1 and j == n - 1:
          ans = min(ans, step)

        nextP = min(val + j, n - 1)
        q.put((grid[i][nextP], i, nextP, step + 1))
        # visited[i][k] = True

        # 向下移动
        nextP = min(val + i, m - 1)
        q.put((grid[nextP][j], nextP, j, step + 1))
        # visited[k][j] = True

    return ans if ans != 10000000 else -1
