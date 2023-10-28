from heapq import heapify, heapreplace
from math import floor, sqrt, isqrt


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-g for g in gifts]
        # 建堆
        heapify(gifts)

        # 替换top1
        for i in range(k):
            # heapreplace(gifts, -floor(sqrt((-gifts[0]))))
            # isqrt = floor(sqrt())
            heapreplace(gifts, -isqrt(-gifts[0]))

        return -(sum(gifts))
