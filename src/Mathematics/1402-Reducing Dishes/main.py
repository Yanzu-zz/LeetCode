from itertools import accumulate


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        ans = 0

        satisfaction.sort(reverse=True)
        for s in accumulate(satisfaction):
            if s <= 0:
                break

            # f(i) = f(i-1) + s
            ans += s

        return ans
