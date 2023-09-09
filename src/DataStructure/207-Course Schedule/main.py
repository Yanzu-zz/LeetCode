from collections import defaultdict, deque


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # 先建图（这里用邻接表存储）
        g = defaultdict(list)
        # 入度数组
        indeg = [0] * numCourses

        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1  # 注意，这里是 a 是被入的

        # 将入度为 0 的节点先拎出来
        q = deque(i for i, x in enumerate(indeg) if x == 0)

        # 然后进行拓扑排序
        cnt = 0
        while q:
            i = q.popleft()
            cnt += 1
            # 接着将它的入度节点加入 q
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)

        return cnt == numCourses
