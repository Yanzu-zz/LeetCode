from typing import List


class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> \
            List[int]:
        ret = []

        for restaurant in restaurants:
            # 逐个条件验证，全部通过才能加入结果数组
            if veganFriendly > restaurant[2]:
                continue
            if restaurant[3] > maxPrice:
                continue
            if restaurant[4] > maxDistance:
                continue

            ret.append((restaurant[0], restaurant[1]))

        # 然后按照rating排序
        ret.sort(key=lambda x: (-x[1], -x[0]))
        return [r[0] for r in ret]
