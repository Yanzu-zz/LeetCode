from collections import deque


class Solution:
  def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
    # 邻接表，建表
    g = [[] for _ in range(n)]
    # 出入度表
    degree = [0] * n
    for a, b in edges:
      g[a].append(b)
      g[b].append(a)
      degree[a] += 1
      degree[b] += 1

    # 拓扑排序，把叶子节点全pop掉剩下的就是答案了
    q = deque([i for i in range(n) if degree[i] <= 1])
    ans = []
    while q:
      ans.clear()

      for _ in range(len(q)):
        a = q.popleft()
        ans.append(a)

        for b in g[a]:
          degree[b] -= 1
          if degree[b] == 1:
            q.append(b)

    return ans
