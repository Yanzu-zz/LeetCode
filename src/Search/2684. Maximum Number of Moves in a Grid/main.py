from queue import Queue


class Solution:
  def maxMoves(self, grid: List[List[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    q = Queue()
    visited = [[False for _ in range(n)] for _ in range(m)]
    visited[0][0] = True

    direction = [[-1, 1], [0, 1], [1, 1]]
    ans = 0

    def isValid(i, j):
      return 0 <= i < m and 0 <= j < n and not visited[i][j]

    for i in range(m):
      # 只要是正常遍历加进来的肯定是第0步
      q.put((grid[i][0], 0, i, 0))

      while not q.empty():
        curLen = q.qsize()
        for k in range(curLen):
          val, step, row, col = q.get()
          ans = max(ans, step)

          for d in range(3):
            nextRow = row + direction[d][0]
            nextCol = col + direction[d][1]

            # 合法的话就下一个
            if isValid(nextRow, nextCol) and grid[nextRow][nextCol] > val:
              visited[nextRow][nextCol] = True
              q.put((grid[nextRow][nextCol], step + 1, nextRow, nextCol))

    return ans
