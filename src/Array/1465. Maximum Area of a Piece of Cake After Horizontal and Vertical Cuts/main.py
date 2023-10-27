from itertools import pairwise


class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        # 从大到小排序
        horizontalCuts = [0] + sorted(horizontalCuts) + [h]
        verticalCuts = [0] + sorted(verticalCuts) + [w]

        # 逐个区间判断
        maxH = max(b - a for a, b in pairwise(horizontalCuts))
        maxW = max(b - a for a, b in pairwise(verticalCuts))

        return (maxW * maxH) % (10 ** 9 + 7)
