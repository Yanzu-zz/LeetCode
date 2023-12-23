from sortedcontainers import SortedList


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        # 每次都维护一个有序列表
        arr = SortedList(piles)
        while k > 0:
            cur = arr[-1]
            arr.pop()
            arr.add(cur - (cur // 2))
            k -= 1

        return sum(arr)
