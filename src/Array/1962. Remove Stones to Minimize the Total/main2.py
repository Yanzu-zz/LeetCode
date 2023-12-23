from heapq import heapify, heapreplace


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        # 用堆来做
        piles = [-pile for pile in piles]
        heapify(piles)

        while k > 0:
            heapreplace(piles, piles[0] // 2)
            k -= 1

        return -sum(piles)
