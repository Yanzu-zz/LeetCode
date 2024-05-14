from queue import Queue


class Solution:
  def orangesRotting(self, grid):
    m, n = len(grid), len(grid[0])
    directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
    visited = [[False for _ in range(n)] for _ in range(m)]

    def checkFresh():
      return any(1 in g for g in grid)

    def isValid(i, j):
      if i < 0 or i >= m or j < 0 or j >= n:
        return False
      return True

    ans = 0
    q = Queue()
    for i in range(m):
      for j in range(n):
        if grid[i][j] == 2:
          q.put((i, j, 0))

    while not q.empty():
      curLen = q.qsize()
      for i in range(curLen):
        curI, curJ, curStep = q.get()
        ans = max(ans, curStep)
        grid[curI][curJ] = 2

        for d in directions:
          newI, newJ = curI + d[0], curJ + d[1]
          if isValid(newI, newJ) and not visited[newI][newJ] and grid[newI][newJ] == 1:
            q.put((newI, newJ, curStep + 1))
            visited[newI][newJ] = True

    return ans if not checkFresh() else -1


grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
print(Solution().orangesRotting(grid))
