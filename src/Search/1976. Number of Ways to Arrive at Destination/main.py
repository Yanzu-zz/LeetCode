from math import inf
from typing import List


class Solution:
  def countPaths(self, n: int, roads: List[List[int]]) -> int:
    # 先建图，稠密图用稀疏矩阵，稀疏图用邻接表
    g = [[inf for _ in range(n)] for _ in range(n)]
    for a, b, c in roads:
      g[a][b] = c
      g[b][a] = c

    # 0 到各个节点的最短距离
    dis = [inf] * n
    dis[0] = 0
    # 有多少个最短距离
    dp = [0] * n
    dp[0] = 1
    # 当前节点是否确认最短距离
    isDone = [False] * n

    while True:
      x = -1

      # 寻找当前节点相邻的最短路径节点
      for i, node in enumerate(isDone):
        # 只能全部扫一遍才知道最短距离
        if not node and (x < 0 or dis[i] < dis[x]):
          x = i

      # 边界条件
      if x == n - 1:
        return dp[-1]

      isDone[x] = True
      dx = dis[x]
      # 接着开始更新 dis
      for y, d in enumerate(g[x]):
        new_d = dx + d

        # 发现个更短的路径，更新一下
        if new_d < dis[y]:
          dis[y] = new_d
          dp[y] = dp[x]
        elif new_d == dis[y]:
          dp[y] = (dp[y] + dp[x]) % 1_000_000_007
