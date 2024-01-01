from typing import List


class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        profit, ansTime = 0, 0
        i, cnt = 0, 0
        n = len(customers)
        # 当前已经在摩天轮上的总人数
        curTotalCnt = 0

        while i < n or cnt > 0:
            if i < n:
                cnt += customers[i]
            # 当前轮能上摩天轮的人数
            curHCnt = 4 if cnt >= 4 else max(cnt, 0)
            cnt -= curHCnt
            curTotalCnt += curHCnt

            i += 1
            tmp = curTotalCnt * boardingCost - i * runningCost
            if tmp > profit:
                profit = tmp
                ansTime = i

        return ansTime if profit > 0 else -1


print(Solution().minOperationsMaxProfit([10, 9, 6], 6, 4))
