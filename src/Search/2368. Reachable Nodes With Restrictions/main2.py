class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        tree = [[] for _ in range(n)]
        set_restricted = set(restricted)

        for a, b in edges:
            if a not in set_restricted and b not in set_restricted:
                tree[a].append(b)
                tree[b].append(a)

        def dfs(node, father):
            cnt = 1
            for next in tree[node]:
                if next != father:
                    cnt += dfs(next, node)

            return cnt

        return dfs(0, -1)
