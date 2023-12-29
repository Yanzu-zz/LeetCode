import heapq


class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        n = len(prices)
        # 大顶堆
        mh = []
        heapq.heappush(mh, -prices[0])
        heapq.heappush(mh, -prices[1])

        for i in range(2, n):
            x = -prices[i]
            if x > mh[0]:
                heapq.heappop(mh)
                heapq.heappush(mh, x)

        ans = money + sum(mh)
        return ans if ans >= 0 else money
