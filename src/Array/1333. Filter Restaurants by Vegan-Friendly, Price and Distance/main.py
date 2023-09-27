from typing import List

class Solution:
    @staticmethod
    def filterRestaurants(restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int):
        # 按照 rating 排序
        restaurants.sort(key=lambda x: (-x[1], -x[0]))
        # print(restaurants)
        ret = list()

        for i, restaurant in enumerate(restaurants):
            # 逐个条件验证，全部通过才能加入结果数组
            if veganFriendly == 1 and restaurant[2] != 1:
                continue
            if restaurant[3] > maxPrice:
                continue
            if restaurant[4] > maxDistance:
                continue

            ret.append(restaurant[0])

        return ret

restaurants = [[1, 4, 1, 40, 10], [2, 8, 0, 50, 5], [3, 8, 1, 30, 4], [4, 10, 0, 10, 3], [5, 1, 1, 15, 1]]
veganFriendly = 1
maxPrice = 50
maxDistance = 10

print(Solution.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance))
#Solution.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance)
