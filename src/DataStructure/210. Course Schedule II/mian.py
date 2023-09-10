from collections import defaultdict, deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        g = defaultdict(list)
        indeg = [0] * numCourses

        # 建图
        for a, b in prerequisites:
            g[b].append(a)
            indeg[a] += 1

        # 将入度为0的节点进行拓扑排序
        ret = list()
        q = deque()
        for i, x in enumerate(indeg):
            if x == 0:
                q.append(i)
                ret.append(i)

        # 开始拓扑排序
        cnt = 0
        while q:
            i = q.popleft()
            cnt += 1
            for j in g[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
                    ret.append(j)

        return list() if cnt != numCourses else ret
