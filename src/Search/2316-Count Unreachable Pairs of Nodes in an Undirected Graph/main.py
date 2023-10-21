class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        isVisited = [0] * n

        # 建图
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)

        def dfs(x):
            isVisited[x] = 1
            size = 1
            for y in g[x]:
                if not isVisited[y]:
                    size += dfs(y)
            return size

        # 逐个计算块的个数然后相乘
        total = 0
        ans = 0
        for i in range(n):
            if not isVisited[i]:
                size = dfs(i)
                ans += size * total
                total += size

        return ans
