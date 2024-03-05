from queue import Queue


# BFS 解法
class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        tree = [[] for _ in range(n)]
        set_restricted = set(restricted)

        # 建树
        for a, b in edges:
            if a not in set_restricted and b not in set_restricted:
                tree[a].append(b)
                tree[b].append(a)

        visited = [False] * n
        # 0节点不会被限制
        res = 1
        q = Queue()
        q.put(0)
        visited[0] = True

        while not q.empty():
            curLen = q.qsize()
            for i in range(curLen):
                curItem = q.get()
                for j, node in enumerate(tree[curItem]):
                    if not visited[node]:
                        q.put(node)
                        visited[node] = True
                        res += 1

        return res
