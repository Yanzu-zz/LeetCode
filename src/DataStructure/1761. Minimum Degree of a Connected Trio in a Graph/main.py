class Solution:
  def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
    # 邻接矩阵
    g = [[False] * n for _ in range(n)]
    # 化度数矩阵（出入）
    deg = [0] * n

    # 下面开始初始化邻接和度数矩阵
    for u, v in edges:
        # 下标从0开始，所以要-1
        u, v = u-1, v-1
        g[u][v] = g[v][u] = True
        deg[u]+=1
        deg[v]+=1
    
    # 然后开始计算题目要求
    # 其实就是暴力查看每三个节点是否相通，通的话就计算它的度
    # 由于每个连通三节点都有6个连接自身的出入度，所以我们减掉它就行
    ans = inf
    for i in range(n):
      for j in range(i+1, n):
        if(g[i][j]):
          for k in range(j+1, n):
            if(g[i][k] and g[j][k]):
              ans = min(ans, deg[i]+deg[j]+deg[k]-6)


    return -1 if ans == inf else ans