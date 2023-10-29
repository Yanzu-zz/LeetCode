class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        cnt = [0] * (n + 1)

        for c in citations:
            # 计数排序
            cnt[min(c, n)] += 1

        # 接着就是判断某个数是否 >= i
        s = 0
        for i in range(n, -1, -1):
            s += cnt[i]
            if s >= i:
                return i

        return 0
