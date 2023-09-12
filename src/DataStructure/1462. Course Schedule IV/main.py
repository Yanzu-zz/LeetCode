class Solution:
    # def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[
    #     bool]:
    #     g=[[False] * numCourses for _ in range(numCourses)]
    #     for a, b in prerequisites:
    #         g[b][a] = True
    #
    #     ret = []
    #     for a, b in queries:
    #         ret.append(g[b][a])
    #
    #     return ret

    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[
        bool]:
        g = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            g[a].append(b)

        # search if v1 is prerequest of v2
        @cache
        def dfs(v1, v2):
            # 也就是沿着 v1 的子元素往下查
            for q in g[v1]:
                if q == v2 or dfs(q, v2):
                    return True

            return False

        return [dfs(a, b) for a, b in queries]
