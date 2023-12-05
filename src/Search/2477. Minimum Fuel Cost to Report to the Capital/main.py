class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        n = len(roads)

        # 建树
        g = [[] for _ in range(n + 1)]
        for a, b in roads:
            g[a].append(b)
            g[b].append(a)

        ans = 0

        def dfs(cur, parent):
            size = 1
            for child in g[cur]:
                # 只要不是父节点，就递归下去
                if child != parent:
                    size += dfs(child, cur)

            # 到了叶节点，且排除根节点的情况
            if cur:
                nonlocal ans
                ans += (size - 1) // seats + 1

            return size

        dfs(0, -1)
        return ans
