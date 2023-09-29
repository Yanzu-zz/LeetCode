from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed.insert(0, 0)
        flowerbed.append(0)

        lenF = len(flowerbed)
        i = 1
        cnt = 0

        # 贪心做法，能种花就在当前位置种花
        while i < lenF - 1:
            # 分类
            cur = flowerbed[i]
            if cur == 1:
                i += 2
            else:  # cur==0
                # 因为初始条件不可能有相邻的两朵花，故只需要判断下一个位置是否有花即可
                if flowerbed[i + 1] == 0:
                    cnt += 1
                    i += 2
                else:
                    i += 1
        return cnt >= n
