import math


class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        if (cost2 > cost1):
            cost1, cost2 = cost2, cost1

        ret = 0
        curV = 0
        # 一个情况一个情况的枚举
        while (curV <= total):
            # ret += math.floor((total - curV) / cost2) + 1
            ret += (total - curV) // cost2 + 1
            curV += cost1

        return ret

if __name__ == "__main__":
    Solution.waysToBuyPensPencils(20, 10, 5)